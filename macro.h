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
    afisare(intreagaDreapta, foldFisExtDreapta, foldFisDateDreapta[viewCounterDreapta], foldFisSizeDreapta[viewCounterDreapta], deUndeAfisezDreapta[nivStivaDreapta], panaUndeAfisezDreapta[nivStivaDreapta], viewCounterDreapta, 542);



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
    afisare(intreagaStanga, foldFisExtStanga, foldFisDateStanga[viewCounterStanga], foldFisSizeStanga[viewCounterStanga], deUndeAfisezStanga[nivStivaStanga], panaUndeAfisezStanga[nivStivaStanga], viewCounterStanga, 15);




