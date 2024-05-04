#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED

#include"szemely.h"
#include"memtrace.h"

class Telefonkonyv{

    Szemely** data;
    size_t meret;
    size_t db;

public:
    Telefonkonyv(size_t m);
    void add(Szemely* sz);
    void deleteco();
    void list();
    void fwrite(std::string filename);
    void fread(std::string filename);
    void expand(Szemely* sz);
};

#endif // TELEFONKONYV_H_INCLUDED
