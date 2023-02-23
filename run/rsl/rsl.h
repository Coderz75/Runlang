#ifndef RSL_H
#define RSL_H

#include "functions/print.h"
using namespace rsl;
#include <algorithm>
#include <cstring>
#include "classes/string.h"
#include "classes/os.h"
#include "classes/random.h"
#include "classes/pointers.h"
#include "classes/exceptions.h"
#include "classes/nums.h"
#ifdef _WIN32
#include <windows.h>
#endif



namespace rsl{
    #define fn auto
    #define var auto
    #define run int

    typedef str string;

    str input(str ask){
      std::cout << "\n";
      std::string x;
      std::cout << ask.v;
      std::getline(std::cin, x);
      return x;
    }
    str input(){
      std::cout << "\n";
      std::string x;
      std::getline(std::cin, x);
      return x;
    }
    #ifdef _WIN32
       str input(std::string ask){
      std::cout << "\n";
      std::string x;
      std::cout << ask;
      std::getline(std::cin, x);
      return x;
    } 
    #endif

    template <typename U>

    #define toint(arg) toints(arg,__LINE__,__FILE__)


    int toints(float something,int line,auto file){
      return (int)something;
    }

    int toints(std::string something,int line,auto file){
      try{
        return stoi(something);
      }catch (...){
        throw exception("Cannot convert '" + something + "'to 'int'",file,line);
      }
    }

    int toints(bool something,int line,auto file){
        return int(something);
    }

    int toints(double something,int line,auto file){
        return int(something);
    }

    int toints(char something,int line,auto file){
        return int(something);
    }

    int toints(str something,int line,auto file){
      return toints(something.v,line,file);
    }

//to string
    template <typename L>
    str tostring(L a);

    template<>
    str tostring<float>(float a){
      return std::to_string(a);
    }
    template<>
    str tostring<int>(int a){
      return std::to_string(a);
    }
    template<>
    str tostring<double>(double a){
      return std::to_string(a);
    }
    template<>
    str tostring(bool b) {
    return b ? std::string("true") : std::string("false");
    }
    template<>
    str tostring(char a){
        char l = a;
        std::string f;
        f.push_back(l);
        return f;
    }
    //To float

    template <typename H>
    float tofloat(H a);

    template<>
    float tofloat(int a){
        return (float) a;
    }

    template<>
    float tofloat(std::string a){
        int x = toint(a);
        return (float) x;
    }

    template<>
    float tofloat(char a){
        int x = toint(a);
        return (float) x;
    }

    template<>
    float tofloat(bool a){
        int x = toint(a);
        return (float) x;
    }
    template<>
    float tofloat(double a){
        return (float) a;
    }
}

#ifdef __MINGW32__
#error "Due to the fact that Mingw has some issues with libraries, we do not support it in runlang"
#endif

#ifdef __GNUC__

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"
#endif


#endif