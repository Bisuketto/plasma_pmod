#ifndef ASCIINTERFACE_H
#define ASCIINTERFACE_H

/*
Include Plasma libs
*/

#define ADDR_ASCII_MODULE /*ASCII module adress */

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
void setHightDepth(int depth);

/*
    Set the pixel depth of the low addr
*/
void setLowDepth(int depth);

/*
    Return the value of the bitmmap's pixel from the addr
*/
int getBitmap(int addr);

/*
    Set the value of the bitmmap's pixel at the addr
*/
int setBitmap(int value, int addr);

/*
    Return the value of the character at the position (x, y)
*/
int getCharac(int x, int y);

/*
    Set the value of the character at the position (x, y)
*/
int setCharac(int x, int y, int value);

/*
    Fill the display with the value
*/
int fillDisplay(int value);

#endif
