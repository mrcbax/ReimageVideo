#include "./utils.h"
#include "./disp_modes/text.h"
#include "./display_interface.h"
#include "./column.h"
#include "./serial_io.h"

void main(void) {
  __idata char serial_output_buf[SERIAL_BUF_SIZE];
  serial_init();
  set_output_buf(serial_output_buf);

  CLKREG = 0b1;     //run system at X2 speed
  DEMULT_CS1 = 0b1; //invert demultiplexer so that we can provide a rising edge to the DFFs to trigger latch

  print_text("I'm Open Source! LOL :P HAHAHAHA");
  clear_screen();   //reset all the DFFs to prevent old images from being displayed.

  float percent = 0;
  __idata fill_properties_t fill;
  fill.color = 0;
  fill.fill_to_col = 160 * percent;
  set_display_properties(&fill);
  while(1){
    if (serial_data_received()) {
      parse_serial_data(serial_output_buf);
    }
    draw_display();
  }
}
