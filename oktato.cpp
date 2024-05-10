#include "oktato.h"

void Oktato::show(){
    std::cout<<getNev()<<" - "<<getBecenev()<<" - "<<getCim()<<" - "<<getPrivatszam()<<" - "<<munkahelyiszam<<std::endl;
}

void Oktato::write(std::ofstream& of){
    of<<"0"<<","<<getNev()<<","<<getBecenev()<<","<<getCim()<<","<<getPrivatszam()<<","<<munkahelyiszam<<std::endl;
}
