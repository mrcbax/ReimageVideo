#ifndef COLUMN_H
#define COLUMN_H

static const char GROUP_EVEN[2][2][5] = {
  {//segment 0
    {//red
      0b11110111,0b11110110,0b01001111,0b11110011,0b11110000
    },
    {//green
      0b11110101,0b00111111,0b11110100,0b11110001,0b11110010
    }
  },
  {//segment 1
    {//red
      0b11111001,0b10011111,0b00101111,0b01111111,0b11111000
    },
    {//green
      0b00011111,0b00001111,0b10001111,0b01101111,0b01011111
    }
  }
};

static const char GROUP_ODD[2][2][5] = {
  {//segment 0
    {//red
      0b00101111,0b00001111,0b10011111,0b11111000,0b10001111
    },
    {//green
      0b00011111,0b11110111,0b01101111,0b01111111,0b01011111
    }
  },
  {//segment 1
    {//red
      0b11111001,0b01001111,0b11110110,0b11110000,0b11110011
    },
    {//green
      0b00111111,0b11110101,0b11110001,0b11110100,0b11110010
    }
  }
};

char get_column(char group, char segment, char color, char column);

#endif /* COLUMN_H */
