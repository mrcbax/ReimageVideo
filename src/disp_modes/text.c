#include "./text.h"

void pad_string(char * text) {
  while (strlen(text) < 32) {
    strcat(text, " ");
  }
}
