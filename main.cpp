///
/// 888b     d888            .d8888b.                                                              888
/// 8888b   d8888           d88P  Y88b                                                             888
/// 88888b.d88888           888    888                                                             888
/// 888Y88888P888 888  888  888         .d88b.  88888b.d88b.  88888b.d88b.   8888b.  88888b.   .d88888  .d88b.  888d888
/// 888 Y888P 888 888  888  888        d88""88b 888 "888 "88b 888 "888 "88b     "88b 888 "88b d88" 888 d8P  Y8b 888P"
/// 888  Y8P  888 888  888  888    888 888  888 888  888  888 888  888  888 .d888888 888  888 888  888 88888888 888
/// 888   "   888 Y88b 888  Y88b  d88P Y88..88P 888  888  888 888  888  888 888  888 888  888 Y88b 888 Y8b.     888
/// 888       888  "Y88888   "Y8888P"   "Y88P"  888  888  888 888  888  888 "Y888888 888  888  "Y88888  "Y8888  888
///                    888
///               Y8b d88P
///                "Y88P"




///TODO: select: stergere, move si sa restrictionez edit+view



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


struct DATE_FILE
{
    unsigned int zi, luna, an;
};

void convertSize(char chstring[], long unsigned int marime)
{
    char temp[101];
    long unsigned int aux=marime, lg=0, i, j;
    while (aux)
    {
        temp[lg]='0'+aux%10;
        aux/=10;
        lg++;
    }
    temp[lg]=0;
    for (i=lg-1,j=0; j<lg; i--, j++)
        chstring[j]=temp[i];
    chstring[lg]=0;
}

void convertDate(char chstring[], DATE_FILE a)
{
    int lg=0;
    if (a.zi<10)
    {
        chstring[lg++]='0';
        chstring[lg++]='0'+a.zi;
        chstring[lg++]='/';
    }
    else
    {
        chstring[lg++]='0'+a.zi/10;
        chstring[lg++]='0'+a.zi%10;
        chstring[lg++]='/';
    }
    if (a.luna<10)
    {
        chstring[lg++]='0';
        chstring[lg++]='0'+a.luna;
        chstring[lg++]='/';
    }
    else
    {
        chstring[lg++]='0'+a.luna/10;
        chstring[lg++]='0'+a.luna%10;
        chstring[lg++]='/';
    }
    chstring[lg++]='0'+a.an/1000;
    chstring[lg++]='0'+a.an/100%10;
    chstring[lg++]='0'+a.an/10%10;
    chstring[lg++]='0'+a.an%10;
    chstring[lg]=0;
}
void sortareDupaExtensieAsc(char **arr, char** extArr, DATE_FILE dateArr[], unsigned long int sizeArr[], int lgArray)
{
    int i;
    unsigned long int auxULI;
    DATE_FILE auxDate;
    char temp[201];
    bool sortat;
    do
    {
        sortat=false;
        for (i=0; i<lgArray-1; i++)
        {
            if (strcmp(extArr[i], extArr[i+1])>0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
                strcpy(temp, extArr[i]);
                strcpy(extArr[i], extArr[i+1]);
                strcpy(extArr[i+1], temp);
                auxDate=dateArr[i];
                dateArr[i]=dateArr[i+1];
                dateArr[i+1]=auxDate;
                auxULI=sizeArr[i];
                sizeArr[i]=sizeArr[i+1];
                sizeArr[i+1]=auxULI;
                sortat=true;
            }
        }

    }
    while (sortat);
}
void sortareDupaExtensieDesc(char **arr, char** extArr, DATE_FILE dateArr[], unsigned long int sizeArr[], int lgArray)
{
    int i;
    unsigned long int auxULI;
    DATE_FILE auxDate;
    char temp[201];
    bool sortat;
    do
    {
        sortat=false;
        for (i=0; i<lgArray-1; i++)
        {
            if (strcmp(extArr[i], extArr[i+1])<0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
                strcpy(temp, extArr[i]);
                strcpy(extArr[i], extArr[i+1]);
                strcpy(extArr[i+1], temp);
                auxDate=dateArr[i];
                dateArr[i]=dateArr[i+1];
                dateArr[i+1]=auxDate;
                auxULI=sizeArr[i];
                sizeArr[i]=sizeArr[i+1];
                sizeArr[i+1]=auxULI;
                sortat=true;
            }
        }

    }
    while (sortat);
}
void sortareDupaSizeDesc(char **arr, char** extArr, DATE_FILE dateArr[], unsigned long int sizeArr[], int lgArray)
{
    int i;
    unsigned long int auxULI;
    DATE_FILE auxDate;
    char temp[201];
    bool sortat;
    do
    {
        sortat=false;
        for (i=0; i<lgArray-1; i++)
        {
            if (sizeArr[i]<sizeArr[i+1])
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
                strcpy(temp, extArr[i]);
                strcpy(extArr[i], extArr[i+1]);
                strcpy(extArr[i+1], temp);
                auxDate=dateArr[i];
                dateArr[i]=dateArr[i+1];
                dateArr[i+1]=auxDate;
                auxULI=sizeArr[i];
                sizeArr[i]=sizeArr[i+1];
                sizeArr[i+1]=auxULI;
                sortat=true;
            }
        }

    }
    while (sortat);
}



void sortareDupaSizeAsc(char **arr, char** extArr, DATE_FILE dateArr[], unsigned long int sizeArr[], int lgArray)
{
    int i;
    unsigned long int auxULI;
    DATE_FILE auxDate;
    char temp[201];
    bool sortat;
    do
    {
        sortat=false;
        for (i=0; i<lgArray-1; i++)
        {
            if (sizeArr[i]>sizeArr[i+1])
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
                strcpy(temp, extArr[i]);
                strcpy(extArr[i], extArr[i+1]);
                strcpy(extArr[i+1], temp);
                auxDate=dateArr[i];
                dateArr[i]=dateArr[i+1];
                dateArr[i+1]=auxDate;
                auxULI=sizeArr[i];
                sizeArr[i]=sizeArr[i+1];
                sizeArr[i+1]=auxULI;
                sortat=true;
            }
        }

    }
    while (sortat);
}

int comparDate(DATE_FILE a, DATE_FILE b)
{
    if (a.an>b.an) return 1;
    if (a.an<b.an) return -1;


    if (a.luna>b.luna) return 1;
    if (a.luna<b.luna) return -1;


    if (a.zi>b.zi) return 1;
    if (a.zi<b.zi) return -1;


    return 0;
}

void sortareDupaDateAsc(char **arr, char** extArr, DATE_FILE dateArr[], unsigned long int sizeArr[], int lgArray)
{
    int i;
    unsigned long int auxULI;
    DATE_FILE auxDate;
    char temp[201];
    bool sortat;
    do
    {
        sortat=false;
        for (i=0; i<lgArray-1; i++)
        {
            if (comparDate(dateArr[i], dateArr[i+1])>0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
                strcpy(temp, extArr[i]);
                strcpy(extArr[i], extArr[i+1]);
                strcpy(extArr[i+1], temp);
                auxDate=dateArr[i];
                dateArr[i]=dateArr[i+1];
                dateArr[i+1]=auxDate;
                auxULI=sizeArr[i];
                sizeArr[i]=sizeArr[i+1];
                sizeArr[i+1]=auxULI;
                sortat=true;
            }
        }

    }
    while (sortat);
}
void sortareDupaDateDesc(char **arr, char** extArr, DATE_FILE dateArr[], unsigned long int sizeArr[], int lgArray)
{
    int i;
    unsigned long int auxULI;
    DATE_FILE auxDate;
    char temp[201];
    bool sortat;
    do
    {
        sortat=false;
        for (i=0; i<lgArray-1; i++)
        {
            if (comparDate(dateArr[i], dateArr[i+1])<0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
                strcpy(temp, extArr[i]);
                strcpy(extArr[i], extArr[i+1]);
                strcpy(extArr[i+1], temp);
                auxDate=dateArr[i];
                dateArr[i]=dateArr[i+1];
                dateArr[i+1]=auxDate;
                auxULI=sizeArr[i];
                sizeArr[i]=sizeArr[i+1];
                sizeArr[i+1]=auxULI;
                sortat=true;
            }
        }

    }
    while (sortat);
}


