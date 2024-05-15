#include "telefonkonyv.h"
#include "oktato.h"
#include "diak.h"

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
        fajl.close();
    }
    else
    {
        std::cout<<"Nem sikerult megnyitni a filet!";
    }

}

void Telefonkonyv::fread(std::string filename)
{
    std::ifstream fajl(filename);
    if (fajl.is_open())
    {
        std::string jelzobit;
        std::string n, b, c, p, m, i;
        std::string sor;
        while (getline(fajl, sor))
        {
            std::stringstream ss(sor);
            std::getline(ss, jelzobit, ',');

            if(jelzobit=="0"){
                std::getline(ss, n, ',');
                std::getline(ss, b, ',');
                std::getline(ss, c, ',');
                std::getline(ss, p, ',');
                std::getline(ss, m, ',');
                Szemely* okt=new Oktato(n,b,c,p,m);
                add(okt);
            }else if(jelzobit=="1"){
                std::getline(ss, n, ',');
                std::getline(ss, b, ',');
                std::getline(ss, c, ',');
                std::getline(ss, p, ',');
                std::getline(ss, i, ',');
                Szemely* dik=new Diak(n,b,c,p,i);
                add(dik);
            }
        }
        fajl.close();
    }
    else
    {
        std::cout<<"Nem sikerult megnyitni a filet!";
    }
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

size_t Telefonkonyv::size()const{return db;}

size_t Telefonkonyv::capacity()const{return meret;}

Szemely* Telefonkonyv::operator[](size_t idx){
    if(idx>=db) throw "EVZ1MK";
    return data[idx];
}
