#include "./text.h"

void pad_string(char * text) {
  while (strlen(text) < 32) {
    strcat(text, " ");
  }
}

void draw_line(char * text, char * meta) {
  delay_ms(10); //if we don't sleep here the last column of the previous operation will be dim.
             //BDC0BDC1
  BDC_ADDR = 0b11111111;                                                                              //disable both BDCs to clear them
  clear_screen();                                                                                     //reset all the DFFs to prevent bleed
  for (char segment = 0; segment < 2; segment++) {                                                    //each group is comprised of two segments
    for (char column = 0; column < 5; column++) {                                                     //each segment is comprised of 5 columns
      for (char group = 0; group < 16; group+=2) {                                                    //do the even groups
        //Select the DFF we intend to address   //then advertise the row data for the corresponding column of the font
        XBYTE[group << 8]                     = FONT[((text[(group*2) + segment] - 32) * 5) + column];
        clock_demultiplexer(); //L -> H (rising edge) transition on selected pin latching data from the DFF address bus.
        //Look up the correct color for the column we want, then enable that column
        BDC_ADDR = get_column(group, segment, 0, column);
      }
      XBYTE[group << 8] = 0b0000000;                                                                  //Advertise clear rows on DFF address lines.
      clock_demultiplexer(); //L -> H (rising edge) transition on selected DFF pin latching data from the DFF address bus.
    }
  }
  delay_ms(10); //if we don't sleep here the last column of the previous operation will be dim.
  BDC_ADDR = 0b11111111;                                                                              //disable both BDCs to clear them
  clear_screen();                                                                                     //reset all the DFFs to prevent bleed
  for (char segment = 0; segment < 2; segment++) {                                                    //each group is comprised of two segments
    for (char column = 0; column < 5; column++) {                                                     //each segment is comprised of 5 columns
      for (char group = 1; group < 16; group+=2) {                                                    //do the odd groups
        //Select the DFF we intend to address   //then advertise the row data for the corresponding column of the font
        XBYTE[group << 8]                     = FONT[((text[(group*2) + segment] - 32) * 5) + column];
        clock_demultiplexer(); //L -> H (rising edge) transition on selected DFF pin latching data from the DFF address bus.

        //Look up the correct color for the column we want, then enable that column
        BDC_ADDR = get_column(group, segment, 1, column);
      }
    }
    BDC_ADDR = 0b11111111;
    XBYTE[group << 8] = 0b0000000;                                                                    //Advertise clear rows on DFF address lines.
    clock_demultiplexer(); //L -> H (rising edge) transition on selected DFF latching pin.
  }
}

/* BEGIN OLD ALGORITHM */

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

/* END OLD ALGORITHM */
