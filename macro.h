#define reindexare_Dreapta() \
    viewCounterDreapta=0;\
    reindex(caleDreapta,foldereDreapta,fisiereDreapta,nr_fisiereDreapta,nr_foldereDreapta);\
    nivStivaDreapta=0;\
    deUndeAfisezDreapta[nivStivaDreapta]=0;\
    nrFoldereFisiereDreapta=nr_fisiereDreapta+nr_foldereDreapta;\
    initializareVectorDeNumeFoldereFisiere(intreagaDreapta,foldereDreapta,fisiereDreapta,nr_foldereDreapta,nr_fisiereDreapta);\
    clear_dreapta();\
    if(nrFoldereFisiereDreapta>29) panaUndeAfisezDreapta[nivStivaDreapta]=29;\
    else panaUndeAfisezDreapta[nivStivaDreapta]=nrFoldereFisiereDreapta;\
    afisare(intreagaDreapta,deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542)


 #define reindexare_Stanga()\
    viewCounterStanga = 0;\
    reindex(caleStanga,foldereStanga,fisiereStanga,nr_fisiereStanga,nr_foldereStanga);\
    nivStivaStanga=0;\
    deUndeAfisezStanga[nivStivaStanga]=0;\
    nrFoldereFisiereStanga=nr_fisiereStanga+nr_foldereStanga;\
    initializareVectorDeNumeFoldereFisiere(intreagaStanga,foldereStanga,fisiereStanga,nr_foldereStanga,nr_fisiereStanga);\
    clear_stanga();\
    if(nrFoldereFisiereStanga>29) panaUndeAfisezStanga[nivStivaStanga]=29;\
    else panaUndeAfisezStanga[nivStivaStanga]=nrFoldereFisiereStanga;\
    afisare(intreagaStanga, deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga,15)




