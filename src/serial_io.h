#ifndef SERIAL_IO_H
#define SERIAL_IO_H

#define SERIAL_BUF_SIZE 38

void serial_init();
void serial_handler(void) __interrupt 4;
void set_output_buf(char * buf);
void clear_output_buf();
char serial_data_received();

#endif
