#ifndef DIAK_H_INCLUDED
#define DIAK_H_INCLUDED

#include "szemely.h"
#include "memtrace.h"

/**
 * @class Diak
 * @brief Di�k oszt�ly, amely a Szemely oszt�lyb�l �r�kl�dik.
 */
class Diak: public Szemely{
    std::string iskolanev;
public:
    /**
     * @brief Diak konstruktor.
     *
     * @param n A di�k neve
     * @param b A di�k beceneve
     * @param c A di�k c�me
     * @param p A di�k priv�t telefonsz�ma
     * @param in Az iskola neve
     */
    Diak(std::string n, std::string b, std::string c, std::string p, std::string in): Szemely(n,b,c,p), iskolanev(in) {}

    /**
     * @brief Diak oszt�ly destruktora.
     */
    ~Diak() {}

    /**
     * @brief Megjelen�ti a di�k adatait a standard kimeneten.
     */
    void show();

    /**
     * @brief A di�k adatait f�jlba �rja.
     *
     * @param of A f�jl kimeneti adatfolyama, amelybe �rni kell.
     */
    void write(std::ofstream& of);
};

#endif // DIAK_H_INCLUDED
