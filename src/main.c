#include "./utils.h"
#include "./disp_modes/text.h"
//#include "./disp_modes/bar.h"
#include "./display.h"
#include "./column.h"

void main(void) {
  CLKREG = 0b1;     // run system at X2 speed
  DEMULT_CS1 = 0b1; //invert demultiplexer so that we can provide a rising edge to the DFFs to trigger latch
  __idata char text[33];
  strcpy(text, "I'm Open Source! LOL :P HAHAHAHA");
  pad_string(text); //make sure the string fills the screen
  clear_screen();   //reset all the DFFs to prevent old images from being displayed.
  char ct = 0;
  float percent = .01;
  while(1){
    __idata fill_properties_t fill;
    fill.color = 1;
    fill.fill_to_col = 160 * percent;
    draw_screen(text, &fill);
    if (ct == 5) {
      if (percent < 1) {
        percent += 0.01;
      } else {
        percent = 0.01;
      }
      ct = 0;
    }
    ct++;

  }
}
