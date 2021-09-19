#include "./display_interface.h"

__idata unsigned char display_text[DISPLAY_BUF_SIZE];
__idata fill_properties_t *fill_props;

void print_text(char * text) {
  empty_string(display_text);
  strcpy(display_text, text);
  pad_string(display_text); //make sure the string fills the screen
}
void set_display_properties(__idata fill_properties_t *fill) {
  fill_props = fill;
}
void parse_serial_data(char * serial_data) {
  const char * delim = " ";
  float percent = 0;
  char *str_ptr = strtok(serial_data, delim);
  if(str_ptr != NULL) {
    switch(str_ptr[0]) {
    case 'p': {
      str_ptr = strtok(NULL, delim);
      if (str_ptr != NULL) {
        switch(str_ptr[0]) {
        case 'r': {
          fill_props->color = 0;
          str_ptr = strtok(NULL, delim);
          if(str_ptr != NULL) {
            percent = atof(str_ptr);
          } else {
            print_text("missing percent value");
          }
          break;
        }
        case 'g': {
          fill_props->color = 1;
          str_ptr = strtok(NULL, delim);
          if(str_ptr != NULL) {
            percent = atof(str_ptr);
          } else {
            print_text("missing percent value");
          }
          break;
        }
        case 'y': {
          fill_props->color = 2;
          str_ptr = strtok(NULL, delim);
          if(str_ptr != NULL) {
            percent = atof(str_ptr);
          } else {
            print_text("missing percent value");
          }
          break;
        }
        default: {
          print_text("bad color");
          break;
        }
        }
      } else {
        print_text("missing color value");
      }
      fill_props->fill_to_col = 160 * percent;
      break;
    }
    case 't': {
      empty_string(display_text);
      str_ptr = strtok(NULL, delim);
      if (str_ptr != NULL) {
        switch(str_ptr[0]) {
        case 'r': {
          fill_props->color = 0;
          str_ptr = strtok(NULL, delim);
          if(str_ptr != NULL) {
            while(str_ptr != NULL) {
              strncat(display_text, str_ptr, DISPLAY_BUF_SIZE - 1 - strlen(display_text));
              strncat(display_text, " ", DISPLAY_BUF_SIZE - 1 - strlen(display_text));
              str_ptr = strtok(NULL, delim);
            }
          } else {
            print_text("missing text value");
          }
          break;
        }
        case 'g': {
          fill_props->color = 1;
          str_ptr = strtok(NULL, delim);
          if(str_ptr != NULL) {
            while(str_ptr != NULL) {
              strncat(display_text, str_ptr, DISPLAY_BUF_SIZE - 1 - strlen(display_text));
              strncat(display_text, " ", DISPLAY_BUF_SIZE - 1 -strlen(display_text));
              str_ptr = strtok(NULL, delim);
            }
          } else {
            print_text("missing text value");
          }
          break;
        }
        case 'y': {
          fill_props->color = 2;
          str_ptr = strtok(NULL, delim);
          if(str_ptr != NULL) {
            while(str_ptr != NULL) {
              strncat(display_text, str_ptr, DISPLAY_BUF_SIZE - 1 - strlen(display_text));
              strncat(display_text, " ", DISPLAY_BUF_SIZE - 1 - strlen(display_text));
              str_ptr = strtok(NULL, delim);
            }
          } else {
            print_text("missing text value");
          }
          break;
        }
        default: {
          print_text("bad color");
          break;
        }
        }
      } else {
        print_text("missing color value");
      }
      pad_string(display_text);
      break;
    }
    case 'c': {
      percent = 0;
      fill_props->fill_to_col = 160 * percent;
      print_text("                                ");
      break;
    }
    default: {
      print_text("bad command");
      break;
    }
    }
  }
  //strcpy(text, serial_output_buf);
  clear_output_buf();
}
void draw_display() {
  draw_screen(display_text, fill_props);
}
