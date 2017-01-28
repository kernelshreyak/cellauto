//1 dimensional elementary cellular automata based on binary rules
// Author: Shreyak Chakraborty (C) 2017
//License: GNU GPLv3

# include <iostream>
# include <graphics.h>
# include <conio.h>

using namespace std;

int rule[]={0,1,0,1,1,0,1,0};  //rule 90
//int rule[]={0,0,0,1,1,1,1,0};  //rule 30
//int rule[]={0,1,0,1,1,0,0,1};

struct cell
{
    void draw(int,int);
    int life;
};

void cell::draw(int x,int y)
{
    int cl;

    if(life==0)
        cl=RED;
    if(life==1)
        cl=YELLOW;
    if(life==2)
        cl=YELLOW;
    if(life==3)
        cl=BLUE;
    putpixel(x,y,cl);
}

int rules(int a,int b,int c)
{
    if(a==0 && b==0 && c==0)
        return rule[7];
    else if(a==0 && b==0 && c==1)
        return rule[6];
    else if(a==0 && b==1 && c==0)
        return rule[5];
    else if(a==0 && b==1 && c==1)
        return rule[4];
    else if(a==1 && b==0 && c==0)
        return rule[3];
    else if(a==1 && b==0 && c==1)
        return rule[2];
    else if(a==1 && b==1 && c==0)
        return rule[1];
    else if(a==1&&b==1&&c==1)
        return rule[0];
}

int main()
{
    int i,k,x,y,population=500,gen=0,G=500;

    cell cells_old[population],cells[population];

    initwindow(1024,768,"Cellular Automata");

    cout<<rules(0,0,1);

    for(i=0;i<=population+1;i++)
    {
        cells[i].life=0;
    }

    //initial values:
    cells[population/2].life=1;

    y=2;


    while(gen<=G)
    {
        for(k=0;k<population;k++)
            cells_old[k].life=cells[k].life;

        x=4;

        //the rules for evolution
        for(i=1;i<=population-1;i++)
        {
            cells[i].life=rules(cells_old[i-1].life,cells_old[i].life,cells_old[i+1].life);
            //cout<<cells[i].life<<" ";

        }
        //cout<<endl;

        cells[0].life=cells[population-1].life;
        cells[population+1].life=cells[1].life;

        for(k=0;k<population;k++,x+=2)
            cells[k].draw(x,y);

        y+=2;

        gen=gen+1;
    }

    cout<<"\n\nTerminated after generation=\t"<<gen-1;

    getch();
    closegraph();
}
