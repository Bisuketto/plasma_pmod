#include "../Includes/ASCIInterface.h"

Send_ASCII send;

void sendData(void)
{
    MemoryWrite(ADDR_ASCII_MODULE,
        (send.displayOff << 30) | (send.pixelDepth_H << 28) |
        (send.pixelDepth_L << 26) | (send.bit_w << 25) |
        (send.cont_w << 24) | (send.addr << 9) |
        send.data_in);
}

void initDisplay(void)
{
        send.data_in = 0;
        send.addr = 0;
        send.cont_w = 0;
        send.bit_w = 0;
        send.pixelDepth_L = 0;
        send.pixelDepth_H = 0;
        send.displayOff = 1;

        MemoryWrite(RST_ASCII_MODULE, 1);
}

int getDisplayInformation(void)
{
    return 0;
}

void startDisplay(void)
{
    send.displayOff = 0;
    sendData();
}

void stopDisplay(void)
{
    send.displayOff = 1;
    sendData();
}

void setHightDepth(unsigned int depth)
{
    send.pixelDepth_H = depth;
    sendData();
}

void setLowDepth(unsigned int depth)
{
    send.pixelDepth_L = depth;
    sendData();
}

int getBitmap(unsigned int addr)
{
    send.addr = addr;
    sendData();
    return MemoryRead(ADDR_ASCII_MODULE) >> 9;
}

int setBitmap(unsigned int value, unsigned int addr)
{
    send.addr = addr;
    send.data_in = value;
    sendData();

    return 0;
}

int getCharac(unsigned int x, unsigned int y)
{
    send.addr = y*180 + x;
    sendData();
    return MemoryRead(ADDR_ASCII_MODULE) & 0x1FF;
}

int setCharac(unsigned int x, unsigned int y, unsigned int value)
{
    send.addr = y*180 + x;
    send.data_in = value;
    sendData();

    return 0;
}

int fillDisplay(unsigned int value)
{
    int size = 180*128;
    send.addr = 0;
    for (int i = 0; i<size; i++)
    {
        sendData();
        send.addr++;
    }
    send.addr = 0;

    return 0;
}
