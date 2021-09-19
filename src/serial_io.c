#include "./serial_io.h"
#include <at89s8253.h>
#include <string.h>

static unsigned char rcnt;
char * serial_buf;

void serial_init() {
  rcnt = 0;

  SCON = 0x50;

  T2CON = 0x30;
  RCAP2H = 0xFF;
  RCAP2L = 0x73;
  TR2 = 1;

  RI = 0;
  TI = 0;
  IE = 0x90;
}

void serial_handler(void) __interrupt 4 {
  if (RI) {
    RI = 0;
    if (SBUF == '\n' || rcnt >= SERIAL_BUF_SIZE - 2) {
      serial_buf[SERIAL_BUF_SIZE - 1] = '\0';
      rcnt = 0;
    } else {
      serial_buf[rcnt] = SBUF;
      rcnt++;
    }
  }
}

void set_output_buf(char * buf) {
  serial_buf = buf;
}

void clear_output_buf() {
  for (char i = 0; i<strlen(serial_buf); i++) {
    serial_buf[i] = ' ';
  }
  serial_buf[0] = '\0';
}
