#include "./utils.h"
#include "./disp_modes/text.h"
#include "./column.h"

void main(void) {
  CLKREG = 0b1; // run system at X2 speed
  DEMULT_CS1 = 0b1; //invert demultiplexer so that we can provide a rising edge to the DFFs to trigger latch
  char text[33];
  char meta[33] = {0,1,1,1,0,0,1,1,1,0,1,1,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,0,1,1,0,1,0}; //color and inversion metadata
  strcpy(text, "I'm Open Source! LOL :P HAHAHAHA");
  pad_string(text); //make sure the string fills the screen
  while(1){

    draw_line(text, meta);

    /* BEGIN TESTING CODE FOR OLD ALGORITHM */
    /*for(char i = 0; i < 2; i++) {
      if(i) {
        draw_line(text, 0b00000000);
      } else {
        draw_line(text, 0b00000011);
      }
      }*/
    /* END TESTING CODE FOR OLD ALGORITHM */
  }
}
