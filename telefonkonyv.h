#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED

#include"szemely.h"
#include"memtrace.h"

/**
 * @class Telefonkonyv
 * @brief Telefonk�nyv oszt�ly, amely Szem�ly objektumokat t�rol.
 */
class Telefonkonyv{

    Szemely** data;
    size_t meret;
    size_t db;

public:
     /**
     * @brief Telefonkonyv oszt�ly konstruktora.
     *
     * @param m A telefonk�nyv kezd� m�rete (alap�rtelmezett: 5)
     */
    Telefonkonyv(size_t m=5);

    /**
     * @brief Telefonkonyv oszt�ly m�sol� konstruktora.
     *
     * @param masik A m�sik Telefonkonyv objektum, amelyb�l m�solunk
     */
    Telefonkonyv(const Telefonkonyv& masik);

    /**
     * @brief Telefonkonyv oszt�ly destruktora.
     */
    ~Telefonkonyv();

    /**
     * @brief �j Szem�ly objektum hozz�ad�sa a telefonk�nyvh�z.
     *
     * @param sz A hozz�adand� Szem�ly objektum
     */
    void add(Szemely* sz);

    /**
     * @brief Telefonkonyv ki�r�t�se �s az �sszes Szem�ly objektum t�rl�se.
     */
    void deleteco();

    /**
     * @brief A telefonk�nyv tartalm�nak kilist�z�sa a standard kimenetre.
     */
    void list();

    /**
     * @brief A telefonk�nyv adatainak f�jlba �r�sa.
     *
     * @param filename A f�jl neve, ahov� �rni kell
     */
    void fwrite(std::string filename);

    /**
     * @brief A telefonk�nyv adatainak beolvas�sa f�jlb�l.
     *
     * @param filename A f�jl neve, ahonnan olvasni kell
     */
    void fread(std::string filename);

    /**
     * @brief A telefonk�nyv kapacit�s�nak b�v�t�se.
     *
     * @param sz Az �j Szem�ly objektum, amely miatt b�v�t�nk
     */
    void expand(Szemely* sz);

    /**
     * @brief Telefonkonyv oszt�ly egyenl�s�g oper�tora.
     *
     * @param masik A m�sik Telefonkonyv objektum, amelyb�l hozz�rendel�nk
     * @return A hozz�rendelt Telefonkonyv objektum
     */
    Telefonkonyv& operator=(const Telefonkonyv& masik);

     /**
     * @brief Visszaadja a telefonk�nyvben t�rolt Szem�ly objektumok sz�m�t.
     *
     * @return A t�rolt Szem�ly objektumok sz�ma
     */
    size_t size()const;

     /**
     * @brief Visszaadja a telefonk�nyv kapacit�s�t.
     *
     * @return A telefonk�nyv kapacit�sa
     */
    size_t capacity()const;

    /**
     * @brief Visszaad egy Szem�ly objektumot az adott indexen.
     *
     * @param idx Az index, amelyen a Szem�ly objektum tal�lhat�
     * @return A Szem�ly objektum az adott indexen (Hib�s index eset�n kiv�telt dob!)
     */
    Szemely* operator[](size_t idx);
};

#endif // TELEFONKONYV_H_INCLUDED
