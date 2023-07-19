/*
    Runlang. A programming language that brings the ease of python to the speed to c++
    Copyright (C) 2023  Nuaym Syed

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/
#ifndef RSL_RANDOM_H
#define RSL_RANDOM_H
#include <iostream>
#include <time.h>
#include <cmath>
#ifndef _WIN32
#include <climits>
#endif
namespace rsl{

class RUN_CACHER_RANDOM{
    public:
        RUN_CACHER_RANDOM(){
                srand(time(0));
        }
        int rint(int min, int max){
                return std::rand()%(max-min + 1) + min;
        }
        int rint(){
                return std::rand()% INT_MAX;
        }
        float rfloat(int precision = 2){
                auto max = INT_MAX - 1;
                auto min = INT_MIN + 1;
                auto e = std::rand()%(max-(min) + 1) + min;
                auto f = e/precision;
                return f;
        }
        float rfloat(int min, int max, int precision = 2){
                auto m = pow(10, precision);
                max *= m;
                min *= m;
                auto e = std::rand()%(max-(min) + 1) + min;
                auto f = e/m;
                return f;
        }
};

RUN_CACHER_RANDOM Random;

}

#endif