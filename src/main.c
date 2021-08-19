#include "./utils.h"
#include "./disp_modes/text.h"
#include "./column.h"

void main(void) {
  CLKREG = 0b1;     // run system at X2 speed
  DEMULT_CS1 = 0b1; //invert demultiplexer so that we can provide a rising edge to the DFFs to trigger latch
  char text[33];
  char meta[33] = {0,0,0,0,1,1,1,1,0,2,2,2,2,2,2,2,0,0,0,0,0,1,1,0,2,2,0,0,1,1,2,2,0}; //color and inversion metadata
  strcpy(text, "I'm Open Source! LOL :P HAHAHAHA");
  pad_string(text); //make sure the string fills the screen
  clear_screen();   //reset all the DFFs to prevent old images from being displayed.
  while(1){
    draw_line(text, meta);
  }
}
