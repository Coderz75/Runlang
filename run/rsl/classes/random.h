#ifndef RSL_RANDOM_H
#define RSL_RANDOM_H
#include <iostream>
#ifndef _WIN32
#include <climits>
#endif
namespace rsl{

class RUN_CACHER_RANDOM{
    public:

        int rint(int num){

                return std::rand() % num + 0;   

        }
        int rint(int min, int max){

                return std::rand()%(max-min + 1) + min;

        }
        int rint(){

                return std::rand()% INT_MAX;
        }
};

RUN_CACHER_RANDOM random;

}

#endif