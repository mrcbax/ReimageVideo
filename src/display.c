#include "./display.h"

void draw_screen(char * cols, char * cols_meta) {
  draw_group(0, cols, cols_meta);
  draw_group(1, cols, cols_meta);
}

void draw_group(char group_start, char * cols, char * cols_meta) {
  clear_screen();
  for (char color = 0; color < 2; color++) {                                                            //scan per color
    for (char segment = 0; segment < 2; segment++) {                                                    //each group is comprised of two segments
      for (char column = 0; column < 5; column++) {                                                     //each segment is comprised of 5 columns
        for (char group = group_start; group < 16; group+=2) { //clock the row data into the even groups
          char col_meta = cols_meta[(((group * 2) + segment) * 5) + column];
          char col_data = cols[(((group * 2) + segment) * 5) + column];
          char col_color = col_meta & 0b0000011;                                       //lookup the correct metadata for the segment
          if (color == col_color || col_color == 2) { //determine which groups to enable based on color
            if((col_meta >> 2) & 0b00000001){
              XBYTE[group << 8]                     = ~col_data;
            } else {
              //Select the DFF we intend to address   //then advertise the row data for the corresponding column of the font
              XBYTE[group << 8]                     = col_data;
            }
          } else {
            XBYTE[group << 8] = 0b0000000;
          }
          clock_demultiplexer(); //L -> H (rising edge) transition on selected pin latching data from the DFF address bus
        }
        for (char group = group_start; group < 16; group+=2) {                                                    //iluminate the even groups
          //Look up the correct color for the column we want, then enable that column
          BDC_ADDR = get_column(group, segment, color, column);
          //delay_ms(500); //<<<<USE THIS DELAY FOR TESTING
          delay_nop(40);                                                                                //delay before disabling the column (brightness)
          BDC_ADDR = 0b11111111;                                                                        //turn off all columns
        }
        //delay_ms(2000);  //<<<<USE THIS DELAY FOR TESTING
      }
    }
  }
}
