#ifndef DIAK_H_INCLUDED
#define DIAK_H_INCLUDED

#include "szemely.h"
#include "memtrace.h"

/**
 * @class Diak
 * @brief Diák osztály, amely a Szemely osztályból öröklődik.
 */
class Diak: public Szemely{
    std::string iskolanev;
public:
    /**
     * @brief Diak konstruktor.
     *
     * @param n A diák neve
     * @param b A diák beceneve
     * @param c A diák címe
     * @param p A diák privát telefonszáma
     * @param in Az iskola neve
     */
    Diak(std::string n, std::string b, std::string c, std::string p, std::string in): Szemely(n,b,c,p), iskolanev(in) {}

    /**
     * @brief Diak osztály destruktora.
     */
    ~Diak() {}

    /**
     * @brief Megjeleníti a diák adatait a standard kimeneten.
     */
    void show();

    /**
     * @brief A diák adatait fájlba írja.
     *
     * @param of A fájl kimeneti adatfolyama, amelybe írni kell.
     */
    void write(std::ofstream& of);
};

#endif // DIAK_H_INCLUDED
