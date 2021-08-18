#include "./text.h"

void pad_string(char * text) {
  while (strlen(text) < 32) {
    strcat(text, " ");
  }
}

void draw_line(char * text, char * meta) {
  //For each column in the first segment of all even sections, set row data and illuminate column with desired color.
  delay_ms(10);
  BDC_ADDR = 0b11111111;
  clear_screen();
  for (char segment = 0; segment < 2; segment++) {
    for (char column = 0; column < 5; column++) {
      for (char group = 0; group < 16; group+=2) {
        XBYTE[group << 8] = 0b0000000; //Clear demux data
        clock_demultiplexer(); //L -> H transition on selected demux output pin.

        //Set desired column data for correct column; address selects correct flip-flop which latches to data assigned.
        XBYTE[group << 8] = FONT[((text[(group*2) + segment] - 32) * 5) + column];

        clock_demultiplexer(); //L -> H

        BDC_ADDR = get_column(group, segment, 0, column);
        //delay_ms(100);
      }
    }
  }
  delay_ms(10);
  BDC_ADDR = 0b11111111;
  clear_screen();
  for (char segment = 0; segment < 2; segment++) {
    for (char column = 0; column < 5; column++) {
      for (char group = 1; group < 16; group+=2) {
        XBYTE[group << 8] = 0b0000000;
        clock_demultiplexer(); //L -> H

        //Set desired column data for correct column; address selects correct flip-flop which latches to data assigned.
        XBYTE[group << 8] = FONT[((text[(group*2) + segment] - 32) * 5) + column];

        clock_demultiplexer(); //L -> H

        //Technically BCD bus data, set data bits to illuminate desired column based on map
        BDC_ADDR = get_column(group, segment, 1, column);
        //delay_ms(100);
      }
      //delay_ms(500); //Delay before moving back to even
    }
  }
}

/*void draw_line(char * text, char meta) {
  clear_screen();
  for(char column = 0; column < 5; column++) {
    for(char segment = 0; segment < 2; segment++) {
      for(char group = 0; group < 16; group++) {
        if(!(group % 2)) {
          if((meta & 0b1)){
            XBYTE[group << 8] = ~FONT[((text[(group*2) + segment] - 32) * 5) + column];
          } else {
            XBYTE[group << 8] = FONT[((text[(group*2) + segment] - 32) * 5) + column];
          }
          clock_demultiplexer();
          if(((meta >> 1) & 0b11) == 2) {
            BDC_ADDR = get_column(group, segment, 0, column);
            BDC_ADDR = get_column(group, segment, 1, column);
            } else {
            BDC_ADDR = get_column(group, segment, (meta >> 1) & 0b00000011, column);
          }
        } else {
          XBYTE[group << 8] = 0b0000000;
          clock_demultiplexer();
        }
      }
      delay_ms(1);
      BDC_ADDR = 0b11111111;
      clear_screen();
      for(char group = 0; group < 16; group++) {
        if(!(group % 2)) {
          XBYTE[group << 8] = 0b0000000;
          clock_demultiplexer();
        } else {
          if((meta & 0b1)){
            XBYTE[group << 8] = ~FONT[((text[(group*2) + segment] - 32) * 5) + column];
          } else {
            XBYTE[group << 8] = FONT[((text[(group*2) + segment] - 32) * 5) + column];
          }
          clock_demultiplexer();
          if(((meta >> 1) & 0b11) == 2) {

            BDC_ADDR = get_column(group, segment, 0, column);
            BDC_ADDR = get_column(group, segment, 1, column);
            } else {
            BDC_ADDR = get_column(group, segment, (meta >> 1) & 0b00000011, column);
            }
        }
      }
      delay_ms(1);
      BDC_ADDR = 0b11111111;
      clear_screen();
    }
  }
  }*/
