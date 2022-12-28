#ifndef RSL_RANDOM_H
#define RSL_RANDOM_H
#include <iostream>
#ifndef _WIN32
#include <climits>
#endif
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