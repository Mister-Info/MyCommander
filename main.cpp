#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include<cstring>
#include<windows.h>
#include <graphics.h>
#include <winbgim.h>


using namespace std;

void indexare_foldere_fisiere(char p[], WIN32_FIND_DATA cautare, char foldere[101][257], char fisiere[101][257], int &nr_foldere, int &nr_fisiere)///functia asta gaseste folderele si fisierele
{



    nr_fisiere=nr_foldere=0;

    HANDLE director=FindFirstFile(p,&cautare);

    while(FindNextFile(director, &cautare))
    {

        if(cautare.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
        {
            strcpy(foldere[nr_foldere++],cautare.cFileName);
        }
        else
        {
            strcpy(fisiere[nr_fisiere++],cautare.cFileName);
        }

    }
}


void refresh()
{
    return ;
}

void update()
{
    return ;
}

void Change()///cand apesi TAB, schimbi fereastra
{
    return ;
}




bool verif=false;
void Up_Arrow_stanga()///alegerea precedenta
{
    if (GetKeyState(VK_UP) & 0x8000)
    {
        if(!verif)
        {
            verif=true;
            cout<<"da";
        }
    }
    else
    {

        verif=false;
    }


}

void Down_Arrow_stanga()///alegerea ulterioara
{
    if (GetKeyState(VK_DOWN) & 0x8000)
    {
        if(!verif)
        {
            verif=true;
            cout<<"da";
        }
    }
    else
    {

        verif=false;
    }
}


void Fixed_Option()///fisierul/folderul selectat
{
    return ;
}


void cautare_stanga_start()
{
    char foldere[101][257], fisiere[101][257], discuri_locale[101][257];///le voi optimiza mai tarziu
    int nr_foldere, nr_fisiere;

    WIN32_FIND_DATA cautare;///pentru cautare
    char p[255];
    int nrdisc=0;

    for(char c='A'; c<='Z'; c++)
    {
        char disk[1];
        disk[0]=c;
        disk[1]=NULL;
        strcpy(p,disk);
        strcat(p,":");///pentru viitoarele local discuri
        strcat(p,"\\*");
        nr_foldere=nr_fisiere=0;


        HANDLE director=FindFirstFile(p,&cautare);///directorul explicit

        if(director!=INVALID_HANDLE_VALUE)///practic daca directorul ala nu are nimic
        {
            char pcopie[1];
            pcopie[0]=p[0];
            pcopie[1]=NULL;
            strcat(discuri_locale[nrdisc]," Local disk: ");///11
            strcat(discuri_locale[nrdisc++],pcopie);
            strcat(discuri_locale[nrdisc-1], " ");

        }



        int x=15;
        int y=110;

        for(int i=0; i<nrdisc; i++)
        {
            if(i==0)
            {
                setcolor(BLACK);
                setbkcolor(COLOR(149, 159, 255));
                outtextxy(x,y,discuri_locale[i]);
                y+=20;
            }
            else
            {
                setcolor(BLACK);
                setbkcolor(WHITE);
                outtextxy(x,y,discuri_locale[i]);
                y+=20;
            }
        }


        for (int i=0; i<nrdisc; i++)
            indexare_foldere_fisiere(p, cautare,  foldere, fisiere, nr_foldere, nr_fisiere);

        FindClose(director);

    }
}

void HUD()
{
    ///Partea de design a aplicatiei (interfata)
    setbkcolor(COLOR(220, 220, 220));
    cleardevice();
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, WHITE);
    bar3d(10, 80,  497, 688, 0, 0);
    bar3d(537, 80, 1014, 688, 0, 0);
    setcolor(DARKGRAY);
    line(0, 728, 1024, 728);
    line(0, 70, 1024, 70);
    setfillstyle(SOLID_FILL, COLOR(94, 53, 248));
    bar(0, 0, 1024, 30);
    ///Titlul Aplicatiei
    setcolor(COLOR(255, 0, 0));
    setbkcolor(COLOR(94, 53, 248));
    outtextxy(10, 10, "<");
    setcolor(WHITE);
    outtextxy(20, 10, "MY COMMANDER");
    setcolor(COLOR(255, 0, 0));
    outtextxy(138, 10, ">");

    ///Informatii despre fisiere (nume, extensia, marimea, data)
    setcolor(COLOR(157, 157, 195));
    setfillstyle(SOLID_FILL, COLOR(233, 236, 255));
    bar3d(10, 80, 497, 105, 0, 0);
    bar3d(537, 80, 1014, 105, 0, 0);
    setcolor(BLACK);
    setbkcolor(COLOR(233, 236, 255));
    outtextxy(15, 85, "Name");
    outtextxy(542, 85, "Name");    ///urmeaza sa pun si ext, size si date


    ///Butoanele aplicatiei
    ///Go backwards
    setcolor(BLACK);
    setbkcolor(WHITE);
    outtextxy(10, 42, "  <  ");
    ///Go Forward
    outtextxy(50, 42,"  >  ");
    ///F3 View
    outtextxy(10, 740, " [F3] View ");
    ///F4 Edit
    outtextxy(110, 740, " [F4] Edit ");
    ///F5 Copy
    outtextxy(205, 740, " [F5] Copy ");
    ///F6 Move
    outtextxy(310, 740, " [F6] Move ");
    ///F7 NewFolder
    outtextxy(415, 740, " [F7] NewFolder ");
    ///F8 Delete
    outtextxy(555, 740, " [F8] Delete ");
    ///ESC iesirea din program
    outtextxy(665, 740, " [ESC] Exit ");
    ///Fereastra de inceput pe care ma focusez este cu rosu iar cealalta cu gri
    setcolor(COLOR(255, 0, 0));
    rectangle(10, 80,  496, 687);
    setcolor(DARKGRAY);
    rectangle(537, 80, 1013, 687);
}

void utilizareaAplicatiei()
{
    bool loop=true, mousePress=false, tastaEsc=false, tastaTab=false,
         careFereastra=false; ///false e stanga si true e dreapta
    int viewCounterStanga=1, viewCounterDreapta=1; ///variabile de contorizare a adancimii fisierelor
    int clickX, clickY;///coordonate mouse
    while (loop)
    {

        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (!mousePress)
            {
                mousePress=true;
                clickX=mousex();
                clickY=mousey();
                if (clickX>=665 && clickX<=761 && clickY>=740 && clickY<=748)
                    ///Am apasat cu mouse-ul butonul ESC
                    loop=false;
            }
            mousePress=false;
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            if (!tastaEsc)
                tastaEsc=true;
            loop=false;
        }
        if (GetAsyncKeyState(VK_TAB))
        {
            if (!tastaTab) tastaTab=true;
            {
                if (careFereastra==false)
                {
                    careFereastra=true;
                    setcolor(DARKGRAY);
                    rectangle(10, 80,  496, 687);
                    setcolor(COLOR(255, 0, 0));
                    rectangle(537, 80, 1013, 687);
                }
                else
                {
                    careFereastra=false;
                    setcolor(COLOR(255, 0, 0));
                    rectangle(10, 80,  496, 687);
                    setcolor(DARKGRAY);
                    rectangle(537, 80, 1013, 687);
                }
            }
            tastaTab=false;
            Sleep(300);
        }
    }
}

int main()
{
    initwindow(1024, 768);
    HUD();
    cautare_stanga_start();
    utilizareaAplicatiei();
    closegraph();
    return 0;
}
