#include <iostream>
#include "gtest_lite.h"
#include "szemely.h"
#include "telefonkonyv.h"
#include "oktato.h"
#include "diak.h"
#include "memtrace.h"



int main()
{
    Telefonkonyv telk;
    telk.add(new Diak("asd","asd","asd","asd","asd"));
    telk.add(new Oktato("asd2","asd2","asd2","asd2","asd2"));
    telk.add(new Oktato("asd3","asd3","asd3","asd3","asd3"));
    telk.add(new Oktato("asd3","asd3","asd3","asd3","asd3"));
    telk.add(new Oktato("asd3","asd3","asd3","asd3","asd3"));
    telk.add(new Diak("asd3","asd3","asd3","asd3","asd3"));

    telk.list();
    return 0;
}
