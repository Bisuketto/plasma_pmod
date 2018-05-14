#ifndef ASCIINTERFACE_H
#define ASCIINTERFACE_H

#include "../../shared/plasmaSoPCDesign.h"
#include "../../shared/plasma.h"

#define MemoryRead(A)     (*(volatile unsigned int*)(A))
#define MemoryWrite(A,V) *(volatile unsigned int*)(A)=(V)

#define ADDR_ASCII_MODULE   0x40000600 /*ASCII module adress */
#define RST_ASCII_MODULE    0x40000604 /*ASCII module reset addr */

typedef struct send_ascii {
    unsigned int data_in;
    unsigned int addr;
    unsigned int cont_w;
    unsigned int bit_w;
    unsigned int pixelDepth_L;
    unsigned int pixelDepth_H;
    unsigned int displayOff;
} Send_ASCII;

/*
    Inialize the display
*/
void initDisplay(void);

/*
    Return an int corresponding of the resolution of the screen
    0 : Full resolution
    1 : Half resolution
    2 : Quarter resolution
*/
int getDisplayInformation(void);

/*
    Turn the display on
*/
void startDisplay(void);

/*
    Turn the display off
*/
void stopDisplay(void);

/*
    Set the pixel depth of the hight addr
*/
void setHightDepth(unsigned int depth);

/*
    Set the pixel depth of the low addr
*/
void setLowDepth(unsigned int depth);

/*
    Return the value of the bitmmap's pixel from the addr
*/
int getBitmap(unsigned int addr);

/*
    Set the value of the bitmmap's pixel at the addr
*/
int setBitmap(unsigned int value, unsigned int addr);

/*
    Return the value of the character at the position (x, y)
*/
int getCharac(unsigned int x, unsigned int y);

/*
    Set the value of the character at the position (x, y)
*/
int setCharac(unsigned int x, unsigned int y, unsigned int value);

/*
    Fill the display with the value
*/
int fillDisplay( unsigned int value);

#endif
