#ifndef SZEMELY_H_INCLUDED
#define SZEMELY_H_INCLUDED

#include <string>
#include"memtrace.h"

class Szemely{

    std::string nev;
    std::string becenev;
    std::string cim;
    std::string privatszam;

public:
    Szemely(std::string n, std::string b, std::string c, std::string p) : nev(n), becenev(b), cim(c), privatszam(p) {}
    virtual ~Szemely() {}
    virtual void show()=0;
    std::string getNev()const;
    std::string getBecenev()const;
    std::string getCim()const;
    std::string getPrivatszam()const;
};

#endif // SZEMELY_H_INCLUDED
