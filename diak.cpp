#include "diak.h"

void Diak::show(){
    std::cout<<getNev()<<" - "<<getBecenev()<<" - "<<getCim()<<" - "<<getPrivatszam()<<" - "<<iskolanev<<std::endl;
}

void Diak::write(std::ofstream& of){
    of<<"1"<<","<<getNev()<<","<<getBecenev()<<","<<getCim()<<","<<getPrivatszam()<<","<<iskolanev<<std::endl;
}
