#ifndef OKTATO_H_INCLUDED
#define OKTATO_H_INCLUDED

#include"szemely.h"
#include"memtrace.h"

/**
 * @class Oktato
 * @brief Oktató osztály, amely a Szemely osztályból öröklõdik.
 */
class Oktato: public Szemely {
    std::string munkahelyiszam;
public:
        /**
     * @brief Oktato osztály konstruktora
     *
     * @param n Az Oktato neve
     * @param b Az Oktato beceneve
     * @param c Az Oktato címe
     * @param p Az Oktato privát telefonszáma
     * @param msz Az Oktato munkahelyi telefonszáma
     */
    Oktato(std::string n, std::string b, std::string c, std::string p, std::string msz): Szemely(n,b,c,p), munkahelyiszam(msz) {}

    /**
     * @brief Oktato osztály destruktora.
     */
    ~Oktato() {}

     /**
     * @brief Megjeleníti az oktató adatait a standard kimeneten.
     */
    void show();

    /**
     * @brief Az oktató adatait fájlba írja.
     *
     * @param of A fájl kimeneti adatfolyama, amelybe írni kell
     */
    void write(std::ofstream& of);
};

#endif // OKTATO_H_INCLUDED
