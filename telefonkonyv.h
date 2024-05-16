#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED

#include"szemely.h"
#include"memtrace.h"

/**
 * @class Telefonkonyv
 * @brief Telefonkönyv osztály, amely Személy objektumokat tárol.
 */
class Telefonkonyv{

    Szemely** data;
    size_t meret;
    size_t db;

public:
     /**
     * @brief Telefonkonyv osztály konstruktora.
     *
     * @param m A telefonkönyv kezdõ mérete (alapértelmezett: 5)
     */
    Telefonkonyv(size_t m=5);

    /**
     * @brief Telefonkonyv osztály másoló konstruktora.
     *
     * @param masik A másik Telefonkonyv objektum, amelybõl másolunk
     */
    Telefonkonyv(const Telefonkonyv& masik);

    /**
     * @brief Telefonkonyv osztály destruktora.
     */
    ~Telefonkonyv();

    /**
     * @brief Új Személy objektum hozzáadása a telefonkönyvhöz.
     *
     * @param sz A hozzáadandó Személy objektum
     */
    void add(Szemely* sz);

    /**
     * @brief Telefonkonyv kiürítése és az összes Személy objektum törlése.
     */
    void deleteco();

    /**
     * @brief A telefonkönyv tartalmának kilistázása a standard kimenetre.
     */
    void list();

    /**
     * @brief A telefonkönyv adatainak fájlba írása.
     *
     * @param filename A fájl neve, ahová írni kell
     */
    void fwrite(std::string filename);

    /**
     * @brief A telefonkönyv adatainak beolvasása fájlból.
     *
     * @param filename A fájl neve, ahonnan olvasni kell
     */
    void fread(std::string filename);

    /**
     * @brief A telefonkönyv kapacitásának bõvítése.
     *
     * @param sz Az új Személy objektum, amely miatt bõvítünk
     */
    void expand(Szemely* sz);

    /**
     * @brief Telefonkonyv osztály egyenlõség operátora.
     *
     * @param masik A másik Telefonkonyv objektum, amelybõl hozzárendelünk
     * @return A hozzárendelt Telefonkonyv objektum
     */
    Telefonkonyv& operator=(const Telefonkonyv& masik);

     /**
     * @brief Visszaadja a telefonkönyvben tárolt Személy objektumok számát.
     *
     * @return A tárolt Személy objektumok száma
     */
    size_t size()const;

     /**
     * @brief Visszaadja a telefonkönyv kapacitását.
     *
     * @return A telefonkönyv kapacitása
     */
    size_t capacity()const;

    /**
     * @brief Visszaad egy Személy objektumot az adott indexen.
     *
     * @param idx Az index, amelyen a Személy objektum található
     * @return A Személy objektum az adott indexen (Hibás index esetén kivételt dob!)
     */
    Szemely* operator[](size_t idx);
};

#endif // TELEFONKONYV_H_INCLUDED
