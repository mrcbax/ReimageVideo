#include "./text.h"

void pad_string(char * text) {
  while (strlen(text) < 32) {
    strcat(text, " ");
  }
}

void generate_line (char * text, char * meta) {
  char cols[160];
  char cols_meta[160];
  int ct = 0;
  for (int character = 0; character < 32; character++) {
    for (int column = 0; column < 5; column++) {
      cols[ct] = FONT[((text[character] - 32) * 5) + column];
      cols_meta[ct] = meta[character];
      ct++;
    }
  }
  draw_screen(cols, cols_meta);
}
