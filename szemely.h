#ifndef SZEMELY_H_INCLUDED
#define SZEMELY_H_INCLUDED

#include <string>
#include"memtrace.h"


/**
 * @class Szemely
 * @brief Absztrakt Szem�ly oszt�ly.
 */
class Szemely{

    std::string nev;
    std::string becenev;
    std::string cim;
    std::string privatszam;

public:
     /**
     * @brief �j Szemely objektum l�trehoz�sa.
     *
     * @param n A szem�ly neve
     * @param b A szem�ly beceneve
     * @param c A szem�ly c�me
     * @param p A szem�ly priv�t telefonsz�ma
     */
    Szemely(std::string n, std::string b, std::string c, std::string p) : nev(n), becenev(b), cim(c), privatszam(p) {}

    /**
     * @brief Virtu�lis destruktor a Szemely oszt�lyhoz.
     */
    virtual ~Szemely() {}

     /**
     * @brief Absztrakt met�dus a szem�ly adatainak megjelen�t�s�re.
     */
    virtual void show()=0;

    /**
     * @brief Absztrakt met�dus a szem�ly adatainak f�jlba �r�s�ra.
     *
     * @param of A f�jl kimeneti adatfolyama, amelybe �rni kell
     */
    virtual void write(std::ofstream& of)=0;

     /**
     * @brief Visszaadja a szem�ly nev�t.
     *
     * @return A szem�ly neve
     */
    std::string getNev()const;

    /**
     * @brief Visszaadja a szem�ly becenev�t.
     *
     * @return A szem�ly beceneve
     */
    std::string getBecenev()const;

    /**
     * @brief Visszaadja a szem�ly c�m�t.
     *
     * @return A szem�ly c�me
     */
    std::string getCim()const;

    /**
     * @brief Visszaadja a szem�ly priv�t telefonsz�m�t.
     *
     * @return A szem�ly priv�t telefonsz�ma
     */
    std::string getPrivatszam()const;
};

#endif // SZEMELY_H_INCLUDED
