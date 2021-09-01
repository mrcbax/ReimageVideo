#ifndef DISPLAY_H
#define DISPLAY_H
#include "./column.h"
#include "./utils.h"

void draw_screen(char * cols, char * cols_meta);
void draw_group(char group_start, char * cols, char * cols_meta);

#endif /* DISPLAY_H */
