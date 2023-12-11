#ifndef GETCH_H
#define GETCH_H

#include <unistd.h>
#include <termios.h>

int getch_echo(bool echo=true)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~ICANON;
    if(echo)
	newt.c_lflag &=  ECHO;
    else
	newt.c_lflag &= ~ECHO;
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
      
int getch()
{
    getch_echo(false);
}

int wherexy(int&x,int&y)
{
    printf("\033[6n");
    if(getch() != '\x1B') return 0;
    if(getch() != '\x5B') return 0;
    int in;
    int ly = 0;
    while((in = getch()) != ';')
        ly = ly * 10 + in - '0';	
    int lx = 0;
    while((in = getch()) != 'R')
        lx = lx * 10 + in - '0';
    x = lx;
    y = ly;
}

int wherex()
{
    int x=0,y=0;
    wherexy(x,y);
    return x;
}
      
int wherey()
{
    int x=0,y=0;
    wherexy(x,y);
    return y;
}

#endif
