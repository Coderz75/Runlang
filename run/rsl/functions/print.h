#ifndef RSL_PRINT_H
#define RSL_PRINT_H

#include <string>
#include <iostream>
#include "../rsl.h"
#include <vector>

namespace rsl{
    //print
	std::string noend = "01101110~%~01101111 01100101~%~01101110~%~01100100 ";

    void print() {
        std::cout<<std::endl;
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
        std::cout << arg;
        std::cout <<" ";
        print(rest...);
    }

}

#endif