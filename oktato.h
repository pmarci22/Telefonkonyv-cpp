#ifndef OKTATO_H_INCLUDED
#define OKTATO_H_INCLUDED

#include"szemely.h"
#include"memtrace.h"


class Oktato: public Szemely {
    std::string munkahelyiszam;
public:
    void show();
};

#endif // OKTATO_H_INCLUDED
