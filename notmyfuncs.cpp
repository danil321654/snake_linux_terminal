<<<<<<< HEAD
#include "zm.h"

bool kbhit()
{
termios term;
tcgetattr(0, &term);

termios term2 = term;
term2.c_lflag &= ~ICANON;
tcsetattr(0, TCSANOW, &term2);

int byteswaiting;
ioctl(0, FIONREAD, &byteswaiting);

tcsetattr(0, TCSANOW, &term);

return byteswaiting > 0;
=======
#include"zm.h"
int _kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

int _getch( ) {
  struct termios oldt,
                 newt;
  int            ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
>>>>>>> 0d0005d8b8f5344a54c8ee55941678f35e1a3c0d
}
