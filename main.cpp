/**
 * @file main.cpp
 * @brief Tesztprogram a Telefonkonyv osztályhoz.
 */
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


/**
 * @brief A program belépési pontja.
 *
 * @return int A program visszatérési értéke.
 */

 #ifdef CPORTA
int main()
{
        /**
     * @test Telefonkonyv konstruktor tesztelése.
     */
    TEST(telefonkonyv1, konstruktor) {

        Telefonkonyv telk1;
        size_t s=5;
        EXPECT_EQ(s, telk1.capacity());
        size_t d=0;
        EXPECT_EQ(d, telk1.size());

    } END

         /**
     * @test Személy hozzáadása a Telefonkonyv-hez.
     */
        TEST(telefonkonyv2, add) {

        Telefonkonyv telk2;
        size_t s=5;
        EXPECT_EQ(s, telk2.capacity());
        telk2.add(new Oktato("Szabó Dániel","Dani","7624 Pécs Zsolnay Vilmos utca 16.","+36 70 345 6789","+36 60 600 8000"));
        size_t d=1;
        EXPECT_EQ(d, telk2.size());

    } END
        /**
     * @test Telefonkonyv adatok ellenőrzése.
     */
        TEST(telefonkonyv3, data) {

        Telefonkonyv telk3;
        telk3.add(new Diak("Kovács Nikolett","Niki","6722 Szeged Petőfi Sándor sugárút 12.","+36 30 234 5678","Xántus János Gimnázium"));
        std::string nev="Kovács Nikolett";
        EXPECT_EQ(telk3[0]->getNev(), nev);
        std::string bn="Niki";
        EXPECT_EQ(bn, telk3[0]->getBecenev());
        std::string cim="6722 Szeged Petőfi Sándor sugárút 12.";
        EXPECT_EQ(telk3[0]->getCim(), cim);
        std::string pszam="+36 30 234 5678";
        EXPECT_EQ(telk3[0]->getPrivatszam(), pszam);

    } END

        /**
     * @test Telefonkonyv index operátor tesztelése.
     */
        TEST(telefonkonyv4, indexop) {

        Telefonkonyv telk4;
        telk4.add(new Oktato("Kovács Nikolett","Niki","6722 Szeged Petőfi Sándor sugárút 12.","+36 30 234 5678","+36 30 547 5896"));
        size_t si=1;
        EXPECT_EQ(si, telk4.size());
        EXPECT_THROW(telk4[1], const char *);

    } END

        /**
     * @test Telefonkonyv deleteco tesztelése.
     */
        TEST(telefonkonyv5, deleteco) {

        Telefonkonyv telk4;
        telk4.add(new Oktato("Kovács Nikolett","Niki","6722 Szeged Petőfi Sándor sugárút 12.","+36 30 234 5678","+36 30 547 5896"));
        size_t si=1;
        EXPECT_EQ(si, telk4.size());
        telk4.deleteco();
        size_t s2=0;
        EXPECT_EQ(s2, telk4.size());

    } END

        /**
     * @test Telefonkonyv expand tesztelése.
     */
        TEST(telefonkonyv6, expand) {

        Telefonkonyv telk5;
        telk5.add(new Oktato("Kovács Nikolett","Niki","6722 Szeged Petőfi Sándor sugárút 12.","+36 30 234 5678","+36 30 547 5896"));
        telk5.add(new Diak("Horváth Emese","Emi","1037 Budapest Montevideo utca 2.","+36 30 234 5678","Óbudai Gimnázium"));
        telk5.add(new Diak("Varga Márton","Marci","6724 Szeged Kossuth Lajos sgt. 19.","+36 30 456 7890","Óbudai Gimnázium"));
        telk5.add(new Diak("Tóth Brigitta","Brigi","7622 Pécs Király utca 15.","+36 70 234 5678","József Attila Gimnázium"));
        telk5.add(new Oktato("Nagy András","Bandi","1118 Budapest Budaörsi út 10."," +36 20 345 6789","+36 30 123 4567"));
        telk5.add(new Oktato("Farkas Réka","Réki","3300 Eger Dobó István tér 1."," +36 30 123 4567","+36 30 234 5678"));
        size_t si=6;
        EXPECT_EQ(si, telk5.size());
        size_t c=10;
        EXPECT_EQ(c, telk5.capacity());

    } END

         /**
     * @test Telefonkonyv fájlba írás és olvasás tesztelése.
     */
        TEST(telefonkonyv7, file) {

        Telefonkonyv telk6;
        telk6.add(new Oktato("Kovács Nikolett","Niki","6722 Szeged Petőfi Sándor sugárút 12.","+36 30 234 5678","+36 30 547 5896"));
        telk6.add(new Diak("Horváth Emese","Emi","1037 Budapest Montevideo utca 2.","+36 30 234 5678","Óbudai Gimnázium"));
        telk6.fwrite("adatbazis.txt");
        telk6.deleteco();
        telk6.fread("adatbazis.txt");
        telk6.list();
        std::string s="Kovács Nikolett";
        EXPECT_EQ(telk6[0]->getNev(), s);
        size_t si=2;
        EXPECT_EQ(si, telk6.size());

    } END
    return 0;
}

#else
int main(){
    #if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
        setlocale(LC_ALL, "");
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);
    #endif
    Telefonkonyv menustelk;
    menustelk.fread("adatbazis.txt");
    int valasztas;
    do {
        std::cout << "1. Uj kontakt hozzaadasa\n";
        std::cout << "2. Kontaktok listazasa\n";
        std::cout << "3. Osszes torlese\n";
        std::cout << "4. Kilepes\n";
        std::cout << "Valasszon egy opciot: ";
        std::cin >> valasztas;

        switch (valasztas) {
            case 1: {
                std::string nev, becenev, cim, privatszam, munkahelyi, iskola;
                int valasztas2;
                std::cout << "Diakot(1) vagy Oktatot(2) kivan hozzaadni?";
                std::cin >> valasztas2;
                if(valasztas2==1){
                std::cin.ignore(1);
                std::cout << "Adja meg a nevet: ";
                std::getline(std::cin, nev);
                std::cout << "Adja meg a becenevet: ";
                std::getline(std::cin, becenev);
                std::cout << "Adja meg a cimet: ";
                std::getline(std::cin, cim);
                std::cout << "Adja meg a privat szamot: ";
                std::getline(std::cin, privatszam);
                std::cout << "Adja meg az iskolanevet: ";
                std::getline(std::cin, iskola);

                menustelk.add(new Diak(nev,becenev,cim,privatszam,iskola));
                }else{
                std::cin.ignore(1);
                std::cout << "Adja meg a nevet: ";
                std::getline(std::cin, nev);
                std::cout << "Adja meg a becenevet: ";
                std::getline(std::cin, becenev);
                std::cout << "Adja meg a cimet: ";
                std::getline(std::cin, cim);
                std::cout << "Adja meg a privat szamot: ";
                std::getline(std::cin, privatszam);
                std::cout << "Adja meg az munkahelyi szamot: ";
                std::getline(std::cin, munkahelyi);

                menustelk.add(new Oktato(nev,becenev,cim,privatszam,munkahelyi));
                }
                break;
            }
            case 2: {
                menustelk.list();
                break;
            }
            case 3: {
                menustelk.deleteco();
                break;
            }
            case 4: {
                menustelk.fwrite("adatbazis.txt");
                std::cout << "Kilepes...\n";
                break;
            }
            default: {
                std::cout << "Ervenytelen valasztas. Kerjuk, probalja ujra.\n";
                break;
            }
        }
    } while (valasztas != 4);
    return 0;
}


#endif
