#include "zm.h"
void game()
{
srand(static_cast<unsigned int>(time(0)));
    initscr();
    use_legacy_coding(2);
    curs_set(0);
    keypad(stdscr, true); 
    int fp=rand()%720;
    std::vector<int> zmei{rand()%720};
    zmei.reserve(100);
    shwfield(&fp,&zmei[zmei.size()-1],&zmei);
    int c;int newpos=0,k,lastpos=0;
    int t =500000;
    while (1)
    {
        usleep(t);
        if(kbhit()){
            c=getch();
				switch(c){
			   case 259: {if(zmei.size()==1 ||newpos!=40) newpos=-40;break;}
			   case 261: {if(zmei.size()==1 ||newpos!=-1)	newpos=1;	break;}
			   case 260: {if(zmei.size()==1 ||newpos!=1)	newpos=-1;	break;}
			   case 258: {if(zmei.size()==1 ||newpos!=-40)newpos=40; break;}
					 } }
        lastpos=zmei.back();
         if((zmei[0]-39)%40==0&&newpos==1) return;
         else if (zmei[0]%40==0&&newpos==-1) return;
         else  k=zmei[0]+newpos;
         if(k<0||k>719)return;
        zmei.emplace(zmei.begin(),k);
        k= zmei[zmei.size()-1];
        zmei.erase(zmei.begin()+zmei.size()-1);
        for (int i=1;i<zmei.size();i++) if(zmei[0]==zmei[i])return;
        shwfield(&fp,&k,&zmei);
        refresh();
        k=0;
	if(t>100000) t=500000-zmei.size()*10000;
    }
	endwin();
}
void shwfield(int* foodpos,int* lastpos, std::vector<int>* zmei)
{   
	clear();
printw(" ");
refresh();
     for (int i=0;i<40;i++) {addch(115| A_ALTCHARSET);;refresh();}
     printw(" \n");
refresh();
     char field [720]{0};
     if(*foodpos==(*zmei)[0]){zmei->push_back(*lastpos);*foodpos=rand()%720;}
     for (int i=0;i<zmei->size();i++) field[(*zmei)[i]]='0';
     field[*foodpos]='+';
     for (int i=0;i<720;i++)
    {
        if(field[i]!='0' && field[i]!='+') field[i]=' ';
        if (i>0 && i%40==0){addch(120 | A_ALTCHARSET);printw("\n");}
        if (i%40==0) addch(120 | A_ALTCHARSET);
        printw("%c",field[i]);
        refresh();
    }
addch(120 | A_ALTCHARSET);
    printw("\n ");
refresh();
for (int i=0;i<40;i++) {addch(111 | A_ALTCHARSET);refresh();}
    printw(" \n%d",zmei->size(),"\n");
    refresh();

    
}