void sortareDupaNumeAsc(char **arr, char** extArr, DATE_FILE dateArr[], unsigned long int sizeArr[], int lgArray)
{
    int i;
    unsigned long int auxULI;
    DATE_FILE auxDate;
    char temp[201];
    bool sortat;
    do
    {
        sortat=false;
        for (i=0; i<lgArray-1; i++)
        {
            if (strcmp(arr[i], "..")!=0)
                if (strcmp(arr[i], arr[i+1])>0)
                {
                    strcpy(temp, arr[i]);
                    strcpy(arr[i], arr[i+1]);
                    strcpy(arr[i+1], temp);
                    strcpy(temp, extArr[i]);
                    strcpy(extArr[i], extArr[i+1]);
                    strcpy(extArr[i+1], temp);
                    auxDate=dateArr[i];
                    dateArr[i]=dateArr[i+1];
                    dateArr[i+1]=auxDate;
                    auxULI=sizeArr[i];
                    sizeArr[i]=sizeArr[i+1];
                    sizeArr[i+1]=auxULI;
                    sortat=true;
                }
        }

    }
    while (sortat);
}

void sortareDupaNumeDesc(char **arr, char** extArr, DATE_FILE dateArr[], unsigned long int sizeArr[], int lgArray)
{
    int i;
    char temp[201];
    unsigned long int auxULI;
    DATE_FILE auxDate;
    bool sortat;
    do
    {
        sortat=false;
        for (i=0; i<lgArray-1; i++)
        {
            if (strcmp(arr[i], "..")!=0)
                if (strcmp(arr[i], arr[i+1])<0)
                {
                    strcpy(temp, arr[i]);
                    strcpy(arr[i], arr[i+1]);
                    strcpy(arr[i+1], temp);
                    strcpy(temp, extArr[i]);
                    strcpy(extArr[i], extArr[i+1]);
                    strcpy(extArr[i+1], temp);
                    auxDate=dateArr[i];
                    dateArr[i]=dateArr[i+1];
                    dateArr[i+1]=auxDate;
                    auxULI=sizeArr[i];
                    sizeArr[i]=sizeArr[i+1];
                    sizeArr[i+1]=auxULI;
                    sortat=true;
                }
        }

    }
    while (sortat);
}

