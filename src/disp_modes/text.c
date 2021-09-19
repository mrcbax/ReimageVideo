#include "./text.h"

void pad_string(char * text) {
  while (strlen(text) < 32) {
    strcat(text, " ");
  }
}

void empty_string(char * text) {
  for (char i = 0; i<strlen(text); i++) {
    text[i] = '\0';
  }
}