#ifndef RSL_OS_H
#define RSL_OS_H

#include "../rsl.h"

namespace rsl{
class o{
    public:
        o(){
            std::ios_base::sync_with_stdio(false);
        }
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