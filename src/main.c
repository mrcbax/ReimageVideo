#include "./utils.h"
#include "./disp_modes/text.h"
#include "./column.h"

void main(void) {
  CLKREG = 0b1;
  DEMULT_CS1 = 0b1;
  char text[33];
  char meta[32] = {0,1,1,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,0,1,1,0,1};
  strcpy(text, "I'm Open Source! LOL :P HAHAHAHA");
  pad_string(text);
  while(1){

    draw_line(text, meta);
    /*
    for(char i = 0; i < 2; i++) {
      if(i) {
        draw_line(text, 0b00000000);
      } else {
        draw_line(text, 0b00000011);
      }
      }*/
  }
}
  /*for(char group = 0; group < 16; group++ ){
    for (char segment = 0; segment < 2; segment++){
    BDC_ADDR = 0b11111111;
    for(char column = 0; column < 5; column++) {
    for(char i = 0; i < 16; i++) {
    if (!(group % 2)) {
    if(!(i %2)) {
    XBYTE[i << 8] = column;
    } else {
    XBYTE[i << 8] = 0b0000000;
    }
    } else {
    if((i %2)) {
    XBYTE[i << 8] = column;
    } else {
    XBYTE[i << 8] = 0b0000000;
    }
    }
    }
    XBYTE[group << 8] = column;
    clock_demultiplexer();
    BDC_ADDR = get_column(group, segment, segment % 2, column);
    delay_ms(1);
    XBYTE[group << 8] = 0b0000000;
    clock_demultiplexer();
    }
    }
    }*/

/*for(char group = 0; group < 16; group ++) {
  for(char segment = 0; segment < 2; segment++) {
  for(char column = 0; column < 5; column++) {
  XBYTE[group << 8] = 0b0111110;
  clock_demultiplexer();
  BDC_ADDR = get_column(group, segment, 0, column);
  delay_ms(500);
  BDC_ADDR = 0b11111111;
  XBYTE[group << 8] = 0b0000000;
  clock_demultiplexer();
  }
  }
  }*/
