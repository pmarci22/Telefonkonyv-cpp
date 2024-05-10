#ifndef DIAK_H_INCLUDED
#define DIAK_H_INCLUDED

#include "szemely.h"
#include "memtrace.h"

class Diak: public Szemely{
    std::string iskolanev;
public:
    Diak(std::string n, std::string b, std::string c, std::string p, std::string in): Szemely(n,b,c,p), iskolanev(in) {}
    ~Diak() {}
    void show();
    void write(std::ofstream& of);
};

#endif // DIAK_H_INCLUDED
