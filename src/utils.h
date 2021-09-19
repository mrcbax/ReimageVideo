#ifndef UTILS_H
#define UTILS_H
#include <at89s8253.h>
#include <lint.h>
#include <stdlib.h>
#include <sdcc-lib.h>
#include <compiler.h>
#include <string.h>

#include "../lib/absacc.h"
#include "./delay.h"

//Demultiplexer Pins
#define DEMULT_A0   P2_0
#define DEMULT_A1   P2_1
#define DEMULT_A2   P2_2
#define DEMULT_A3   P2_3
#define DEMULT_CS1  P3_6
#define DEMULT_CS2  P2_4
#define DEMULT_ADDR P2

//BDC1 Pins
#define BDC1_A0 P1_0
#define BDC1_A1 P1_1
#define BDC1_A2 P1_2
#define BDC1_A3 P1_3

//BDC2 Pins
#define BDC2_A0 P1_4
#define BDC2_A1 P1_5
#define BDC2_A2 P1_6
#define BDC2_A3 P1_7

//BDC Array Control
#define BDC_ADDR P1
/*
 *BDC0 1111XXXX                BDC1 XXXX1111       G0,G2,G4,G6,G8,G10,G12,G14,G16
 *Number  0 1 2 3 4 5 6 7 8 9  0 1 2 3 4 5 6 7 8 9
 *Segment 0 0 0 0 0 0 0 0 1 1  1 1 1 0 0 1 1 1 1 1
 *Column  4 3 4 3 2 0 1 0 4 0  1 0 2 1 2 4 3 3 2 1
 *Color   R G G R G G R R R R  G G R G R G G R G R
 *BDC0 1111XXXX                BDC1 XXXX1111       G1,G3,G5,G7,G9,G11,G13,G15
 *Number  0 1 2 3 4 5 6 7 8 9  0 1 2 3 4 5 6 7 8 9
 *Segment 1 1 1 1 1 1 1 0 0 1  0 0 0 1 1 0 0 0 0 0
 *Column  3 2 4 4 3 1 2 1 3 0  1 0 0 0 1 4 2 3 4 2
 *Color   R G G R G G R G R R  R G R G R G G G R R

 *0   1   2   3   4
 *S0G: 0:5,1:3,0:4,0:1,0:2
 *S0R: 0:7,0:6,1:4,0:3,0:0
 *S1G: 1:1,1:0,1:8,1:6,1:5
 *S1R: 0:9,1:3,1:2,1:7,0:8

 *0   1   2   3   4   5   6   7   8   9
 *G: 0:5,1:3,0:4,0:1,0:2,1:1,1:0,1:8,1:6,1:5
 *R: 0:7,0:6,1:4,0:3,0:0,0:9,1:3,1:2,1:7,0:8

 *0,1,2,3,4,5,6,7,8,9 : 15,31,47,63,79,95,127,143,159
 */


//PROM Pins
#define PROM_SO  P3_1
#define PROM_SCK P3_2
#define PROM_SI  P3_3
#define PROM_CS_ P3_4

//Connector J3
#define J3_P1 P0_6
#define J3_P2 P0_5
#define J3_P3 P0_4
#define J3_P4 P0_3
#define J3_P5 P0_2
#define J3_P6 P0_1
#define J3_P7 P0_0

//D Flip-Flop Bus
#define DFF_BUS2 J3_P7
#define DFF_BUS3 J3_P6
#define DFF_BUS4 J3_P5
#define DFF_BUS5 J3_P1
#define DFF_BUS6 J3_P2
#define DFF_BUS7 J3_P3
#define DFF_BUS8 J3_P4
#define DFF_BUS  P0

void clock_demultiplexer(void);
void clear_screen(void);

#endif /* UTILS_H */
