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