#ifndef RSL_H
#define RSL_H

#include "functions/print.h"
using namespace rsl;
#include <algorithm>
#include <cstring>


namespace rsl{
    #define fn auto
    #define var auto
    #define run int
    template <typename U>
    int toint(U something);

    template<>
    int toint<float>(float something){
      return (int)something;
    }
    template<>
    int toint<std::string>(std::string something){
      return stoi(something);
    }

    template<>
    int toint<bool>(bool something){
        return int(something);
    }
    template<>
    int toint<double>(double something){
        return int(something);
    }
    template<>
    int toint<char>(char something){
        return int(something);
    }

//to string
    template <typename L>
    std::string tostring(L a);

    template<>
    std::string tostring<float>(float a){
      return std::to_string(a);
    }
    template<>
    std::string tostring<int>(int a){
      return std::to_string(a);
    }
    template<>
    std::string tostring<double>(double a){
      return std::to_string(a);
    }
    template<>
    std::string tostring(bool b) {
    return b ? "true" : "false";
    }
    template<>
    std::string tostring(char a){
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
#endif