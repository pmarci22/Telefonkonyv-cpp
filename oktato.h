#ifndef OKTATO_H_INCLUDED
#define OKTATO_H_INCLUDED

#include"szemely.h"
#include"memtrace.h"


class Oktato: public Szemely {
    std::string munkahelyiszam;
public:
    Oktato(std::string n, std::string b, std::string c, std::string p, std::string msz): Szemely(n,b,c,p), munkahelyiszam(msz) {}
    ~Oktato() {}
    void show();
};

#endif // OKTATO_H_INCLUDED
