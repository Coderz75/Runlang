#ifndef OS_H
#define OS_H
#include "./rsl.h"
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