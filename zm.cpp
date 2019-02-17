
#include "zm.h"
void game()
{
<<<<<<< HEAD
    initscr();

    curs_set(0);
    keypad(stdscr, true); 
    int fp=72;
    std::vector<int> zmei{srand(time())};
    zmei.reserve(100);
    shwfield(&fp,&zmei[zmei.size()-1],&zmei);
    int c;int newpos=0,k,lastpos=0;
    while (1)
    {
        usleep(200000);
        if(kbhit()){
            c=getch();

            if(c==259){ if(zmei.size()==1 ||newpos!=40)newpos=-40;}
            else if(c==261) {if(zmei.size()==1 ||newpos!=-1)newpos=1;}
            else if(c==260) {if(zmei.size()==1 ||newpos!=1)newpos=-1;}
            else if(c==258) {if(zmei.size()==1 ||newpos!=-40)newpos=40;}
                    }
        lastpos=zmei.back();
         if((zmei[0]-39)%40==0&&newpos==1) return;
         else if (zmei[0]%40==0&&newpos==-1) return;
         else  k=zmei[0]+newpos;
         if(k<0||k>719)return;
=======

    int fp=72;
    std::vector<int> zmei;
    zmei.push_back(324);
    shwfield(&fp,&zmei[zmei.size()-1],&zmei);
    int c=0,newpos=0,k;
    int lastpos=0;
    while (c!=13)
    {
        sleep(1);
        if(_kbhit()){
            c=_getch();
            if(c==56){ if(zmei.size()==1 ||newpos!=40)newpos=-40;}
            else if(c==54) {if(zmei.size()==1 ||newpos!=-1)newpos=1;}
            else if(c==52) {if(zmei.size()==1 ||newpos!=1)newpos=-1;}
            else if(c==50) {if(zmei.size()==1 ||newpos!=-40)newpos=40;}
                    }
        lastpos=zmei.back();
        if((zmei[0]%39==0&&newpos==1)||(zmei[0]%40==0&&newpos==-1)) return;
        else k=zmei[0]+newpos;
        if(k<0|k>719)return;
>>>>>>> 0d0005d8b8f5344a54c8ee55941678f35e1a3c0d
        zmei.emplace(zmei.begin(),k);
        k= zmei[zmei.size()-1];
        zmei.erase(zmei.begin()+zmei.size()-1);
        for (int i=1;i<zmei.size();i++) if(zmei[0]==zmei[i])return;
        shwfield(&fp,&k,&zmei);
<<<<<<< HEAD
        refresh();
        k=0;
    }
	endwin();
}
void shwfield(int* foodpos,int* lastpos, std::vector<int>* zmei)
{   
	clear();
printw(" ");
refresh();
     for (int i=0;i<40;i++) {printw("1");refresh();}
     printw(" \n");
refresh();
     char field [720]{0};
     if(*foodpos==(*zmei)[0]){zmei->push_back(*lastpos);*foodpos=rand()%720;}
     for (int i=0;i<zmei->size();i++) field[(*zmei)[i]]='O';
=======
        k=0;
    }

}
void shwfield(int* foodpos,int* lastpos, std::vector<int>* zmei)
{   system("clear");
    std::cout<<' ';
     for (int i=0;i<40;i++) std::cout<<'_';
     std::cout<<' '<<std::endl;
     char field [720]{0};
     if(*foodpos==(*zmei)[0]){(*zmei).push_back(*lastpos);*foodpos=rand()%720;}
     for (int i=0;i<(*zmei).size();i++) field[(*zmei)[i]]='0';
>>>>>>> 0d0005d8b8f5344a54c8ee55941678f35e1a3c0d
     field[*foodpos]='+';
     for (int i=0;i<720;i++)
    {
        if(field[i]!='0' && field[i]!='+') field[i]=' ';
<<<<<<< HEAD
        if (i>0 && i%40==0) printw("1");
        if (i>0 && i%40==0) printw("\n");
        if (i%40==0) printw("1");
        printw("%c",field[i]);
        refresh();
    }
    printw("1\n ");
refresh();
    for (int i=0;i<40;i++) {printw("1");refresh();}
    printw("\n%d",zmei->size(),"\n");
    refresh();

    
=======
        if (i>0 && i%40==0) std::cout<<'|';
        if (i>0 && i%40==0) std::cout<<std::endl;
        if (i%40==0) std::cout<<'|';
        std::cout<<field[i];
    }
     std::cout<<'|'<<std::endl<<" ";
    for (int i=0;i<40;i++) std::cout<<"‾";
    std::cout<<std::endl;

>>>>>>> 0d0005d8b8f5344a54c8ee55941678f35e1a3c0d
}
