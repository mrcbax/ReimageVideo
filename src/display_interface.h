#ifndef DISPLAY_INTERFACE_H
#define DISPLAY_INTERFACE_H

#define DISPLAY_BUF_SIZE 33

#include "./display.h"
#include "./serial_io.h"
#include "./disp_modes/text.h"
#include <string.h>

void print_text(char * text);
void set_display_properties(__idata fill_properties_t *fill);
void parse_serial_data(char * serial_data);
void draw_display();


#endif
