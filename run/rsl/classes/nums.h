#ifndef RSL_NUMS_H
#define RSL_NUMS_H

#include <iostream>
#include <string>
#include <stack>
#include "../rsl.h"

class num{
    public:
        std::string number = "";
        // Overloading
        friend std::ostream& operator<<(std::ostream& os, const num& e); //  << 
        /*
        num operator*(const num x){ //                              *
            int carry = 0;
            std::string y = number;
            for (int i = y.length() - 1; i >= 0; i--){
                for (int e = x.number.length(); e >= 0; e--){

                }
            }
            if (carry){
                y = std::to_string(carry) + y;
            }
            return num(y);
        }
        */
        num operator+(const num x){ // ADDITION
            int carry = 0;
            std::string out = "";
            std::string my_num = number;
            std::string other_num = x.number;
            if (my_num.length() > x.number.length()){
                int offset = number.length() - x.number.length();
                for(int i = my_num.length() - 1; i > 0; i--){
                    int e = carry;
                    if (i - offset >= 0)
                        e += (my_num[i] - '0') + (x.number[i - offset] - '0');
                    else 
                        e += (my_num[i] - '0');
                    if (e > 10){
                        e %=10;
                        carry = 1;
                    }else{
                        carry = 0;
                    }
                    out.insert(0, std::to_string(e));
                }
            }else{
                int offset = x.number.length() - number.length();
                for(int i = x.number.length() - 1; i >= 0; i--){
                    int e = carry;
                    if (i - offset >= 0)
                        e += (x.number[i] - '0') + (number[i - offset] - '0');
                    else 
                        e += (x.number[i] - '0');
                    if (e > 10){
                        e %=10;
                        carry = 1;
                    }else{
                        carry = 0;
                    }
                    out.insert(0, std::to_string(e));
                }
            }
            return num(out);
        }
        num operator-(const num x){
            std::string out = "";
            if (number.length() > x.number.length()){
                int offset = number.length() - x.number.length();
                for(int i = number.length() - 1; i > 0; i--){
                    int e = 0;
                    if((number[i] - '0') - (x.number[i - offset] - '0') > 0)
                        e = (number[i] - '0') - (x.number[i - offset] - '0');
                    else{
                        int z = 0;
                        int ie = i;
                        while (z != 0){

                        }
                    }
                    
                    out.insert(0, std::to_string(e));
                }
            }else{
            }
            return num(out);
        }

        //Constructors
        num(long long x){
            long long z = x;
            std::string signValue = "";
            if (z < 0) {
                signValue = "-";
                z = -z;
            }
            std::stack<char> stringStack;
            while (z > 0) {

                //add last digit to stack after converting it to char    
                stringStack.push(z % 10 + '0');  
                z /= 10; // remove last digit
            }
            number += signValue;
            while (!stringStack.empty()) {
                number += stringStack.top();
                stringStack.pop();
            }
        }
        num(rsl::str v){
            for (int i = 0; i < v.v.size(); i++){
                try{
                    if (v.v[i] != '.' and (v.v[i] != '-' and i == 0))
                    std::stoi(std::string(1,v.v[i]));    
                }catch (...){
                    raise("Invalid string to num conversion.");
                }
            }
            number = v.v;
        }
        
};

std::ostream& operator<<(std::ostream& os, const num& e)
{
    os << e.number;
    return os;
}

#endif