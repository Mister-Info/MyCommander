#include <iostream>
#include <cstdlib>
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
            strcat(discuri_locale[nrdisc],"Local disk:");///11
            strcat(discuri_locale[nrdisc++],pcopie);

        }



        int x=25;
        int y=100;

        for(int i=0; i<nrdisc; i++)
        {
            if(i==0)
            {
                setcolor(RED);
                setbkcolor(GREEN);
                outtextxy(x,y,discuri_locale[i]);
                y+=25;
            }
            else
            {
                setcolor(BLACK);
                setbkcolor(WHITE);
                outtextxy(x,y,discuri_locale[i]);
                y+=25;
            }
        }


        for(int i=0; i<nrdisc; i++)
        {
            indexare_foldere_fisiere(p, cautare,  foldere, fisiere, nr_foldere, nr_fisiere);


           for(int j=0; j<nr_foldere; j++)
            {

                printf("[%s] \n",foldere[j]);
            }
            for(int j=0; j<nr_fisiere; j++)
            {

                printf("%s \n",fisiere[j]);
            }
        }

        FindClose(director);

    }
}

///Razvan
void setWindowTitle()
{
    HWND hWnd, hWndChild;
    hWnd = FindWindow(NULL, "Windows BGI");
    hWndChild = GetWindow(hWnd, GW_CHILD);
    SendMessage((HWND) hWnd, WM_SETTEXT,0, (LPARAM)"MyCommander");
}

///Razvan
void HUD()
{
    setbkcolor(COLOR(220, 220, 220));///setare backgorund
    cleardevice();
    setcolor(DARKGRAY);///setare culoare
    setfillstyle(SOLID_FILL, WHITE);
    bar3d(10, 80,  497, 688, 0, 0);
    bar3d(537, 80, 1014, 688, 0, 0);

    setcolor(DARKGRAY);
    line(0, 728, 1024, 728);
    line(0, 70, 1024, 70);
    setfillstyle(SOLID_FILL, COLOR(94, 53, 248));
    bar(0, 0, 1024, 30);

}
int main()
{
    initwindow(1024, 768);
    setWindowTitle();
    HUD();
    cautare_stanga_start();
    getch();
    closegraph();

    return 0;
}
