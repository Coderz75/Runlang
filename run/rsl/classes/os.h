#ifndef RSL_OS_H
#define RSL_OS_H

#include "../rsl.h"

namespace rsl{
class RUN_CACHER_OS{
    public:
        RUN_CACHER_OS(){
            std::ios_base::sync_with_stdio(false);
        }
        void exec(str cmd){
            std::system(cmd.c_str());
        }
        void exec(std::string cmd){
            std::system(cmd.c_str());
        }
};

RUN_CACHER_OS os;
}
#endif