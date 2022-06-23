#include <iostream>
#include "random.h"

//random number in a range
int rand_range(int min, int max){

    return rand() % (max - min + 1) + min;
}

//uniform random number function
double rand_uni(void){

    return rand()/((double)RAND_MAX);
}
