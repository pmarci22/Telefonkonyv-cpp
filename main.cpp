#include <iostream>
#include <locale>
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#include <windows.h>
#endif
#include "gtest_lite.h"
#include "szemely.h"
#include "telefonkonyv.h"
#include "oktato.h"
#include "diak.h"
#include "memtrace.h"



int main()
{

    #if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);
        setlocale(LC_ALL, "");
    #endif

    Telefonkonyv telk;
    telk.add(new Diak("Gábor László","Gabi","1117 Budapest Gárdonyi tér 3.","+36 20 123 4567","Xántus János Gimnázium"));

    telk.add(new Oktato("Szabó Dániel","Dani","7624 Pécs Zsolnay Vilmos utca 16.","+36 70 345 6789","+36 60 600 8000"));

    telk.fwrite("adatbazis.txt");
    telk.deleteco();

    telk.fread("adatbazis.txt");
    telk.list();
    return 0;
}
