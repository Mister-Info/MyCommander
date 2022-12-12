#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include<cstring>
#include<windows.h>
///windows.h este folosit pentru a lista fisierele
#include <graphics.h>
#include <winbgim.h>
#include "macro.h"


using namespace std;

void splashScreen()
{
    readimagefile("SplashArt.jpg", 0, 0, 1024, 768);
    delay(100);
}

bool fisiere_exista(const char* fisier)
{
    FILE *f=fopen(fisier,"r");
    if(!f)
        return false;
    fclose(f);
    return true;

}

bool exista(const char* cale)
{
    DWORD atribute=GetFileAttributesA(cale);
    return atribute!=INVALID_FILE_ATTRIBUTES;
}

void afisare( char **listaIntreaga, int deUndeAfisez, int panaUndeAfisez, int pozitiaCurenta, int x)
{
    int y=110;
    for(int i=deUndeAfisez; i<panaUndeAfisez; i++)
    {
        if(i==pozitiaCurenta)///select
        {
            setcolor(BLACK);
            setbkcolor(COLOR(149, 159, 255));
            outtextxy(x,y,listaIntreaga[i]);
            y+=20;

        }
        else
        {
            setcolor(BLACK);
            setbkcolor(WHITE);
            outtextxy(x,y,listaIntreaga[i]);
            y+=20;
        }
    }
}


void initializareVectorDeNumeFoldereFisiere(char **intreagaLista,char ** foldere,char ** fisiere,int nr_foldere,int nr_fisiere)
{
    int lgLista=0, i, lg=0;
    for (i=0; i<nr_foldere; i++)
    {
        lg=strlen(foldere[i]);
        if (lg>60)
        {
            strncpy(intreagaLista[lgLista], foldere[i], 54);
            intreagaLista[lgLista][54]=0;
            strcat(intreagaLista[lgLista], "...");
            lgLista++;
        }
        else
            strcpy(intreagaLista[lgLista], foldere[i]), lgLista++;
    }
    for (i=0; i<nr_fisiere; i++)
    {
        lg=strlen(fisiere[i]);
        if (lg>60)
        {
            strncpy(intreagaLista[lgLista], fisiere[i], 54);
            intreagaLista[lgLista][54]=0;
            strcat(intreagaLista[lgLista], "...");
            lgLista++;
        }
        else
            strcpy(intreagaLista[lgLista], fisiere[i]), lgLista++;
    }
}

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


    setcolor(COLOR(255, 0, 0));
    rectangle(10, 80,  496, 687);
    setcolor(DARKGRAY);
    rectangle(537, 80, 1013, 687);



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


    setcolor(DARKGRAY);
    rectangle(10, 80,  496, 687);
    setcolor(COLOR(255, 0, 0));
    rectangle(537, 80, 1013, 687);


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
            if(!(cautare.dwFileAttributes&FILE_ATTRIBUTE_SYSTEM))///sunt foldere de sistem si le ignoram
            {
                strcpy(foldere[nr_foldere++],cautare.cFileName);
            }
        }
        else
        {
            strcpy(fisiere[nr_fisiere++],cautare.cFileName);
        }

    }
}

void stergere(char* sursa)
{
    if(GetFileAttributes(sursa)&FILE_ATTRIBUTE_DIRECTORY)///folder
    {
        ///find all files, copiere foldere, mai putin ..
        int i;
        for(i=strlen(sursa)-1; i>0&&sursa[i]!='\\'; --i);

        char p[257];
        strcpy(p,sursa);
        strcat(p,"\\*");

        WIN32_FIND_DATA cautare;

        HANDLE director=FindFirstFile(p,&cautare);


        while(FindNextFile(director, &cautare))
        {


            if(strcmp(cautare.cFileName, "..")!=0)
            {
                int index=strlen(sursa);
                strcat(sursa,"\\");
                strcat(sursa,cautare.cFileName);
                stergere(sursa);
                sursa[index]=NULL;
            }


        }
        RemoveDirectoryA(sursa);
    }
    else
    {
        DeleteFileA(sursa);
    }
}


