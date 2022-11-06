#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>

namespace rsl{

class r{
    public:

        int randint(int num){

                return std::rand() % num + 0;   

        }
        int randint(int min, int max){

                return std::rand()%(max-min + 1) + min;

        }
        int randint(){

                return std::rand()% INT_MAX;

        }
};

r random;

}

#endif