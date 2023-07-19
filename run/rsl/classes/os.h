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
};

RUN_CACHER_OS os;
}
#endif