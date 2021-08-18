#include "./column.h"
char get_column(char group, char segment, char color, char column) {
  if(!(group % 2)) {
    return GROUP_EVEN[segment][color][column];
  } else {
    return GROUP_ODD[segment][color][column];
  }
}
