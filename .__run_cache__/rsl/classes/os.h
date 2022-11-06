#ifndef OS_H
#define OS_H
#ifdef _WIN32
#include "./rsl.h"
#else
#include "../rsl.h"
#endif
namespace rsl{
class o{
    public:
        void system(str cmd){
            std::system(cmd.c_str());
        }
        void system(std::string cmd){
            std::system(cmd.c_str());
        }
};

o os;
}
#endif