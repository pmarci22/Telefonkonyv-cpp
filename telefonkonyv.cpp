#include "telefonkonyv.h"

Telefonkonyv::Telefonkonyv(size_t m=5){
    db=0;
    meret=m;
    data=new Szemely*[meret];
}

void Telefonkonyv::add(Szemely* sz){
    if(db<meret){
        data[db]=sz;
        db++;
    }
    else{
        expand(sz);
    }
}

void Telefonkonyv::deleteco(){

}

void Telefonkonyv::list(){

}

void Telefonkonyv::fwrite(std::string filename){

}

void Telefonkonyv::fread(std::string filename){

}

void Telefonkonyv::expand(Szemely* sz){

}
