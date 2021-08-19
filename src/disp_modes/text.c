#include "./text.h"

void pad_string(char * text) {
  while (strlen(text) < 32) {
    strcat(text, " ");
  }
}

void draw_line(char * text, char * meta) {
  clear_screen();                                                                                     //reset all the DFFs to prevent bleed
  for (char segment = 0; segment < 2; segment++) {                                                    //each group is comprised of two segments
    for (char column = 0; column < 5; column++) {                                                     //each segment is comprised of 5 columns
      for (char group = 0; group < 16; group+=2) {                                                    //clock the row data into the even groups
        //Select the DFF we intend to address   //then advertise the row data for the corresponding column of the font
        XBYTE[group << 8]                     = FONT[((text[(group*2) + segment] - 32) * 5) + column];
        clock_demultiplexer(); //L -> H (rising edge) transition on selected pin latching data from the DFF address bus
        //Look up the correct color for the column we want, then enable that column
      }
      for (char group = 0; group < 16; group+=2) {                                                    //iluminate the even groups
        //Look up the correct color for the column we want, then enable that column
        BDC_ADDR = get_column(group, segment, meta[(group*2) + segment], column);
        delay_100ns(10);                                                                              //delay before disabling the column (brightness)
        BDC_ADDR = 0b11111111;                                                                        //turn off all columns
      }
      //delay_ms(2000);  //<<<<USE THIS DELAY FOR TESTING
    }
  }
  clear_screen();                                                                                     //reset all the DFFs to prevent bleed
  for (char segment = 0; segment < 2; segment++) {                                                    //each group is comprised of two segments
    for (char column = 0; column < 5; column++) {                                                     //each segment is comprised of 5 columns
      for (char group = 1; group < 16; group+=2) {                                                    //clock the row data into the odd groups
        //Select the DFF we intend to address   //then advertise the row data for the corresponding column of the font
        XBYTE[group << 8]                     = FONT[((text[(group*2) + segment] - 32) * 5) + column];
        clock_demultiplexer(); //L -> H (rising edge) transition on selected DFF pin latching data from the DFF address bus
      }
      for (char group = 1; group < 16; group+=2){                                                     //iluminate the odd groups
        //Look up the correct color for the column we want, then enable that column
        BDC_ADDR = get_column(group, segment, meta[(group*2) + segment], column);
        delay_100ns(10);                                                                              //delay before disabling the column (brightness)
        BDC_ADDR = 0b11111111;                                                                        //turn off all columns
      }
      //delay_ms(2000); //<<<<USE THIS DELAY FOR TESTING
    }
  }
}
