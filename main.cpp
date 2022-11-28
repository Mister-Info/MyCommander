#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include<cstring>
#include<windows.h>
///windows.h este folosit pentru a lista fisierele
#include <graphics.h>
#include <winbgim.h>


using namespace std;


void clear_stanga()
{
    /// Background alb
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, WHITE);
    bar3d(10, 80,  497, 688, 0, 0);

    /// Nume, extensie, etc
    setcolor(COLOR(157, 157, 195));
    setfillstyle(SOLID_FILL, COLOR(233, 236, 255));
    bar3d(10, 80, 497, 105, 0, 0);
    setcolor(BLACK);
    setbkcolor(COLOR(233, 236, 255));
    outtextxy(15, 85, "Name");
}

void clear_dreapta()
{
    /// Background alb
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, WHITE);
    bar3d(537, 80, 1014, 688, 0, 0);

    /// Nume, extensie, etc
    setcolor(COLOR(157, 157, 195));
    setfillstyle(SOLID_FILL, COLOR(233, 236, 255));
    bar3d(537, 80, 1014, 105, 0, 0);
    setcolor(BLACK);
    setbkcolor(COLOR(233, 236, 255));
    outtextxy(542, 85, "Name");
}

void indexare_foldere_fisiere(char cale[],char **foldere, char **fisiere, int &nr_foldere, int &nr_fisiere)
///functia asta gaseste folderele si fisierele
{

    WIN32_FIND_DATA cautare;
    char p[257];
    strcpy(p,cale);
    strcat(p,"\\*");
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
/// char **p este un vector de vectori
void afisare( char **foldere,char **fisiere, int nr_foldere,int nr_fisiere,int pozitiaCurenta,int x)
{
    int y=110;


    for(int i=0; i<nr_foldere; i++)
    {
        if(i==pozitiaCurenta)///select
        {
            setcolor(BLACK);
            setbkcolor(COLOR(149, 159, 255));
            outtextxy(x,y,foldere[i]);
            y+=20;

        }
        else
        {
            setcolor(BLACK);
            setbkcolor(WHITE);
            outtextxy(x,y,foldere[i]);
            y+=20;
        }
    }
    for(int i=0; i<nr_fisiere; i++)
    {
        if(i+nr_foldere==pozitiaCurenta)///fisierele sunt afisate dupa foldere
        {
            setcolor(BLACK);
            setbkcolor(COLOR(149, 159, 255));
            outtextxy(x,y,fisiere[i]);
            y+=20;

        }
        else
        {
            setcolor(BLACK);
            setbkcolor(WHITE);
            outtextxy(x,y,fisiere[i]);
            y+=20;
        }
    }
}

///indexarea pentru discuri
void cautare_start(char **foldere,int &nr_foldere, int &nr_fisiere)
{

    WIN32_FIND_DATA cautare;
    char p[255];

    nr_fisiere=0;
    nr_foldere=0;
    for(char c='A'; c<='Z'; c++)
    {
        char disk[2];
        disk[0]=c;
        disk[1]=NULL;
        strcpy(p,disk);
        strcat(p,":");///pentru viitoarele local discuri
        strcat(p,"\\*");

        HANDLE director=FindFirstFile(p,&cautare);///directorul explicit

        if(director!=INVALID_HANDLE_VALUE)///practic daca directorul ala nu are nimic
        {
            char pcopie[3];
            pcopie[0]=p[0];
            pcopie[1]=':';
            pcopie[2]=NULL;

            strcpy(foldere[nr_foldere++],pcopie);


        }

        FindClose(director);

    }
}

///listeaza fisierele si folderele dintr-o cale
///cale goala = lista din discurile locale
void reindex(char cale[], char **foldere, char **fisiere, int &nr_fisiere, int &nr_foldere)
{

    nr_foldere=nr_fisiere=0;
    if(cale[0]==NULL)
    {
        cautare_start(foldere,nr_foldere,nr_fisiere);
    }
    else
    {
        indexare_foldere_fisiere(cale, foldere, fisiere,nr_foldere,nr_fisiere);
    }
}


///Heads Up Display
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

/// Aloca memorie pentru o matrice NxM
/// (vector de siruri de caractere)
char** init_lista(int n, int m)
{
    /// Alocam N linii, adica spatiu pentru N pointeri
    char** lista = (char**) malloc(n * sizeof(char*));///char* are 4 sau 8 bytes

    for (int i = 0; i < n; ++i)
    {
        /// Alocam M coloane pentru linia i, adica spatiu pentru M caractere
        lista[i] = (char*) malloc(m * sizeof(char));///char are 1 byte
    }

    return lista;
}

void utilizareaAplicatiei()
{
    ///marimile sunt hardcodate, dar pe viitor voi creste dinamic in functie de numarul de foldere
    char** foldereStanga = init_lista(101, 257);
    char** fisiereStanga = init_lista(101, 257);

    char** foldereDreapta = init_lista(101, 257);
    char** fisiereDreapta = init_lista(101, 257);

    int nr_foldereStanga, nr_fisiereStanga;
    int nr_foldereDreapta, nr_fisiereDreapta;

    ///tastele apasate
    bool loop=true, mousePress=false, tastaEsc=false, tastaTab=false, tastaDown=false, tastaUp=false,tastaEnter=false,careFereastra=false; ///false e stanga si true e dreapta

    int viewCounterStanga=0, viewCounterDreapta=0; ///folderul/fisierul selectat
    int clickX, clickY;///coordonate mouse
    char caleStanga[257], caleDreapta[257];

    ///la inceput vom afisa discurile locale(adica, avem cale goala)
    caleStanga[0]=NULL;
    caleDreapta[0]=NULL;

    ///listam discurile locale
    reindex(caleStanga,foldereStanga,fisiereStanga,nr_fisiereStanga,nr_foldereStanga);
    reindex(caleDreapta,foldereDreapta,fisiereDreapta,nr_fisiereDreapta,nr_foldereDreapta);

    ///afisam discurile
    afisare(foldereStanga,fisiereStanga,nr_foldereStanga,nr_fisiereStanga,viewCounterStanga,15);
    afisare(foldereDreapta,fisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta,viewCounterDreapta,542);

    while (loop)
    {
        ///Enter
        if(GetAsyncKeyState(VK_RETURN))
        {

            if (!tastaEnter)
            {
                tastaEnter=true;

                if (careFereastra==false)///stanga
                {
                    ///am selectat un fisier
                    if(viewCounterStanga>=nr_foldereStanga)
                    {
                        ///enter pe un fisier
                        ///TODO: de implementat
                    }
                    else
                    {
                        ///enter pe un folder
                        if (caleStanga[0] != NULL)
                        {
                            strcat(caleStanga, "\\");
                        }
                        strcat(caleStanga,foldereStanga[viewCounterStanga]);

                        viewCounterStanga = 0;

                        reindex(caleStanga,foldereStanga,fisiereStanga,nr_fisiereStanga,nr_foldereStanga);
                        clear_stanga();
                        afisare(foldereStanga,fisiereStanga,nr_foldereStanga,nr_fisiereStanga,viewCounterStanga,15);
                    }
                }
                else if(careFereastra==true)
                {
                    if(viewCounterDreapta>=nr_foldereDreapta)
                    {
                        ///enter pe un fisier
                        ///TODO: de implementat
                    }
                    else
                    {
                        ///enter pe un folder
                        if (caleDreapta[0] != NULL)
                        {
                            strcat(caleDreapta, "\\");
                        }
                        strcat(caleDreapta,foldereDreapta[viewCounterDreapta]);

                        viewCounterDreapta = 0;

                        reindex(caleDreapta,foldereDreapta,fisiereDreapta,nr_fisiereDreapta,nr_foldereDreapta);
                        clear_dreapta();
                        afisare(foldereDreapta,fisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta,viewCounterDreapta,542);
                    }
                }
            }
        }
        else
        {
            tastaEnter=false;
        }
        ///modific selected
        ///DownArrow
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (!tastaDown)
            {
                tastaDown=true;

                if (careFereastra==false && viewCounterStanga+1<nr_foldereStanga+nr_fisiereStanga)
                {
                    viewCounterStanga++;
                    afisare(foldereStanga,fisiereStanga,nr_foldereStanga,nr_fisiereStanga,viewCounterStanga,15);


                }
                else if(careFereastra==true && viewCounterDreapta+1<nr_foldereDreapta+nr_fisiereDreapta)
                {
                    viewCounterDreapta++;
                    afisare(foldereDreapta,fisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta,viewCounterDreapta,542);
                }
            }
        }
        else
        {
            tastaDown=false;
        }

        ///UpArrow
        if (GetAsyncKeyState(VK_UP))
        {
            if (!tastaUp)
            {
                tastaUp=true;

                if (careFereastra==false && viewCounterStanga-1>=0)
                {
                    viewCounterStanga--;
                    afisare(foldereStanga,fisiereStanga,nr_foldereStanga,nr_fisiereStanga,viewCounterStanga,15);
                }
                else if(careFereastra==true && viewCounterDreapta-1>=0)
                {
                    viewCounterDreapta--;
                    afisare(foldereDreapta,fisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta,viewCounterDreapta,542);
                }
            }
        }
        else
        {
            tastaUp=false;
        }



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
        }
        else
        {
            mousePress=false;
        }

        ///ESC
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            if (!tastaEsc)
            {
                tastaEsc=true;
                loop=false;
            }
        }
        else
        {
            tastaEsc = false;
        }

        if (GetAsyncKeyState(VK_TAB))
        {
            if (!tastaTab)
            {
                tastaTab=true;

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
        }
        else
        {
            tastaTab=false;
        }
    }

    ///Eliberam memoria
    free(foldereStanga);
    free(fisiereStanga);
    free(foldereDreapta);
    free(fisiereDreapta);
}

int main()
{
    initwindow(1024, 768);
    HUD();
    utilizareaAplicatiei();
    closegraph();
    return 0;
}