void splashScreen()
{
    readimagefile("SplashArt.jpg", 0, 0, 1024, 768);
    delay(150);
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

void afisare(char **listaIntreaga, char **listaExt, DATE_FILE A, unsigned long int siz, int deUndeAfisez, int panaUndeAfisez, int pozitiaCurenta, int x, int *selectat, int nr_selectate)
{
    char ch[101];
    int y=110;
    for(int i=deUndeAfisez; i<panaUndeAfisez; i++)
    {

        bool gasit=false;
        for(int j=0; j<nr_selectate; ++j)
        {
            if(i==selectat[j])
            {
                gasit=true;
                break;
            }
        }
        if(gasit)
        {

            setcolor(RED);
        }

        if(i==pozitiaCurenta)///select
        {
            if(!gasit)
            {
                if (strcmp(listaExt[i], "<dir>")==0)
                {
                    setcolor(COLOR(115, 115, 0));
                }
                else
                    setcolor(BLACK);
            }
            setbkcolor(COLOR(149, 159, 255));
            outtextxy(x,y,listaIntreaga[i]);
            y+=20;


        }
        else
        {
            if(!gasit)
            {
                if (strcmp(listaExt[i], "<dir>")==0) setcolor(COLOR(115, 115, 0));
                else
                    setcolor(BLACK);
            }
            setbkcolor(WHITE);
            outtextxy(x,y,listaIntreaga[i]);
            y+=20;
        }
        if (listaIntreaga[0][1]!=':')
        {
            setcolor(BLACK);
            setfillstyle(SOLID_FILL, WHITE);
            setbkcolor(WHITE);
            bar3d(760, 738, 1014, 758, 0, 0);
            line(887, 738, 887, 756);
            convertSize(ch, siz);
            outtextxy(764, 740, ch);
            outtextxy(865, 740, "KB");
            convertDate(ch, A);
            outtextxy(915, 740,ch);
        }
    }
}


void initializareVectorDeNumeFoldereFisiere(char **intreagaLista, char**foldFisExt, unsigned long int foldFisSize[],DATE_FILE foldFisDate[],
        char ** foldere,char ** fisiere, char **extFoldere, char**extFisiere, unsigned long int marimeFoldere[],
        unsigned long int marimeFisiere[], DATE_FILE dataFoldere[], DATE_FILE dataFisiere[],
        int nr_foldere,int nr_fisiere)
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
            foldFisSize[lgLista]=marimeFoldere[i];
            foldFisDate[lgLista]=dataFoldere[i];
            strcpy(foldFisExt[lgLista], extFoldere[i]);
            lgLista++;
        }
        else
        {

            foldFisSize[lgLista]=marimeFoldere[i];
            foldFisDate[lgLista]=dataFoldere[i];
            strcpy(foldFisExt[lgLista], extFoldere[i]);
            strcpy(intreagaLista[lgLista], foldere[i]), lgLista++;
        }
    }
    for (i=0; i<nr_fisiere; i++)
    {
        lg=strlen(fisiere[i]);
        if (lg>60)
        {
            strncpy(intreagaLista[lgLista], fisiere[i], 54);
            intreagaLista[lgLista][54]=0;
            foldFisSize[lgLista]=marimeFisiere[i];
            foldFisDate[lgLista]=dataFisiere[i];
            strcpy(foldFisExt[lgLista], extFisiere[i]);
            strcat(intreagaLista[lgLista], "...");
            lgLista++;
        }
        else
        {
            foldFisSize[lgLista]=marimeFisiere[i];
            foldFisDate[lgLista]=dataFisiere[i];
            strcpy(foldFisExt[lgLista], extFisiere[i]);
            strcpy(intreagaLista[lgLista], fisiere[i]), lgLista++;
        }
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

void indexare_foldere_fisiere(char cale[],char **foldere, char **fisiere, char** extensieFoldere, char** extensieFisiere,
                              long unsigned int marimeFoldere[], long unsigned int marimeFisiere[],
                              DATE_FILE candAfostCreatFoldere[], DATE_FILE candAfostCreatFisiere[],
                              int &nr_foldere, int &nr_fisiere)
///functia asta gaseste folderele si fisierele
{

    WIN32_FIND_DATA cautare;
    int i, j;
    char p[257], temp_ext[257]= {0};
    strcpy(p,cale);
    strcat(p,"\\*");
    nr_fisiere=nr_foldere=0;

    HANDLE director=FindFirstFile(p,&cautare);
    LPFILETIME Creare;
    DWORD Marimea;

    SYSTEMTIME TIMP_structurat;

    long unsigned int siz;

    while(FindNextFile(director, &cautare))
    {

        if(cautare.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
        {
            if(!(cautare.dwFileAttributes&FILE_ATTRIBUTE_SYSTEM))///sunt foldere de sistem si le ignoram
            {
                strcpy(foldere[nr_foldere],cautare.cFileName);
                FileTimeToSystemTime(&cautare.ftLastWriteTime, &TIMP_structurat);
                marimeFoldere[nr_foldere]=0;
                candAfostCreatFoldere[nr_foldere].zi=TIMP_structurat.wDay;
                candAfostCreatFoldere[nr_foldere].luna=TIMP_structurat.wMonth;
                candAfostCreatFoldere[nr_foldere].an=TIMP_structurat.wYear;
                strcpy(extensieFoldere[nr_foldere], "<dir>");
                nr_foldere++;
            }
        }
        else
        {
            strcpy(fisiere[nr_fisiere],cautare.cFileName);
            marimeFisiere[nr_fisiere]=cautare.nFileSizeLow/1024+1;
            FileTimeToSystemTime(&cautare.ftLastWriteTime, &TIMP_structurat);
            candAfostCreatFisiere[nr_fisiere].zi=TIMP_structurat.wDay;
            candAfostCreatFisiere[nr_fisiere].luna=TIMP_structurat.wMonth;
            candAfostCreatFisiere[nr_fisiere].an=TIMP_structurat.wYear;
            strcpy(temp_ext, cautare.cFileName);
            for (i=strlen(temp_ext)-1; temp_ext[i]!='.'; i--);
            i++;
            for (j=0; i<strlen(temp_ext); j++)
            {
                extensieFisiere[nr_fisiere][j]=temp_ext[i];
                i++;
            }
            nr_fisiere++;
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
void reindex(char cale[], char **foldere, char **fisiere, char** extensieFoldere, char** extensieFisiere,
             long unsigned int marimeFoldere[], long unsigned int marimeFisiere[],
             DATE_FILE candAfostCreatFoldere[], DATE_FILE candAfostCreatFisiere[], int &nr_fisiere, int &nr_foldere)
{

    nr_foldere=nr_fisiere=0;
    if(cale[0]==NULL)
    {
        cautare_start(foldere,nr_foldere,nr_fisiere);
    }
    else
    {
        indexare_foldere_fisiere(cale, foldere, fisiere, extensieFoldere, extensieFisiere, marimeFoldere,marimeFisiere,
                                 candAfostCreatFoldere, candAfostCreatFisiere,nr_foldere,nr_fisiere);
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
    setcolor(COLOR(255, 0, 0));
    setbkcolor(WHITE);
    ///Back to Local Disks
    outtextxy(6, 42, " Local Disks ");
    setcolor(BLACK);
    setbkcolor(WHITE);
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
    outtextxy(665, 740, " [Alt+F4] Exit ");

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

    ///SORTARE DESCENDING
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
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    bar3d(760, 738, 1014, 758, 0, 0);
    line(887, 738, 887, 756);
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
    char** extensieFoldereStanga = init_lista (101, 257);
    char** extensieFisiereStanga = init_lista (101, 257);
    long unsigned int marimeFoldereStanga[101];
    long unsigned int marimeFisiereStanga[101];
    long unsigned int foldFisSizeStanga[202];
    DATE_FILE candAfostCreatFoldereStanga[101];
    DATE_FILE candAfostCreatFisiereStanga[101];
    DATE_FILE foldFisDateStanga[202];
    char** foldFisExtStanga = init_lista(101, 257);

    char** foldereDreapta = init_lista(101, 257);
    char** fisiereDreapta = init_lista(101, 257);
    char** extensieFoldereDreapta = init_lista (101, 257);
    char** extensieFisiereDreapta = init_lista (101, 257);
    long unsigned int marimeFoldereDreapta[101];
    long unsigned int marimeFisiereDreapta[101];
    long unsigned int foldFisSizeDreapta[202];
    DATE_FILE candAfostCreatFoldereDreapta[101];
    DATE_FILE candAfostCreatFisiereDreapta[101];
    DATE_FILE foldFisDateDreapta[202];
    char** foldFisExtDreapta= init_lista(101, 257);

    char** intreagaStanga = init_lista(202, 257);
    char** intreagaDreapta = init_lista(202, 257);

    char* renameFileString=(char *)malloc(256);
    char tastaIntrodusaRename=0, c;
    int lenRenameFileString=0;
    int coordXRename;

    int nr_foldereStanga, nr_fisiereStanga;
    int nr_foldereDreapta, nr_fisiereDreapta;

    ///tastele apasate
    bool loop=true, loopRename=false, mousePress=false, tastaEsc=false, tastaTab=false,
         tastaDown=false, tastaUp=false,tastaEnter=false,careFereastra=false, ///false e stanga si true e dreapta
         hotKeyCtrlR=false, tastaBack=false, hotkeyLocalDisks=false;
    bool copiere=false;
    bool tasta_stergere=false;
    bool redenumire=false;
    bool deplasare=false;
    bool valid=true;
    bool vizualizare=false;
    bool editare=false;
    bool newfolder=false;
    bool selectare=false;
    DATE_FILE afisStart;
    afisStart.an=1;
    int nrFoldereFisiereStanga, nrFoldereFisiereDreapta,
        deUndeAfisezStanga[7], panaUndeAfisezStanga[7], nivStivaStanga=0,
                                                        deUndeAfisezDreapta[7], panaUndeAfisezDreapta[7], nivStivaDreapta=0;
    int viewCounterStanga=0, viewCounterDreapta=0; ///folderul/fisierul selectat
    int clickX, clickY;///coordonate mouse
    char caleStanga[4096], caleDreapta[4096];

    int *selectie_stanga=(int *)malloc(sizeof(int)*4096);
    int *selectie_dreapta=(int *)malloc(sizeof(int)*4096);
    int nr_selectii_stanga=0;
    int nr_selectii_dreapta=0;

    ///la inceput vom afisa discurile locale(adica, avem cale goala)
    caleStanga[0]=NULL;
    caleDreapta[0]=NULL;

    ///listam discurile locale
    reindex(caleStanga,foldereStanga,fisiereStanga,
            extensieFoldereStanga, extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,
            candAfostCreatFoldereStanga, candAfostCreatFisiereStanga,nr_fisiereStanga,nr_foldereStanga);

    reindex(caleDreapta,foldereDreapta,fisiereDreapta,
            extensieFoldereDreapta, extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,
            candAfostCreatFoldereDreapta, candAfostCreatFisiereDreapta,nr_fisiereDreapta,nr_foldereDreapta);

    initializareVectorDeNumeFoldereFisiere(intreagaStanga, foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,
                                           fisiereStanga, extensieFoldereStanga, extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,
                                           candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);
    initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,
                                           fisiereDreapta,extensieFoldereDreapta, extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,
                                           candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);

    ///afisam discurile
    deUndeAfisezStanga[0]=0;
    panaUndeAfisezStanga[0]=nr_fisiereStanga+nr_foldereStanga;
    afisare(intreagaStanga, foldFisExtStanga, afisStart, 0, deUndeAfisezStanga[0], panaUndeAfisezStanga[0], 0, 15,selectie_stanga,nr_selectii_stanga);
    deUndeAfisezDreapta[0]=0;
    panaUndeAfisezDreapta[0]=nr_fisiereDreapta+nr_foldereDreapta;
    afisare(intreagaDreapta, foldFisExtDreapta,afisStart, 0, deUndeAfisezDreapta[0], panaUndeAfisezDreapta[0], 0, 542,selectie_dreapta,nr_selectii_dreapta);


    while (loop)
    {


        if(GetAsyncKeyState(VK_LSHIFT))
        {
            if(!selectare)
            {
                selectare=true;
                if(careFereastra==false)
                {
                    bool gasit=false;
                    for(int i=0; i<nr_selectii_stanga; ++i)
                    {
                        if(selectie_stanga[i]==viewCounterStanga)
                        {
                            for(int j=i; j<nr_selectii_stanga-1; ++j)
                            {
                                selectie_stanga[j]=selectie_stanga[j+1];
                            }
                            --nr_selectii_stanga;
                            gasit=true;
                            break;
                        }
                    }
                    if(!gasit)
                    {
                        selectie_stanga[nr_selectii_stanga++]=viewCounterStanga;
                    }
                    afisare(intreagaStanga, foldFisExtStanga, foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);
                }
                else
                {
                    bool gasit=false;
                    for(int i=0; i<nr_selectii_dreapta; ++i)
                    {
                        if(selectie_dreapta[i]==viewCounterDreapta)
                        {
                            for(int j=i; j<nr_selectii_dreapta-1; ++j)
                            {
                                selectie_dreapta[j]=selectie_dreapta[j+1];
                            }
                            --nr_selectii_dreapta;
                            gasit=true;
                            break;
                        }
                    }
                    if(!gasit)
                    {
                        selectie_dreapta[nr_selectii_dreapta++]=viewCounterDreapta;
                    }
                    afisare(intreagaDreapta, foldFisExtDreapta, foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542,selectie_dreapta, nr_selectii_dreapta);
                }

            }
        }
        else
        {
            selectare=false;
        }





        ///copiere
        if(GetAsyncKeyState(VK_F5))
        {
            if(!copiere)
            {
                copiere=true;///implementare
                if(careFereastra==false)
                {

                    if(nr_selectii_stanga>0)
                    {

                        for(int i=0; i<nr_selectii_stanga; ++i)
                        {
                            copiereStanga(selectie_stanga[i]);

                        }
                    }
                    else
                    {
                        copiereStanga(viewCounterStanga);
                    }


                }
                else
                {
                    if(nr_selectii_dreapta>0)
                    {
                        for(int i=0; i<nr_selectii_dreapta; ++i)
                        {
                            copiereDreapta(selectie_dreapta[i]);
                        }
                    }
                    else
                    {
                        copiereDreapta(viewCounterStanga);
                    }

                }
            }
        }

        else
        {
            copiere=false;
        }


        ///NewFolder
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
                else
                {
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
        else
        {
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

                        if(strcmp(caleStanga,caleDreapta)!=0)
                        {
                            copierefoldere(folder, caleDreapta);
                            stergere(folder);
                            reindexare_Dreapta();
                            reindexare_Stanga();
                        }
                        else
                        {

                            MessageBoxA(NULL,"Error, you can't move the file/directory in the same location!", "Move",
                                        MB_ICONERROR | MB_OK);

                        }

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

                        if(strcmp(caleStanga,caleDreapta)!=0)
                        {
                            copierefoldere(folder, caleStanga);
                            stergere(folder);
                            reindexare_Stanga();
                            reindexare_Dreapta();
                        }
                        else
                        {
                            MessageBoxA(NULL,"Error, you can't move the file/directory in the same location!", "Move",
                                        MB_ICONERROR | MB_OK);
                        }

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
                        MessageBoxA(NULL,"Please select a file", "Edit", MB_ICONERROR | MB_OK);
                    }
                }
            }
        }
        else
        {
            editare=false;
        }


        ///Enter
        if(GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_RIGHT))
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

                        nr_selectii_stanga=0;
                        ///enter pe un folder
                        if (caleStanga[0] != NULL)
                        {
                            strcat(caleStanga, "\\");
                        }
                        strcat(caleStanga,foldereStanga[viewCounterStanga]);
                        reindexare_Stanga();
                        bar3d(10, 689, 497, 709, 0, 0);
                        char p[201]= {0};
                        int lg=strlen(caleStanga), i;
                        strcpy(p, caleStanga);
                        if (p[lg-1]=='.' && p[lg-2]=='.')
                        {
                            lg-=3;
                            p[lg]=0;
                            for (i=lg-1; p[i]!=92; i--) p[i]=0;
                            p[i]=0;
                        }
                        lg=strlen(p);
                        strcpy(caleStanga, p);
                        setcolor(RED);
                        if (lg<68)
                            outtextxy(12, 691, caleStanga);
                        else
                            outtextxy(12, 691, "Path too large");
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
                        nr_selectii_dreapta=0;
                        if (caleDreapta[0] != NULL)
                        {
                            strcat(caleDreapta, "\\");
                        }
                        strcat(caleDreapta,foldereDreapta[viewCounterDreapta]);

                        reindexare_Dreapta();
                        setcolor(BLACK);
                        setfillstyle(SOLID_FILL, WHITE);
                        bar3d(537, 689, 1014, 709, 0, 0);
                        char p[201]= {0};
                        int lg=strlen(caleDreapta), i;
                        strcpy(p, caleDreapta);
                        if (p[lg-1]=='.' && p[lg-2]=='.')
                        {
                            lg-=3;
                            p[lg]=0;
                            for (i=lg-1; p[i]!=92; i--) p[i]=0;
                            p[i]=0;
                        }
                        strcpy(caleDreapta, p);
                        setcolor(RED);
                        if (lg<68)
                            outtextxy(540, 691, caleDreapta);
                        else
                            outtextxy(540, 691, "Path too large");
                    }
                }
            }
        }
        else
        {
            tastaEnter=false;
        }

        ///View
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
                        ///view pe un folder
                        MessageBoxA(NULL, "Please select a file", "View", MB_ICONERROR | MB_OK);

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
                        ///view pe un folder
                        MessageBoxA(NULL,"Please select a file", "View", MB_ICONEXCLAMATION | MB_OK);
                    }
                }
            }
        }
        else
        {
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
                    afisare(intreagaStanga, foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);
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
                    afisare(intreagaDreapta, foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542,selectie_dreapta,nr_selectii_dreapta);

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
                    afisare(intreagaStanga, foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15, selectie_stanga,nr_selectii_stanga);
                }
                else if(careFereastra==true && viewCounterDreapta-1>=0)
                {
                    viewCounterDreapta--;
                    if (nivStivaDreapta>0 && viewCounterDreapta==deUndeAfisezDreapta[nivStivaDreapta]-1)
                    {
                        nivStivaDreapta--;
                        clear_dreapta();
                    }
                    afisare(intreagaDreapta, foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542, selectie_dreapta,nr_selectii_dreapta);
                }
            }
        }
        else
        {
            tastaUp=false;
        }

        ///Hotkey back to local disks
        if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState('L'))
        {


            if (!hotkeyLocalDisks)
            {
                hotkeyLocalDisks=true;

                if (careFereastra==false)
                {
                    clear_stanga();
                    caleStanga[0]=NULL;
                    viewCounterStanga=0;
                    nivStivaStanga=0;
                    deUndeAfisezStanga[0]=0;
                    panaUndeAfisezStanga[0]=0;
                    ///listam discurile locale
                    reindex(caleStanga,foldereStanga,fisiereStanga,
                            extensieFoldereStanga, extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,
                            candAfostCreatFoldereStanga, candAfostCreatFisiereStanga,nr_fisiereStanga,nr_foldereStanga);
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar3d(760, 738, 1014, 758, 0, 0);
                    line(887, 738, 887, 756);
                    bar3d(10, 689, 497, 709, 0, 0);
                    initializareVectorDeNumeFoldereFisiere(intreagaStanga, foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga,extensieFoldereStanga, extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);

                    ///afisam discurile

                    deUndeAfisezStanga[0]=0;
                    panaUndeAfisezStanga[0]=nr_fisiereStanga+nr_foldereStanga;
                    afisare(intreagaStanga, foldFisExtStanga, afisStart, 0,deUndeAfisezStanga[0], panaUndeAfisezStanga[0], 0, 15, selectie_stanga,nr_selectii_stanga);

                }
                else if (careFereastra==true)
                {
                    clear_dreapta();
                    caleDreapta[0]=NULL;
                    viewCounterDreapta=0;
                    nivStivaDreapta=0;
                    deUndeAfisezDreapta[0]=0;
                    panaUndeAfisezDreapta[0]=0;
                    ///listam discurile locale
                    reindex(caleDreapta,foldereDreapta,fisiereDreapta,
                            extensieFoldereDreapta, extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,
                            candAfostCreatFoldereDreapta, candAfostCreatFisiereDreapta,nr_fisiereDreapta,nr_foldereDreapta);
                    setcolor(BLACK);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar3d(760, 738, 1014, 758, 0, 0);
                    line(887, 738, 887, 756);
                    bar3d(537, 689, 1014, 709, 0, 0);
                    initializareVectorDeNumeFoldereFisiere(intreagaDreapta, foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta, extensieFoldereDreapta, extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                    ///afisam discurile

                    deUndeAfisezDreapta[0]=0;
                    panaUndeAfisezDreapta[0]=nr_fisiereDreapta+nr_foldereDreapta;
                    afisare(intreagaDreapta, foldFisExtDreapta, afisStart, 0, deUndeAfisezDreapta[0], panaUndeAfisezDreapta[0], 0, 542, selectie_dreapta,nr_selectii_dreapta);
                }

            }
            else
                hotkeyLocalDisks=false;
        }

        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (!mousePress)
            {
                mousePress=true;
                clickX=mousex();
                clickY=mousey();
                if (clickX>=665 && clickX<=761 && clickY>=740 && clickY<=756)
                    ///Am apasat cu mouse-ul butonul de iesire
                    loop=false;


                ///Am apasat pe butonul Sortare ASC dupa Nume
                if (clickX>=195 && clickX<=195+textwidth("    Name    ") && clickY>=42 && clickY<=58 )
                {
                    if (careFereastra==false)
                    {
                        sortareDupaNumeAsc(fisiereStanga, extensieFisiereStanga, candAfostCreatFisiereStanga, marimeFisiereStanga, nr_fisiereStanga);
                        initializareVectorDeNumeFoldereFisiere(intreagaStanga, foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga, extensieFoldereStanga, extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);
                        clear_stanga();
                        nivStivaStanga=0;
                        deUndeAfisezStanga[0]=0;
                        viewCounterStanga=0;
                        if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;
                        else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                        afisare(intreagaStanga, foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15, selectie_stanga,nr_selectii_stanga);
                    }
                    else if(careFereastra==true)
                    {
                        sortareDupaNumeAsc(fisiereDreapta, extensieFisiereDreapta, candAfostCreatFisiereDreapta, marimeFisiereDreapta, nr_fisiereDreapta);
                        initializareVectorDeNumeFoldereFisiere(intreagaDreapta, foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta, extensieFoldereDreapta, extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                        clear_dreapta();
                        nivStivaDreapta=0;
                        deUndeAfisezDreapta[0]=0;
                        viewCounterDreapta=0;
                        if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;
                        else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                        afisare(intreagaDreapta,foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542, selectie_dreapta,nr_selectii_dreapta);

                    }
                }

                ///Am apasat pe butonul Sortare ASC dupa Extensie
                if (clickX>=277 && clickX<=277+textwidth("  Extension  ") && clickY>=42 && clickY<=58 )
                {
                    if (careFereastra==false)
                    {
                        sortareDupaExtensieAsc(fisiereStanga, extensieFisiereStanga, candAfostCreatFisiereStanga, marimeFisiereStanga, nr_fisiereStanga);
                        initializareVectorDeNumeFoldereFisiere(intreagaStanga, foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga,extensieFoldereStanga,extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);
                        clear_stanga();
                        nivStivaStanga=0;
                        deUndeAfisezStanga[0]=0;
                        viewCounterStanga=0;
                        if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;
                        else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                        afisare(intreagaStanga,foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15, selectie_stanga,nr_selectii_stanga);
                    }
                    else if(careFereastra==true)
                    {
                        sortareDupaExtensieAsc(fisiereDreapta, extensieFisiereDreapta, candAfostCreatFisiereDreapta, marimeFisiereDreapta, nr_fisiereDreapta);
                        initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta,extensieFoldereDreapta,extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                        clear_dreapta();
                        nivStivaDreapta=0;
                        deUndeAfisezDreapta[0]=0;
                        viewCounterDreapta=0;
                        if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;
                        else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                        afisare(intreagaDreapta,foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542, selectie_dreapta,nr_selectii_dreapta);

                    }
                }
                ///Am apasat pe butonul Sortare ASC dupa Size
                if (clickX>=371 && clickX<=371+textwidth("    Size    ") && clickY>=42 && clickY<=58 )
                {
                    if (careFereastra==false)
                    {
                        sortareDupaSizeAsc(fisiereStanga, extensieFisiereStanga, candAfostCreatFisiereStanga, marimeFisiereStanga, nr_fisiereStanga);
                        initializareVectorDeNumeFoldereFisiere(intreagaStanga,foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga,extensieFoldereStanga,extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);
                        clear_stanga();
                        nivStivaStanga=0;
                        deUndeAfisezStanga[0]=0;
                        viewCounterStanga=0;
                        if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;
                        else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                        afisare(intreagaStanga,foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15, selectie_stanga,nr_selectii_stanga);
                    }
                    else if(careFereastra==true)
                    {
                        sortareDupaSizeAsc(fisiereDreapta, extensieFisiereDreapta, candAfostCreatFisiereDreapta, marimeFisiereDreapta, nr_fisiereDreapta);
                        initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta,extensieFoldereDreapta,extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                        clear_dreapta();
                        nivStivaDreapta=0;
                        deUndeAfisezDreapta[0]=0;
                        viewCounterDreapta=0;
                        if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;
                        else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                        afisare(intreagaDreapta,foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542, selectie_dreapta,nr_selectii_dreapta);

                    }
                }
                ///Am apasat pe butonul Sortare ASC dupa Date
                if (clickX>=445 && clickX<=445+textwidth("    Date    ") && clickY>=42 && clickY<=58 )
                {
                    if (careFereastra==false)
                    {
                        sortareDupaDateAsc(fisiereStanga, extensieFisiereStanga, candAfostCreatFisiereStanga, marimeFisiereStanga, nr_fisiereStanga);
                        initializareVectorDeNumeFoldereFisiere(intreagaStanga,foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga, extensieFoldereStanga, extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);
                        clear_stanga();
                        nivStivaStanga=0;
                        deUndeAfisezStanga[0]=0;
                        viewCounterStanga=0;
                        if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;
                        else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                        afisare(intreagaStanga,foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);
                    }
                    else if(careFereastra==true)
                    {
                        sortareDupaDateAsc(fisiereDreapta, extensieFisiereDreapta, candAfostCreatFisiereDreapta, marimeFisiereDreapta, nr_fisiereDreapta);
                        initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta,extensieFoldereDreapta,extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                        clear_dreapta();
                        nivStivaDreapta=0;
                        deUndeAfisezDreapta[0]=0;
                        viewCounterDreapta=0;
                        if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;
                        else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                        afisare(intreagaDreapta,foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542, selectie_stanga,nr_selectii_stanga);

                    }
                }



                ///Am apasat pe butonul Sortare DESC dupa Nume
                if (clickX>=642 && clickX<=642+textwidth("    Name    ") && clickY>=42 && clickY<=58 )
                {
                    if (careFereastra==false)
                    {
                        sortareDupaNumeDesc(fisiereStanga, extensieFisiereStanga, candAfostCreatFisiereStanga, marimeFisiereStanga, nr_fisiereStanga);
                        initializareVectorDeNumeFoldereFisiere(intreagaStanga,foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga,extensieFoldereStanga,extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);
                        clear_stanga();
                        nivStivaStanga=0;
                        deUndeAfisezStanga[0]=0;
                        viewCounterStanga=0;
                        if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;
                        else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                        afisare(intreagaStanga,foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);
                    }
                    else if(careFereastra==true)
                    {
                        sortareDupaNumeDesc(fisiereDreapta, extensieFisiereDreapta, candAfostCreatFisiereDreapta, marimeFisiereDreapta, nr_fisiereDreapta);
                        initializareVectorDeNumeFoldereFisiere(intreagaDreapta, foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta,extensieFoldereDreapta,extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                        clear_dreapta();
                        nivStivaDreapta=0;
                        deUndeAfisezDreapta[0]=0;
                        viewCounterDreapta=0;
                        if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;
                        else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                        afisare(intreagaDreapta, foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542,selectie_dreapta,nr_selectii_dreapta);

                    }
                }

                ///Am apasat pe butonul Sortare Desc dupa Extensie
                if (clickX>=724 && clickX<=724+textwidth("  Extension  ") && clickY>=42 && clickY<=58 )
                {
                    if (careFereastra==false)
                    {
                        sortareDupaExtensieDesc(fisiereStanga, extensieFisiereStanga, candAfostCreatFisiereStanga, marimeFisiereStanga, nr_fisiereStanga);
                        initializareVectorDeNumeFoldereFisiere(intreagaStanga,foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga,extensieFoldereStanga,extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);
                        clear_stanga();
                        nivStivaStanga=0;
                        deUndeAfisezStanga[0]=0;
                        viewCounterStanga=0;
                        if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;
                        else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                        afisare(intreagaStanga,foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);
                    }
                    else if(careFereastra==true)
                    {
                        sortareDupaExtensieDesc(fisiereDreapta, extensieFisiereDreapta, candAfostCreatFisiereDreapta, marimeFisiereDreapta, nr_fisiereDreapta);
                        initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta,extensieFoldereDreapta,extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                        clear_dreapta();
                        nivStivaDreapta=0;
                        deUndeAfisezDreapta[0]=0;
                        viewCounterDreapta=0;
                        if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;
                        else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                        afisare(intreagaDreapta,foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542, selectie_dreapta,nr_selectii_dreapta);

                    }
                }
                ///Am apasat pe butonul Sortare Desc dupa Size
                if (clickX>=818 && clickX<=818+textwidth("    Size    ") && clickY>=42 && clickY<=58 )
                {
                    if (careFereastra==false)
                    {
                        sortareDupaSizeDesc(fisiereStanga, extensieFisiereStanga, candAfostCreatFisiereStanga, marimeFisiereStanga, nr_fisiereStanga);
                        initializareVectorDeNumeFoldereFisiere(intreagaStanga,foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga,extensieFoldereStanga,extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);
                        clear_stanga();
                        nivStivaStanga=0;
                        deUndeAfisezStanga[0]=0;
                        viewCounterStanga=0;
                        if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;
                        else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                        afisare(intreagaStanga,foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15, selectie_stanga,nr_selectii_stanga);
                    }
                    else if(careFereastra==true)
                    {
                        sortareDupaSizeDesc(fisiereDreapta, extensieFisiereDreapta, candAfostCreatFisiereDreapta, marimeFisiereDreapta, nr_fisiereDreapta);
                        initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta,extensieFoldereDreapta,extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                        clear_dreapta();
                        nivStivaDreapta=0;
                        deUndeAfisezDreapta[0]=0;
                        viewCounterDreapta=0;
                        if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;
                        else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                        afisare(intreagaDreapta,foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542, selectie_dreapta,nr_selectii_dreapta);

                    }
                }
                ///Am apasat pe butonul Sortare Desc dupa Date
                if (clickX>=892 && clickX<=892+textwidth("    Date    ") && clickY>=42 && clickY<=58 )
                {
                    if (careFereastra==false)
                    {
                        sortareDupaDateDesc(fisiereStanga, extensieFisiereStanga, candAfostCreatFisiereStanga, marimeFisiereStanga, nr_fisiereStanga);
                        initializareVectorDeNumeFoldereFisiere(intreagaStanga,foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga,extensieFoldereStanga,extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);
                        clear_stanga();
                        nivStivaStanga=0;
                        deUndeAfisezStanga[0]=0;
                        viewCounterStanga=0;
                        if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;
                        else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                        afisare(intreagaStanga,foldFisExtStanga,foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);
                    }
                    else if(careFereastra==true)
                    {
                        sortareDupaDateDesc(fisiereDreapta, extensieFisiereDreapta, candAfostCreatFisiereDreapta, marimeFisiereDreapta, nr_fisiereDreapta);
                        initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta,extensieFoldereDreapta,extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                        clear_dreapta();
                        nivStivaDreapta=0;
                        deUndeAfisezDreapta[0]=0;
                        viewCounterDreapta=0;
                        if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;
                        else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                        afisare(intreagaDreapta,foldFisExtDreapta,foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542, selectie_dreapta,nr_selectii_dreapta);

                    }
                }


                ///Am apasat pe butonul F3
                if (clickX>=10 && clickX<=10+textwidth(" [F3] View ") && clickY>=740 && clickY<=756 )
                {
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
                            MessageBoxA(NULL,"Please select a file", "View",MB_ICONEXCLAMATION | MB_OK);
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
                            MessageBoxA(NULL,"Please select a file", "View", MB_ICONEXCLAMATION | MB_OK);
                        }
                    }
                }


                ///Am apasat pe butonul F4
                if (clickX>=110 && clickX<=110+textwidth(" [F4] Edit ") && clickY>=740 && clickY<=756 )
                {
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
                            MessageBoxA(NULL,"Please select a file", "Edit",MB_ICONEXCLAMATION | MB_OK);

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
                            MessageBoxA(NULL,"Please select a file", "Edit",MB_ICONEXCLAMATION | MB_OK);
                        }
                    }
                }


                ///Am apasat pe butonul F5
                if (clickX>=205 && clickX<=205+textwidth(" [F5] Copy ") && clickY>=740 && clickY<=756 )
                {
                    if(careFereastra==false)
                    {

                        if(nr_selectii_stanga>0)
                        {

                            for(int i=0; i<nr_selectii_stanga; ++i)
                            {
                                copiereStanga(selectie_stanga[i]);

                            }
                        }
                        else
                        {
                            copiereStanga(viewCounterStanga);
                        }


                    }
                    else
                    {
                        if(nr_selectii_dreapta>0)
                        {
                            for(int i=0; i<nr_selectii_dreapta; ++i)
                            {
                                copiereDreapta(selectie_dreapta[i]);
                            }
                        }
                        else
                        {
                            copiereDreapta(viewCounterStanga);
                        }

                    }
                }


                ///Am apasat pe butonul F6
                if (clickX>=310 && clickX<=310+textwidth(" [F6] Move ") && clickY>=740 && clickY<=756)
                {
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
                            if(strcmp(caleStanga,caleDreapta)!=0)
                            {
                                copierefoldere(folder, caleDreapta);
                                stergere(folder);
                                reindexare_Dreapta();
                                reindexare_Stanga();
                            }
                            else
                            {

                                MessageBoxA(NULL,"Error, you can't move the file/directory in the same location!", "Move",
                                            MB_ICONERROR | MB_OK);

                            }
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

                ///Am apasat pe butonul F7
                if (clickX>=415 && clickX<=415+textwidth(" [F7] NewFolder ") && clickY>=740 && clickY<=756)
                {
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
                    else
                    {
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

                ///Am apasat pe butonul F8
                if (clickX>=555 && clickX<=555+textwidth(" [F8] Delete ") && clickY>=740 && clickY<=756 )
                {
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
                ///am apasat mai sus stanga
                if (clickX>=498 && clickX<=525 && clickY>=84 && clickY<=100)
                {
                    if (careFereastra==false)
                        if (deUndeAfisezStanga[nivStivaStanga]!=0)
                        {
                            nivStivaStanga--;
                            viewCounterStanga=deUndeAfisezStanga[nivStivaStanga];
                            clear_stanga();
                            afisare(intreagaStanga,foldFisExtStanga, foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], deUndeAfisezStanga[nivStivaStanga], 15,selectie_stanga,nr_selectii_stanga);
                        }
                }
                ///am apasat mai jos stanga
                if (clickX>=498 && clickX<=525 && clickY>=668 && clickY<=684)
                {
                    if (careFereastra==false)
                        if (panaUndeAfisezStanga[nivStivaStanga]<nrFoldereFisiereStanga)
                        {
                            if (panaUndeAfisezStanga[nivStivaStanga]+29<nrFoldereFisiereStanga)
                            {
                                nivStivaStanga++;
                                panaUndeAfisezStanga[nivStivaStanga]=panaUndeAfisezStanga[nivStivaStanga-1]+29;
                            }
                            else
                            {
                                nivStivaStanga++,panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;
                            }
                            deUndeAfisezStanga[nivStivaStanga]=viewCounterStanga=panaUndeAfisezStanga[nivStivaStanga-1];
                            clear_stanga();
                            afisare(intreagaStanga,foldFisExtStanga, foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);

                        }
                }
                ///am apasat mai sus dreapta
                if (clickX>=520 && clickX<=547 && clickY>=84 && clickY<=100)
                {
                    if (careFereastra==true)
                        if (deUndeAfisezDreapta[nivStivaDreapta]!=0)
                        {
                            nivStivaDreapta--;
                            viewCounterDreapta=deUndeAfisezDreapta[nivStivaDreapta];
                            clear_dreapta();
                            afisare(intreagaDreapta,foldFisExtDreapta, foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta],deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], deUndeAfisezDreapta[nivStivaDreapta], 542,selectie_dreapta,nr_selectii_dreapta);
                        }
                }

                ///am apasat mai jos dreapta
                if (clickX>=520 && clickX<=547 && clickY>=668 && clickY<=684)
                {
                    if (careFereastra==true)
                        if (panaUndeAfisezDreapta[nivStivaDreapta]<nrFoldereFisiereDreapta)
                        {
                            if (panaUndeAfisezDreapta[nivStivaDreapta]+29<nrFoldereFisiereDreapta)
                            {
                                nivStivaDreapta++;
                                panaUndeAfisezDreapta[nivStivaDreapta]=panaUndeAfisezDreapta[nivStivaDreapta-1]+29;
                            }
                            else
                            {
                                nivStivaDreapta++,panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;
                            }
                            deUndeAfisezDreapta[nivStivaDreapta]=viewCounterDreapta=panaUndeAfisezDreapta[nivStivaDreapta-1];
                            clear_dreapta();
                            afisare(intreagaDreapta,foldFisExtDreapta, foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542, selectie_dreapta,nr_selectii_dreapta);

                        }
                }

                ///am apasat pe butonul de help
                if (clickX>=975 && clickX<=975+textwidth(" Help ") && clickY>=42 && clickY<=58)
                {
                    bool loopHelp=true;
                    while (loopHelp)
                    {
                        readimagefile("HelpSection1.jpg", 20, 90, 487, 678);
                        readimagefile("HelpSection2.jpg", 547, 90, 1004, 678);
                        if (GetAsyncKeyState(VK_ESCAPE))
                        {
                            if (careFereastra==true)
                            {
                                clear_stanga();
                                clear_dreapta();
                                afisare(intreagaStanga,foldFisExtStanga, foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);
                                afisare(intreagaDreapta,foldFisExtDreapta, foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542,selectie_dreapta,nr_selectii_dreapta);

                                break;
                            }
                            else if(careFereastra==false)
                            {
                                clear_dreapta();
                                clear_stanga();
                                afisare(intreagaDreapta,foldFisExtDreapta, foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542,selectie_dreapta,nr_selectii_dreapta);
                                afisare(intreagaStanga,foldFisExtStanga, foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);
                                break;
                            }
                        }
                    }
                }

                ///Am apasat pe butonul Local Disks
                if (clickX>=6 && clickX<=6+textwidth(" Local Disks ") && clickY>=42 && clickY<=58)
                {
                    if (careFereastra==false)
                    {
                        clear_stanga();
                        caleStanga[0]=NULL;
                        viewCounterStanga=0;
                        nivStivaStanga=0;
                        deUndeAfisezStanga[0]=0;
                        panaUndeAfisezStanga[0]=0;
                        ///listam discurile locale
                        reindex(caleStanga,foldereStanga,fisiereStanga,
                                extensieFoldereStanga, extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,
                                candAfostCreatFoldereStanga, candAfostCreatFisiereStanga,nr_fisiereStanga,nr_foldereStanga);
                        setcolor(BLACK);
                        setfillstyle(SOLID_FILL, WHITE);
                        bar3d(760, 738, 1014, 758, 0, 0);
                        line(887, 738, 887, 756);
                        bar3d(10, 689, 497, 709, 0, 0);
                        initializareVectorDeNumeFoldereFisiere(intreagaStanga,foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga,extensieFoldereStanga,extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);

                        ///afisam discurile

                        deUndeAfisezStanga[0]=0;
                        panaUndeAfisezStanga[0]=nr_fisiereStanga+nr_foldereStanga;
                        afisare(intreagaStanga,foldFisExtStanga, afisStart, 0,deUndeAfisezStanga[0], panaUndeAfisezStanga[0], 0, 15,selectie_stanga,nr_selectii_stanga);

                    }
                    else if (careFereastra==true)
                    {
                        clear_dreapta();
                        caleDreapta[0]=NULL;
                        viewCounterDreapta=0;
                        nivStivaDreapta=0;
                        deUndeAfisezDreapta[0]=0;
                        panaUndeAfisezDreapta[0]=0;
                        ///listam discurile locale
                        reindex(caleDreapta,foldereDreapta,fisiereDreapta,
                                extensieFoldereDreapta, extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,
                                candAfostCreatFoldereDreapta, candAfostCreatFisiereDreapta,nr_fisiereDreapta,nr_foldereDreapta);
                        setcolor(BLACK);
                        setfillstyle(SOLID_FILL, WHITE);
                        bar3d(760, 738, 1014, 758, 0, 0);
                        line(887, 738, 887, 756);
                        bar3d(537, 689, 1014, 709, 0, 0);
                        initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta,extensieFoldereDreapta,extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);
                        ///afisam discurile

                        deUndeAfisezDreapta[0]=0;
                        panaUndeAfisezDreapta[0]=nr_fisiereDreapta+nr_foldereDreapta;
                        afisare(intreagaDreapta,foldFisExtDreapta, afisStart, 0, deUndeAfisezDreapta[0], panaUndeAfisezDreapta[0], 0, 542,selectie_dreapta,nr_selectii_dreapta);

                    }
                }
            }
        }
        else
        {
            mousePress=false;
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
                    if (intreagaDreapta[0][1]!=':')
                    {
                        char ch[101];
                        setcolor(BLACK);
                        setfillstyle(SOLID_FILL, WHITE);
                        setbkcolor(WHITE);
                        bar3d(760, 738, 1014, 758, 0, 0);
                        line(887, 738, 887, 756);
                        convertSize(ch, foldFisSizeDreapta[viewCounterDreapta]);
                        outtextxy(764, 740, ch);
                        outtextxy(865, 740, "KB");
                        convertDate(ch, foldFisDateDreapta[viewCounterDreapta]);
                        outtextxy(915, 740,ch);
                    }

                }
                else
                {
                    careFereastra=false;
                    setcolor(COLOR(255, 0, 0));
                    rectangle(10, 80,  496, 687);
                    setcolor(DARKGRAY);
                    rectangle(537, 80, 1013, 687);
                    if (intreagaStanga[0][1]!=':')
                    {
                        char ch[101];
                        setcolor(BLACK);
                        setfillstyle(SOLID_FILL, WHITE);
                        setbkcolor(WHITE);
                        bar3d(760, 738, 1014, 758, 0, 0);
                        line(887, 738, 887, 756);
                        convertSize(ch, foldFisSizeStanga[viewCounterStanga]);
                        outtextxy(764, 740, ch);
                        outtextxy(865, 740, "KB");
                        convertDate(ch, foldFisDateStanga[viewCounterStanga]);
                        outtextxy(915, 740,ch);
                    }
                }
            }
        }
        else
        {
            tastaTab=false;
        }
        ///rename
        if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState('R'))
        {
            if (!hotKeyCtrlR)
            {

                hotKeyCtrlR=true;
                if (careFereastra==false)
                {
                   if(nr_fisiereStanga>0)
                    {
                        MessageBoxA(NULL, "Cannot rename multiple files", "Rename",
                                                   MB_ICONERROR | MB_OK);
                    }
                    else{
                    coordXRename=42;
                    lenRenameFileString=0;
                    renameFileString[0]=0;
                    while(kbhit())
                        getch();///curata bufferul de la getch()

                    readimagefile("RenameBoxSized.jpg", 30, 305, 475, 395);
                    setcolor(BLACK);
                    setbkcolor(COLOR(220, 220, 220));
                    outtextxy(40, 330," Rename file or directory: ");
                    setbkcolor(WHITE);
                    loopRename=true;
                    while (loopRename)
                    {
                        setcolor(BLACK);


                        tastaIntrodusaRename=getch();


                        if (lenRenameFileString<41)
                        {

                            ///https://stackoverflow.com/questions/10463201/getch-and-arrow-codes

                            if(tastaIntrodusaRename==0||tastaIntrodusaRename==224)
                            {
                                int c=getch();
                                if(c==72)
                                {
                                    ///sageata sus
                                }
                                else if(c==80)
                                {
                                    ///sageata jos
                                }
                                else if(c==75)
                                {
                                    ///sageata stanga
                                }
                                else if(c==77)
                                {
                                    ///sageata dreapta
                                }
                            }
                            else if (tastaIntrodusaRename>='a' && tastaIntrodusaRename<='z' ||
                                     tastaIntrodusaRename>='A' && tastaIntrodusaRename<='Z' ||
                                     tastaIntrodusaRename>='0' && tastaIntrodusaRename<='9' ||
                                     tastaIntrodusaRename==' ' || tastaIntrodusaRename=='_' ||
                                     tastaIntrodusaRename=='-' || tastaIntrodusaRename==',' ||
                                     tastaIntrodusaRename=='(' || tastaIntrodusaRename==')' ||
                                     tastaIntrodusaRename=='.')
                            {
                                renameFileString[lenRenameFileString]=tastaIntrodusaRename;
                                lenRenameFileString++;
                                renameFileString[lenRenameFileString]=0;
                                outtextxy(coordXRename, 356, renameFileString);
                            }
                        }
                        if (tastaIntrodusaRename==8 && lenRenameFileString>0) ///am introdus backspace
                        {
                            lenRenameFileString--;
                            renameFileString[lenRenameFileString]=0;
                            setcolor(WHITE);
                            setbkcolor(WHITE);
                            setfillstyle(SOLID_FILL, WHITE);
                            bar(coordXRename, 356, 455, 372);
                            setcolor(BLACK);
                            outtextxy(coordXRename, 356, renameFileString);
                        }

                        if (GetAsyncKeyState(VK_RETURN))
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



                            char *destinatie=(char *)malloc(256);
                            char *sursa=(char *)malloc(256);
                            strcpy(destinatie,caleStanga);
                            strcat(destinatie,"\\");
                            strcat(destinatie,renameFileString);
                            strcpy(sursa,caleStanga);
                            strcat(sursa,"\\");
                            strcat(sursa,numefisierfolder);


                            MoveFileExA(sursa, destinatie, MOVEFILE_WRITE_THROUGH);
                            free(destinatie);
                            free(sursa);
                            tastaEnter=true;
                            clear_stanga();
                            reindexare_Dreapta();
                            reindexare_Stanga();
                            loopRename=false;
                            break;
                        }
                        if (GetAsyncKeyState(VK_ESCAPE))
                        {
                            clear_stanga();
                            afisare(intreagaStanga,foldFisExtStanga, foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);
                            loopRename=false;
                            break;
                        }
                    }
                }
            }
                else
                {

                     if(nr_fisiereDreapta>0)
                    {
                        MessageBoxA(NULL, "Cannot rename multiple files", "Rename",
                                                   MB_ICONERROR | MB_OK);
                    }

                    else{
                    coordXRename=564;
                    lenRenameFileString=0;
                    renameFileString[0]=0;
                    while(kbhit())
                        getch();///curata bufferul de la getch()
                    readimagefile("RenameBoxSized.jpg", 552, 305, 997, 395);
                    setcolor(BLACK);
                    setbkcolor(COLOR(220, 220, 220));
                    outtextxy(562, 330," Rename file or directory: ");
                    setbkcolor(WHITE);
                    loopRename=true;
                    while (loopRename)
                    {
                        setcolor(BLACK);
                        tastaIntrodusaRename=(char)getch();

                        if(lenRenameFileString<41)
                        {

                            if(tastaIntrodusaRename==0||tastaIntrodusaRename==224)
                            {
                                int c=getch();
                                if(c==72)
                                {
                                    ///sageata sus
                                }
                                else if(c==80)
                                {
                                    ///sageata jos
                                }
                                else if(c==75)
                                {
                                    ///sageata stanga
                                }
                                else if(c==77)
                                {
                                    ///sageata dreapta
                                }
                            }

                            else  if (    tastaIntrodusaRename>='a' && tastaIntrodusaRename<='z' ||
                                          tastaIntrodusaRename>='A' && tastaIntrodusaRename<='Z' ||
                                          tastaIntrodusaRename>='0' && tastaIntrodusaRename<='9' ||
                                          tastaIntrodusaRename==' ' || tastaIntrodusaRename=='_' ||
                                          tastaIntrodusaRename=='-' || tastaIntrodusaRename==',' ||
                                          tastaIntrodusaRename=='(' || tastaIntrodusaRename==')' ||
                                          tastaIntrodusaRename=='.')
                            {
                                renameFileString[lenRenameFileString]=tastaIntrodusaRename;
                                lenRenameFileString++;
                                renameFileString[lenRenameFileString]=0;
                                outtextxy(coordXRename, 356, renameFileString);
                            }
                        }
                        if (tastaIntrodusaRename==8 && lenRenameFileString>0) ///am introdus backspace
                        {
                            lenRenameFileString--;
                            renameFileString[lenRenameFileString]=0;
                            setcolor(WHITE);
                            setbkcolor(WHITE);
                            setfillstyle(SOLID_FILL, WHITE);
                            bar(coordXRename, 356, 984, 372);
                            setcolor(BLACK);
                            outtextxy(coordXRename, 356, renameFileString);
                        }
                        if (GetAsyncKeyState(VK_RETURN))
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

                            char *destinatie=(char *)malloc(256);
                            char *sursa=(char *)malloc(256);
                            strcpy(destinatie,caleDreapta);
                            strcat(destinatie,"\\");
                            strcat(destinatie,renameFileString);
                            strcpy(sursa,caleDreapta);
                            strcat(sursa,"\\");
                            strcat(sursa,numefisierfolder);


                            MoveFileExA(sursa, destinatie, MOVEFILE_WRITE_THROUGH);
                            free(destinatie);
                            free(sursa);
                            tastaEnter=true;
                            clear_stanga();
                            reindexare_Stanga();
                            reindexare_Dreapta();
                            loopRename=false;
                            break;
                        }
                        if (GetAsyncKeyState(VK_ESCAPE))
                        {
                            clear_dreapta();
                            afisare(intreagaDreapta,foldFisExtDreapta, foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542,selectie_dreapta,nr_selectii_dreapta);
                            loopRename=false;
                            break;
                        }
                    }
                }

                }
            }
            else
                hotKeyCtrlR=false;
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

    initwindow(1024, 768, "MyCommander");
    splashScreen();
    HUD();
    utilizareaAplicatiei();
    closegraph();
    return 0;
}
