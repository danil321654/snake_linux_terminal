
#include "zm.h"
void game()
{

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
        zmei.emplace(zmei.begin(),k);
        k= zmei[zmei.size()-1];
        zmei.erase(zmei.begin()+zmei.size()-1);
        for (int i=1;i<zmei.size();i++) if(zmei[0]==zmei[i])return;
        shwfield(&fp,&k,&zmei);
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
     field[*foodpos]='+';
     for (int i=0;i<720;i++)
    {
        if(field[i]!='0' && field[i]!='+') field[i]=' ';
        if (i>0 && i%40==0) std::cout<<'|';
        if (i>0 && i%40==0) std::cout<<std::endl;
        if (i%40==0) std::cout<<'|';
        std::cout<<field[i];
    }
     std::cout<<'|'<<std::endl<<" ";
    for (int i=0;i<40;i++) std::cout<<"‾";
    std::cout<<std::endl;

}
