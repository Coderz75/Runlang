#ifndef PRINT_H
#define PRINT_H

#include <string>
#include <iostream>
#include "../rsl.h"
#include <vector>

namespace rsl{
    //print
	std::string noend = "01101110~%~01101111 01100101~%~01101110~%~01100100 ";


    
    static void prints(std::string a, std::string x=""){
        std::cout << a;
        std::cout << x;
    }
    static void prints(float a, std::string x=""){
        std::cout << std::to_string(a);
        std::cout << x;
    }


    static void prints(int a, std::string x=""){
        std::cout << std::to_string(a);
        std::cout << x;
    }

    static void prints(char const* a, std::string x=""){
        std::string l = a; 
        std::cout << l;
        std::cout << x;
    }


    static void prints(bool a, std::string x = ""){
        std::cout << std::to_string(a);
        std::cout << x;
    }


    static void prints(){
        std::cout << "\n";
    }
    
	template <typename X>
    static void prints(std::vector<X> a, std::string x=""){
		std::cout << "{";
        for(int i=0; i < a.size(); i++){
			prints(a.at(i));
			if(i+1 < a.size()) std::cout<< ", ";
		}
		std::cout << "}";
	}



    void print() {
        std::cout<<std::endl;
    }

    void print(std::string arg) {
		if(arg != noend){
			prints(arg + "\n");
		}else{
            std::cout << "\b";
        }
    }

    template<typename First, typename ... Strings>
    void print(First arg, const Strings&... rest) {
        prints(arg);
        prints(" ");
        print(rest...);
    }

}

#endif