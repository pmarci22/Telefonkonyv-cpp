#ifndef SZEMELY_H_INCLUDED
#define SZEMELY_H_INCLUDED

#include <string>
#include"memtrace.h"


/**
 * @class Szemely
 * @brief Absztrakt Személy osztály.
 */
class Szemely{

    std::string nev;
    std::string becenev;
    std::string cim;
    std::string privatszam;

public:
     /**
     * @brief Új Szemely objektum létrehozása.
     *
     * @param n A személy neve
     * @param b A személy beceneve
     * @param c A személy címe
     * @param p A személy privát telefonszáma
     */
    Szemely(std::string n, std::string b, std::string c, std::string p) : nev(n), becenev(b), cim(c), privatszam(p) {}

    /**
     * @brief Virtuális destruktor a Szemely osztályhoz.
     */
    virtual ~Szemely() {}

     /**
     * @brief Absztrakt metódus a személy adatainak megjelenítésére.
     */
    virtual void show()=0;

    /**
     * @brief Absztrakt metódus a személy adatainak fájlba írására.
     *
     * @param of A fájl kimeneti adatfolyama, amelybe írni kell
     */
    virtual void write(std::ofstream& of)=0;

     /**
     * @brief Visszaadja a személy nevét.
     *
     * @return A személy neve
     */
    std::string getNev()const;

    /**
     * @brief Visszaadja a személy becenevét.
     *
     * @return A személy beceneve
     */
    std::string getBecenev()const;

    /**
     * @brief Visszaadja a személy címét.
     *
     * @return A személy címe
     */
    std::string getCim()const;

    /**
     * @brief Visszaadja a személy privát telefonszámát.
     *
     * @return A személy privát telefonszáma
     */
    std::string getPrivatszam()const;
};

#endif // SZEMELY_H_INCLUDED
