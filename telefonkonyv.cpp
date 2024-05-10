#include "telefonkonyv.h"

Telefonkonyv::Telefonkonyv(size_t m)
{

    db=0;
    meret=m;
    data=new Szemely*[meret];

}

Telefonkonyv::Telefonkonyv(const Telefonkonyv& masik)
{
    meret=masik.meret;
    db=masik.db;
    data=new Szemely*[meret];
    for(size_t i=0; i<db; db++)
    {
        data[i]=masik.data[i];
    }

}

Telefonkonyv::~Telefonkonyv()
{
    this->deleteco();
    delete[] data;
}

Telefonkonyv& Telefonkonyv::operator=(const Telefonkonyv& masik)
{

    if(this!=&masik)
    {
        delete[] data;
        meret=masik.meret;
        db=masik.db;
        data=new Szemely*[meret];

        for(size_t i=0; i<db; db++)
        {
            data[i]=masik.data[i];
        }

    }
    return *this;
}

void Telefonkonyv::add(Szemely* sz)
{
    if(db<meret)
    {
        data[db]=sz;
        db++;
    }
    else
    {
        expand(sz);
    }
}

void Telefonkonyv::deleteco()
{
    for(size_t i=0; i<db; i++)
    {
        delete data[i];
    }
    db=0;
}

void Telefonkonyv::list()
{
    for(size_t i=0; i<db; i++)
    {
        data[i]->show();
    }
}

void Telefonkonyv::fwrite(std::string filename)
{
    std::ofstream fajl(filename);
    if (fajl.is_open())
    {
        for (size_t i = 0; i < db; i++)
        {
            data[i]->write(fajl);
        }
    }
    else
    {
        std::cout<<"Nem sikerult megnyitni a filet!";
    }

}

void Telefonkonyv::fread(std::string filename)
{

}

void Telefonkonyv::expand(Szemely* sz)
{
    size_t ujmeret=meret+5;
    Szemely** ujdata=new Szemely*[ujmeret];

    for(size_t i=0; i<db; i++)
    {
        ujdata[i]=data[i];
    }
    delete[] data;
    data=ujdata;
    meret=ujmeret;

    data[db]=sz;
    db++;

}
