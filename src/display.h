#ifndef DISPLAY_H
#define DISPLAY_H
#include "./column.h"
#include "./utils.h"
#include "./disp_modes/font.h"

typedef struct {
  char fill_to_col;
  char color;
} fill_properties_t;

void draw_screen(char * text, fill_properties_t * screen_fill);
void draw_group(char group_start, char * text, fill_properties_t * screen_fill);

#endif /* DISPLAY_H */
