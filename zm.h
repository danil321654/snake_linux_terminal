#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <stropts.h>
#include <unistd.h>
int _getch();
int _kbhit();
void game();
void shwfield(int*,int*,std::vector<int>*);
