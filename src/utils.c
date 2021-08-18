#include "./utils.h"

void clock_demultiplexer(void) {
  DEMULT_CS1 = 0b0;
  DEMULT_CS1 = 0b1;
}

void clear_screen(void) {
  for(char group = 0; group < 16; group++) {
    XBYTE[group << 8] = 0b0000000;
    clock_demultiplexer();
  }
}
