#include "./display.h"

void draw_screen(char * text, fill_properties_t * screen_fill) {
  draw_group(0, text, screen_fill);
  draw_group(1, text, screen_fill);
}

void draw_group(char group_start, char * text, fill_properties_t * screen_fill) {
  clear_screen();
  for (char segment = 0; segment < 2; segment++) {                                                    //each group is comprised of two segments
    for (char column = 0; column < 5; column++) {                                                     //each segment is comprised of 5 columns
      for (char group = group_start; group < 16; group+=2) { //clock the row data into the groups
        char seg_index = (group << 1) + segment;
        if(!(screen_fill->fill_to_col <= (seg_index * 5) + column)){
          XBYTE[group << 8]                     = ~FONT[((text[seg_index] - 32) * 5) + column];
        } else {
          //Select the DFF we intend to address   //then advertise the row data for the corresponding column
          XBYTE[group << 8]                     = FONT[((text[seg_index] - 32) * 5) + column];
        }
        clock_demultiplexer(); //L -> H (rising edge) transition on selected pin latching data from the DFF address bus
      }
      for (char group = group_start; group < 16; group+=2) { //iluminate the groups
        if (screen_fill -> color == 2) {
          BDC_ADDR = get_column(group, segment, 0, column);
          delay_nop(5);
          BDC_ADDR = get_column(group, segment, 1, column);
          delay_nop(40);
        } else {
          //Look up the correct color for the column we want, then enable that column
          BDC_ADDR = get_column(group, segment, screen_fill -> color, column);
          delay_nop(45); //delay before disabling the column (brightness)
        }

        //delay_ms(500); //<<<<USE THIS DELAY FOR TESTING
        BDC_ADDR = 0b11111111; //turn off all columns
      }
      //delay_ms(2000);  //<<<<USE THIS DELAY FOR TESTING
    }
  }
}