void copierefoldere(char *sursa, char *destinatie)
{

    if(GetFileAttributes(sursa)&FILE_ATTRIBUTE_DIRECTORY)///folder
    {
        ///find all files, copiere foldere, mai putin ..
        int i;
        for(i=strlen(sursa)-1; i>0&&sursa[i]!='\\'; --i);

        char p[257];
        strcpy(p,sursa);
        strcat(p,"\\*");

        WIN32_FIND_DATA cautare;

        HANDLE director=FindFirstFile(p,&cautare);
        int index_destinatie=strlen(destinatie);

        strcat(destinatie,"\\");

        strcat(destinatie,sursa+i+1);
        CreateDirectoryA(destinatie,NULL);
        while(FindNextFile(director, &cautare))
        {


            if(strcmp(cautare.cFileName, "..")!=0)
            {
                int index=strlen(sursa);
                strcat(sursa,"\\");
                strcat(sursa,cautare.cFileName);
                copierefoldere(sursa,destinatie);
                sursa[index]=NULL;
            }


        }
        destinatie[index_destinatie]=NULL;
    }
    else
    {
        int i;
        for(i=strlen(sursa)-1; i>0&&sursa[i]!='\\'; --i);
        int index=strlen(destinatie);
        strcat(destinatie,"\\");
        strcat(destinatie,sursa+i+1);
        bool valid=true;
        FILE*fisier_sursa=fopen(sursa,"rb");
        FILE*fisier_destinatie=fopen(destinatie,"wb");

        if(fisier_sursa==NULL||fisier_destinatie==NULL)
        {
            valid=false;
        }

        char buffer[16*1024];///16 kb, mai eficient decat daca as citi cate 1 byte
        int n; /// Cati bytes s-au citit din fisierul sursa

        ///Citim maxim 16kb; fread() va returna numarul de bytes cititi,
        ///indiferent daca sunt 16kb sau mai putini



        while ((n = fread(buffer, sizeof(char), sizeof(buffer), fisier_sursa)) > 0)
        {
            if (fwrite(buffer, sizeof(char), n, fisier_destinatie) != n)
            {
                ///nu a putut sa se scrie in fisier
                printf("eroare");
                valid=false;
                ///va trebui sa facem o functie de afisare pentru erori
                break;
            }
        }


        fclose(fisier_sursa);
        fclose(fisier_destinatie);


        destinatie[index]=NULL;


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
    outtextxy(10, 8, "<");
    setcolor(WHITE);
    outtextxy(460, 8, "MY COMMANDER");
    setcolor(COLOR(255, 0, 0));
    outtextxy(1004, 8, ">");

    ///Numele fisierelor
    setcolor(COLOR(157, 157, 195));
    setfillstyle(SOLID_FILL, COLOR(233, 236, 255));
    bar3d(10, 80, 497, 105, 0, 0);
    bar3d(537, 80, 1014, 105, 0, 0);
    setcolor(BLACK);
    setbkcolor(COLOR(233, 236, 255));
    outtextxy(15, 85, "Name");
    outtextxy(542, 85, "Name");
    setcolor(COLOR(157, 157, 195));
    bar3d(496, 80, 516, 688, 0, 0);
    bar3d(518, 80, 538, 688, 0, 0);

    ///Butoanele aplicatiei
    ///Up Stanga
    setcolor(BLACK);
    setbkcolor(COLOR(233, 236, 255));
    outtextxy(498, 84, " /\\ ");
    ///Down Stanga
    outtextxy(498, 668, " \\/ ");
    ///Up Dreapta
    outtextxy(520, 84, " /\\ ");
    ///Down Dreapta
    outtextxy(520, 668, " \\/ ");
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

    ///SORTARE ASCENDING
    setbkcolor(COLOR(220, 220, 220));
    outtextxy(90, 42, " Sort by (Asc.): ");
    ///Buton Sort by name
    setcolor(COLOR(86, 89, 252));
    setbkcolor(COLOR(255, 135, 19));
    outtextxy(195, 42, "    Name    ");
    ///Buton Sort by ext
    setcolor(COLOR(90, 252, 86));
    setbkcolor(COLOR(255, 68, 68));
    outtextxy(277, 42, "  Extension  ");
    ///Buton Sort by size
    setcolor(COLOR(255, 255, 68));
    setbkcolor(COLOR(252, 86, 249));
    outtextxy(371, 42, "    Size    ");
    ///buton Sort by date
    setcolor(COLOR(255, 93, 50));
    setbkcolor(COLOR(86, 252, 252));
    outtextxy(445, 42, "    Date    ");

    ///SORTARE ASCENDING
    setcolor(BLACK);
    setbkcolor(COLOR(220, 220, 220));
    outtextxy(527, 42, " Sort by (Desc.): ");
    ///Buton Sort by name
    setcolor(COLOR(255, 135, 19));
    setbkcolor(COLOR(86, 89, 252));
    outtextxy(642, 42, "    Name    ");
    ///Buton Sort by ext
    setcolor(COLOR(255, 68, 68));
    setbkcolor(COLOR(90, 252, 86));
    outtextxy(724, 42, "  Extension  ");
    ///Buton Sort by size
    setcolor(COLOR(252, 86, 249));
    setbkcolor(COLOR(255, 255, 68));
    outtextxy(818, 42, "    Size    ");
    ///Buton Sort by date
    setcolor(COLOR(86, 252, 252));
    setbkcolor(COLOR(255, 93, 50));
    outtextxy(892, 42, "    Date    ");

    ///Buton de help
    setcolor(BLACK);
    setbkcolor(WHITE);
    outtextxy(975, 42, " Help ");

    ///Fereastra de inceput pe care ma focusez este cu rosu iar cealalta cu gri
    setcolor(COLOR(255, 0, 0));
    rectangle(10, 80,  496, 687);
    setcolor(DARKGRAY);
    rectangle(537, 80, 1013, 687);

    /// Path bars
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    bar3d(10, 689, 497, 709, 0, 0);
    bar3d(537, 689, 1014, 709, 0, 0);

    /// Info Bar
    bar3d(750, 738, 1014, 758, 0, 0);
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

    char** intreagaStanga = init_lista(202, 257);
    char** intreagaDreapta = init_lista(202, 257);

    int nr_foldereStanga, nr_fisiereStanga;
    int nr_foldereDreapta, nr_fisiereDreapta;

    ///tastele apasate
    bool loop=true, mousePress=false, tastaEsc=false, tastaTab=false, tastaDown=false, tastaUp=false,tastaEnter=false,careFereastra=false; ///false e stanga si true e dreapta
    bool copiere=false;
    bool tasta_stergere=false;
    bool redenumire=false;
    bool deplasare=false;
    bool valid=true;
    bool vizualizare=false;
    bool editare=false;
    bool newfolder=false;
    int nrFoldereFisiereStanga, nrFoldereFisiereDreapta,
        deUndeAfisezStanga[7], panaUndeAfisezStanga[7], nivStivaStanga=0,
                                                        deUndeAfisezDreapta[7], panaUndeAfisezDreapta[7], nivStivaDreapta=0;
    int viewCounterStanga=0, viewCounterDreapta=0; ///folderul/fisierul selectat
    int clickX, clickY;///coordonate mouse
    char caleStanga[257], caleDreapta[257];

    ///la inceput vom afisa discurile locale(adica, avem cale goala)
    caleStanga[0]=NULL;
    caleDreapta[0]=NULL;

    ///listam discurile locale
    reindex(caleStanga,foldereStanga,fisiereStanga,nr_fisiereStanga,nr_foldereStanga);
    reindex(caleDreapta,foldereDreapta,fisiereDreapta,nr_fisiereDreapta,nr_foldereDreapta);

    initializareVectorDeNumeFoldereFisiere(intreagaStanga,foldereStanga,fisiereStanga,nr_foldereStanga,nr_fisiereStanga);
    initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldereDreapta,fisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);

    ///afisam discurile

    deUndeAfisezStanga[0]=0;
    panaUndeAfisezStanga[0]=nr_fisiereStanga+nr_foldereStanga;
    afisare(intreagaStanga, deUndeAfisezStanga[0], panaUndeAfisezStanga[0], 0, 15);
    deUndeAfisezDreapta[0]=0;
    panaUndeAfisezDreapta[0]=nr_fisiereDreapta+nr_foldereDreapta;
    afisare(intreagaDreapta, deUndeAfisezDreapta[0], panaUndeAfisezDreapta[0], 0, 542);


    while (loop)
    {

        ///copiere
        if(GetAsyncKeyState(VK_F5))
        {
            if(!copiere)
            {
                copiere=true;///implementare
                if(careFereastra==false)
                {
                    char *numefisierfolder;
                    if(viewCounterStanga<nr_foldereStanga)
                    {

                        numefisierfolder=foldereStanga[viewCounterStanga];

                    }

                    else
                    {
                        numefisierfolder=fisiereStanga[viewCounterStanga-nr_foldereStanga];
                    }
                    char *folder= (char*)malloc(256);


                    strcpy(folder,caleStanga);


                    bool ok=true;
                    strcat(folder,"\\");
                    strcat(folder,numefisierfolder);

                    if(ok)
                    {
                        copierefoldere(folder, caleDreapta);
                        reindexare_Dreapta();
                        reindexare_Stanga();
                    }
                    free(folder);

                }
                else
                {
                    char *numefisierfolder;
                    if(viewCounterDreapta<nr_foldereDreapta)
                    {

                        numefisierfolder=foldereDreapta[viewCounterDreapta];

                    }

                    else
                    {
                        numefisierfolder=fisiereDreapta[viewCounterDreapta-nr_foldereDreapta];
                    }
                    char *folder= (char*)malloc(256);


                    strcpy(folder,caleDreapta);


                    bool ok=true;
                    strcat(folder,"\\");
                    strcat(folder,numefisierfolder);
                    if(ok)
                    {
                        copierefoldere(folder, caleStanga);
                        reindexare_Stanga();
                        reindexare_Dreapta();
                    }

                    free(folder);

                }
            }
        }

        else
        {
            copiere=false;
        }



        if(GetAsyncKeyState(VK_F7))
        {
            if(!newfolder)
            {
                newfolder=true;

                if(careFereastra==false)
                {
                    char *folder =(char*) malloc(256);

                    strcpy(folder,caleStanga);
                    strcat(folder,"\\");
                    strcat(folder,"NewFolder");

                    CreateDirectoryA(folder,NULL);

                    reindexare_Dreapta();
                    reindexare_Stanga();


                    free(folder);

                }
                else{
                    char *folder =(char*) malloc(256);

                    strcpy(folder,caleDreapta);
                    strcat(folder,"\\");
                    strcat(folder,"NewFolder");

                    CreateDirectoryA(folder,NULL);

                    reindexare_Stanga();
                    reindexare_Dreapta();

                    free(folder);
                }



            }
        }
        else {

            newfolder=false;
        }




        ///stergerea
        if(GetAsyncKeyState(VK_F8))
        {
            if(!tasta_stergere)
            {
                tasta_stergere=true;


                if(careFereastra==false)
                {
                    char *numefisierfolder;
                    if(viewCounterStanga<nr_foldereStanga)
                    {

                        numefisierfolder=foldereStanga[viewCounterStanga];

                    }

                    else
                    {
                        numefisierfolder=fisiereStanga[viewCounterStanga-nr_foldereStanga];
                    }
                    char *folder= (char*)malloc(256);


                    strcpy(folder,caleStanga);


                    bool ok=false;
                    strcat(folder,"\\");
                    strcat(folder,numefisierfolder);
                    if(exista(folder))
                    {

                        int msgboxID = MessageBoxA(NULL,
                                                   "Are you sure?\nDo you want to remove the file or directory?", "Delete",
                                                   MB_ICONEXCLAMATION | MB_YESNO);

                        if (msgboxID == IDYES)
                        {
                            ok = true;
                        }

                    }
                    if(ok)
                    {
                        stergere(folder);
                        reindexare_Dreapta();
                        reindexare_Stanga();
                    }
                    free(folder);


                }

                else
                {
                    char *numefisierfolder;
                    if(viewCounterDreapta<nr_foldereDreapta)
                    {

                        numefisierfolder=foldereDreapta[viewCounterDreapta];

                    }

                    else
                    {
                        numefisierfolder=fisiereDreapta[viewCounterDreapta-nr_foldereDreapta];
                    }
                    char *folder= (char*)malloc(256);


                    strcpy(folder,caleDreapta);


                    bool ok=false;
                    strcat(folder,"\\");
                    strcat(folder,numefisierfolder);
                    if(exista(folder))
                    {

                        int msgboxID = MessageBoxA(NULL,
                                                   "Are you sure?\nDo you want to remove the file or directory?", "Delete",
                                                   MB_ICONEXCLAMATION | MB_YESNO);

                        if (msgboxID == IDYES)
                        {
                            ok = true;
                        }

                    }
                    if(ok)
                    {
                        stergere(folder);
                        reindexare_Stanga();
                        reindexare_Dreapta();
                    }

                    free(folder);



                }
            }
        }
        else
        {
            tasta_stergere=false;
        }


        ///Move
        if(GetAsyncKeyState(VK_F6))
        {
            if(!deplasare)
            {
                deplasare=true;
                if(careFereastra==false)
                {

                    char *numefisierfolder;
                    if(viewCounterStanga<nr_foldereStanga)
                    {

                        numefisierfolder=foldereStanga[viewCounterStanga];

                    }

                    else
                    {
                        numefisierfolder=fisiereStanga[viewCounterStanga-nr_foldereStanga];
                    }
                    char *folder= (char*)malloc(256);


                    strcpy(folder,caleStanga);


                    bool ok=true;
                    strcat(folder,"\\");
                    strcat(folder,numefisierfolder);

                    if(ok)
                    {
                        copierefoldere(folder, caleDreapta);
                        stergere(folder);
                        reindexare_Dreapta();
                        reindexare_Stanga();
                    }
                    free(folder);
                }
                else
                {
                    char *numefisierfolder;
                    if(viewCounterDreapta<nr_foldereDreapta)
                    {

                        numefisierfolder=foldereDreapta[viewCounterDreapta];

                    }

                    else
                    {
                        numefisierfolder=fisiereDreapta[viewCounterDreapta-nr_foldereDreapta];
                    }
                    char *folder= (char*)malloc(256);


                    strcpy(folder,caleDreapta);


                    bool ok=true;
                    strcat(folder,"\\");
                    strcat(folder,numefisierfolder);
                    if(ok)
                    {
                        copierefoldere(folder, caleStanga);
                        stergere(folder);
                        reindexare_Stanga();
                        reindexare_Dreapta();
                    }

                    free(folder);
                }
            }
        }
            else
            {
                deplasare=false;
            }

            ///Edit
            if(GetAsyncKeyState(VK_F4))
            {
                if(!editare)
                {
                    editare=true;

                    if (careFereastra==false)///stanga
                    {


                        ///am selectat un fisier
                        if(viewCounterStanga>=nr_foldereStanga)
                        {
                            char *fisier= (char*)malloc(256);
                            strcpy(fisier,"notepad.exe \"");
                            strcat(fisier,caleStanga);

                            char *nume_fisier=fisiereStanga[viewCounterStanga-nr_foldereStanga];

                            strcat(fisier,"\\");
                            strcat(fisier,nume_fisier);
                            strcat(fisier,"\"");

                            system(fisier); ///deschide
                            free(fisier);

                        }
                        else
                        {
                            ///edit pe un folder
                            int msgboxID = MessageBoxA(NULL,
                                                   "Please select a file", "Edit",
                                                   MB_ICONEXCLAMATION | MB_OK);

                        }
                    }
                    else if(careFereastra==true)
                    {
                        if(viewCounterDreapta>=nr_foldereDreapta)
                        {
                            ///enter pe un fisier
                            char *fisier= (char*)malloc(256);
                            strcpy(fisier,"notepad.exe \"");
                            strcat(fisier,caleDreapta);

                            char *nume_fisier=fisiereDreapta[viewCounterDreapta-nr_foldereDreapta];

                            strcat(fisier,"\\");
                            strcat(fisier,nume_fisier);
                            strcat(fisier,"\"");

                            system(fisier);
                            free(fisier);
                        }
                        else
                        {
                            ///edit pe un folder
                            int msgboxID = MessageBoxA(NULL,
                                                   "Please select a file", "Edit",
                                                   MB_ICONEXCLAMATION | MB_OK);
                        }
                    }
                }
            }
            else
            {
                editare=false;
            }


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
                            char *fisier= (char*)malloc(256);
                            strcpy(fisier,"\"");
                            strcat(fisier,caleStanga);

                            char *nume_fisier=fisiereStanga[viewCounterStanga-nr_foldereStanga];

                            strcat(fisier,"\\");
                            strcat(fisier,nume_fisier);
                            strcat(fisier,"\"");

                            system(fisier); ///deschide
                            free(fisier);

                        }
                        else
                        {
                            ///enter pe un folder
                            if (caleStanga[0] != NULL)
                            {
                                strcat(caleStanga, "\\");
                            }
                            strcat(caleStanga,foldereStanga[viewCounterStanga]);

                            reindexare_Stanga();
                        }
                    }
                    else if(careFereastra==true)
                    {
                        if(viewCounterDreapta>=nr_foldereDreapta)
                        {
                            ///enter pe un fisier
                            char *fisier= (char*)malloc(256);
                            strcpy(fisier,"\"");
                            strcat(fisier,caleDreapta);

                            char *nume_fisier=fisiereDreapta[viewCounterDreapta-nr_foldereDreapta];

                            strcat(fisier,"\\");
                            strcat(fisier,nume_fisier);
                            strcat(fisier,"\"");

                            system(fisier);
                            free(fisier);
                        }
                        else
                        {
                            ///enter pe un folder
                            if (caleDreapta[0] != NULL)
                            {
                                strcat(caleDreapta, "\\");
                            }
                            strcat(caleDreapta,foldereDreapta[viewCounterDreapta]);

                            reindexare_Dreapta();
                        }
                    }
                }
            }
            else
            {
                tastaEnter=false;
            }

            ///Edit
            if(GetAsyncKeyState(VK_F3))
            {
                if(!vizualizare)
                {
                    vizualizare=true;
                    if (careFereastra==false)///stanga
                    {


                        ///am selectat un fisier
                        if(viewCounterStanga>=nr_foldereStanga)
                        {
                            char *fisier= (char*)malloc(256);
                            strcpy(fisier,"\"");
                            strcat(fisier,caleStanga);

                            char *nume_fisier=fisiereStanga[viewCounterStanga-nr_foldereStanga];

                            strcat(fisier,"\\");
                            strcat(fisier,nume_fisier);
                            strcat(fisier,"\"");

                            system(fisier); ///deschide
                            free(fisier);

                        }
                        else
                        {
                            ///edit pe un folder
                            int msgboxID = MessageBoxA(NULL,
                                                   "Please select a file", "View",
                                                   MB_ICONEXCLAMATION | MB_OK);

                        }
                    }
                    else if(careFereastra==true)
                    {
                        if(viewCounterDreapta>=nr_foldereDreapta)
                        {
                            ///enter pe un fisier
                            char *fisier= (char*)malloc(256);
                            strcpy(fisier,"\"");
                            strcat(fisier,caleDreapta);

                            char *nume_fisier=fisiereDreapta[viewCounterDreapta-nr_foldereDreapta];

                            strcat(fisier,"\\");
                            strcat(fisier,nume_fisier);
                            strcat(fisier,"\"");

                            system(fisier);
                            free(fisier);
                        }
                        else
                        {
                            ///edit pe un folder
                            int msgboxID = MessageBoxA(NULL,
                                                   "Please select a file", "View",
                                                   MB_ICONEXCLAMATION | MB_OK);
                        }
                    }

                }
            }
            else {
                vizualizare=false;
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
                        if (viewCounterStanga==panaUndeAfisezStanga[nivStivaStanga])
                        {
                            if (panaUndeAfisezStanga[nivStivaStanga]+29<nrFoldereFisiereStanga)
                            {
                                nivStivaStanga++;
                                panaUndeAfisezStanga[nivStivaStanga]=panaUndeAfisezStanga[nivStivaStanga-1]+29;
                            }
                            else
                                nivStivaStanga++,panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                            deUndeAfisezStanga[nivStivaStanga]=viewCounterStanga;
                            clear_stanga();
                        }
                        afisare(intreagaStanga, deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15);

                    }
                    else if(careFereastra==true && viewCounterDreapta+1<nr_foldereDreapta+nr_fisiereDreapta)
                    {
                        viewCounterDreapta++;
                        if (viewCounterDreapta==panaUndeAfisezDreapta[nivStivaDreapta])
                        {
                            if (panaUndeAfisezDreapta[nivStivaDreapta]+29<nrFoldereFisiereDreapta)
                            {
                                nivStivaDreapta++;
                                panaUndeAfisezDreapta[nivStivaDreapta]=panaUndeAfisezDreapta[nivStivaDreapta-1]+29;
                            }
                            else
                                nivStivaDreapta++, panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                            deUndeAfisezDreapta[nivStivaDreapta]=viewCounterDreapta;
                            clear_dreapta();
                        }
                        afisare(intreagaDreapta, deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542);

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
                        if (nivStivaStanga>0 && viewCounterStanga==deUndeAfisezStanga[nivStivaStanga]-1)
                        {
                            nivStivaStanga--;
                            clear_stanga();
                        }
                        afisare(intreagaStanga, deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15);
                    }
                    else if(careFereastra==true && viewCounterDreapta-1>=0)
                    {
                        viewCounterDreapta--;
                        if (nivStivaDreapta>0 && viewCounterDreapta==deUndeAfisezDreapta[nivStivaDreapta]-1)
                        {
                            nivStivaDreapta--;
                            clear_dreapta();
                        }
                        afisare(intreagaDreapta, deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542);
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
                    if (clickX>=665 && clickX<=761 && clickY>=740 && clickY<=756)
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

            ///TAB
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
        free(intreagaStanga);
        free(intreagaDreapta);
    }

    int main()
    {
        initwindow(1024, 768, "My Commander");
        splashScreen();
        HUD();
        utilizareaAplicatiei();
        closegraph();
        return 0;
    }
