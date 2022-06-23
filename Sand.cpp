
#include <iostream>
#include "Sand.h"

Sand::Sand(int N){
    grains=N;
}

Sand::~Sand(){
    
   // std::cout<<"Objet destroyed!"<<std::endl;  

}

void Sand::Print(void){
    //std::cout<<"The number of grains is: "<<grains<<std::endl;
    std::cout<<grains<<" ";
}
//add grain
void Sand::add_grain(void){
    grains=grains+1;
}
//remove grains given a value of zc
void Sand::rem_grain(int zc){
    grains=grains-zc;
}
//set the number of grains
void Sand::set_grains(int N){
    grains=N;
}
//get the number of grains
int Sand::get_grains(void){
    return grains;
}
