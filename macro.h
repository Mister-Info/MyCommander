#define reindexare_Dreapta() \
    viewCounterDreapta=0;\
    reindex(caleDreapta,foldereDreapta,fisiereDreapta,extensieFoldereDreapta,extensieFisiereDreapta,marimeFoldereDreapta,marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_fisiereDreapta,nr_foldereDreapta);\
    nivStivaDreapta=0;\
    deUndeAfisezDreapta[nivStivaDreapta]=0;\
    nrFoldereFisiereDreapta=nr_fisiereDreapta+nr_foldereDreapta;\
    initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldFisExtDreapta,foldFisSizeDreapta, foldFisDateDreapta,foldereDreapta,fisiereDreapta, extensieFoldereDreapta, extensieFisiereDreapta, marimeFoldereDreapta, marimeFisiereDreapta,candAfostCreatFoldereDreapta,candAfostCreatFisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);\
    clear_dreapta();\
    if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;\
    else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;\
    afisare(intreagaDreapta, foldFisExtDreapta, foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542,selectie_dreapta, nr_selectii_dreapta);



#define reindexare_Stanga()\
    viewCounterStanga = 0;\
        reindex(caleStanga,foldereStanga,fisiereStanga,extensieFoldereStanga, extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga, candAfostCreatFisiereStanga,nr_fisiereStanga,nr_foldereStanga);\
    nivStivaStanga=0;\
    deUndeAfisezStanga[nivStivaStanga]=0;\
    nrFoldereFisiereStanga=nr_fisiereStanga+nr_foldereStanga;\
    initializareVectorDeNumeFoldereFisiere(intreagaStanga, foldFisExtStanga,foldFisSizeStanga, foldFisDateStanga,foldereStanga,fisiereStanga, extensieFoldereStanga, extensieFisiereStanga, marimeFoldereStanga, marimeFisiereStanga,candAfostCreatFoldereStanga,candAfostCreatFisiereStanga,nr_foldereStanga,nr_fisiereStanga);\
    clear_stanga();\
    if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;\
    else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;\
    afisare(intreagaStanga, foldFisExtStanga, foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15,selectie_stanga,nr_selectii_stanga);




#define  copiereStanga(counter)\
    char *numefisierfolder;\
                    if(counter<nr_foldereStanga)\
                    {\
                        numefisierfolder=foldereStanga[counter];\
                    }\
\
                    else\
                    {\
                        numefisierfolder=fisiereStanga[counter-nr_foldereStanga];\
                    }\
                    char *folder= (char*)malloc(256);\
                    strcpy(folder,caleStanga);\
                    bool ok=true;\
                    strcat(folder,"\\");\
                    strcat(folder,numefisierfolder);\
\
                    if(ok)\
                    {\
                        copierefoldere(folder, caleDreapta);\
                        reindexare_Dreapta();\
                        reindexare_Stanga();\
                    }\
                    free(folder);



#define  copiereDreapta(counter)\
 char *numefisierfolder;\
            if(counter<nr_foldereDreapta)\
                    {\
                        numefisierfolder=foldereDreapta[counter];\
                    }\
\
                    else\
                    {\
                        numefisierfolder=fisiereDreapta[counter-nr_foldereDreapta];\
                    }\
                    char *folder= (char*)malloc(256);\
                    strcpy(folder,caleDreapta);\
                    bool ok=true;\
                    strcat(folder,"\\");\
                    strcat(folder,numefisierfolder);\
                    if(ok)\
                    {\
                        copierefoldere(folder, caleStanga);\
                        reindexare_Stanga();\
                        reindexare_Dreapta();\
                    }\
                    free(folder);




