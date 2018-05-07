#include "../../shared/plasmaSoPCDesign.h"
#include "../../shared/plasma.h"

#include "../Includes/ASCIInterface.h"

int kbhit(void);
int getch(void);

int kbhit(void)
{
    return MemoryRead(IRQ_STATUS) & IRQ_UART_READ_AVAILABLE;
}

int getch(void)
{
    while(!kbhit()) ;
    return MemoryRead(UART_READ);
}

int main()
{
    char data;
    int xmax = 160;
    int ymax = 128;
    int x = 0;
    int y = 0;

    int dispinfo = getDisplayInformation();
    if (dispinfo)
    {
        x = x/dispinfo;
        y = y/dispinfo;
    }

    initDisplay();
    startDisplay();

    while(1)
    {
        data = getch();

        setCharac(x, y, (int)data);

        x++;
        if (x == xmax)
        {
            x = 0;
            y++;
        }

        if (y == ymax)
        {
            y = 0;
            fillDisplay(0);
        }
    }
}
