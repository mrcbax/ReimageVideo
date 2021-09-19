#include "./utils.h"
#include "./disp_modes/text.h"
//#include "./disp_modes/bar.h"
#include "./display.h"
#include "./column.h"
#include "./serial_io.h"

void main(void) {
  AUXR = 0;
  __idata char serial_output_buf[SERIAL_BUF_SIZE];
  serial_init();
  set_output_buf(serial_output_buf);
  //CLKREG = 0b1;     //run system at X2 speed
  DEMULT_CS1 = 0b1; //invert demultiplexer so that we can provide a rising edge to the DFFs to trigger latch
  __idata unsigned char text[33];
  strcpy(text, "I'm Open Source! LOL :P HAHAHAHA");
  pad_string(text); //make sure the string fills the screen
  clear_screen();   //reset all the DFFs to prevent old images from being displayed.
  float percent = 0;
  while(1){

    if (strlen(serial_output_buf) > 0) {
      empty_string(text);
      strcpy(text, serial_output_buf);
      pad_string(text);
      clear_output_buf();
    }

    __idata fill_properties_t fill;
    fill.color = 0;
    fill.fill_to_col = 160 * percent;
    draw_screen(text, &fill);
  }
}
