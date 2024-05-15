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

    TEST(telefonkonyv, konstruktor) {

        Telefonkonyv telk1;
        size_t s=5;
        EXPECT_EQ(s, telk1.capacity());
        size_t d=0;
        EXPECT_EQ(d, telk1.size());

    } END

        TEST(telefonkonyv, add) {

        Telefonkonyv telk2;
        size_t s=5;
        EXPECT_EQ(s, telk2.capacity());
        telk2.add(new Oktato("Szabó Dániel","Dani","7624 Pécs Zsolnay Vilmos utca 16.","+36 70 345 6789","+36 60 600 8000"));
        size_t d=1;
        EXPECT_EQ(d, telk2.size());

    } END

        TEST(telefonkonyv, data) {

        Telefonkonyv telk3;
        telk3.add(new Diak("Kovács Nikolett","Niki","6722 Szeged Petőfi Sándor sugárút 12.","+36 30 234 5678","Xántus János Gimnázium"));
        std::string nev=telk3[0]->getNev();
        EXPECT_EQ("Kovács Nikolett", nev);
        std::string bn=telk3[0]->getBecenev();
        EXPECT_EQ("Niki", bn);
        std::string cim=telk3[0]->getCim();
        EXPECT_EQ("6722 Szeged Petőfi Sándor sugárút 12.", cim);
        std::string pszam=telk3[0]->getPrivatszam();
        EXPECT_EQ("+36 30 234 5678", pszam);

    } END

        TEST(telefonkonyv, indexop) {

        Telefonkonyv telk4;
        telk4.add(new Oktato("Kovács Nikolett","Niki","6722 Szeged Petőfi Sándor sugárút 12.","+36 30 234 5678","+36 30 547 5896"));
        size_t si=1;
        EXPECT_EQ(si, telk4.size());
        EXPECT_THROW(telk4[1], const char *);

    } END
    return 0;
}
