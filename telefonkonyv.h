#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED

#include"szemely.h"
#include"memtrace.h"

class Telefonkonyv{

    Szemely** data;
    size_t meret;
    size_t db;

public:
    Telefonkonyv(size_t m=5);
    Telefonkonyv(const Telefonkonyv& masik);
    ~Telefonkonyv();
    void add(Szemely* sz);
    void deleteco();
    void list();
    void fwrite(std::string filename);
    void fread(std::string filename);
    void expand(Szemely* sz);
    Telefonkonyv& operator=(const Telefonkonyv& masik);
    size_t size()const;
    size_t capacity()const;
    Szemely* operator[](size_t idx);
};

#endif // TELEFONKONYV_H_INCLUDED
