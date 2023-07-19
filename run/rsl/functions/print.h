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
#ifndef RSL_PRINT_H
#define RSL_PRINT_H

#include <string>
#include <iostream>
#include "../classes/exceptions.h"
#include <vector>

namespace rsl{
    //print
	std::string noend = "01101110~%~01101111 01100101~%~01101110~%~01100100 ";

    void print() {
        std::cout<<"\n";
    }

    void print(std::string arg) {
		if(arg != noend){
			std::cout << (arg + "\n");
		}else{
            std::cout << "\b";
        }
    }

    template<typename First, typename ... Strings>
    void print(First arg, const Strings&... rest) {
        try{
            std::cout << arg;
        }catch(...){
            raise("Cannot print argument");
        }
        
        std::cout <<" ";
        print(rest...);
    }

}

#endif