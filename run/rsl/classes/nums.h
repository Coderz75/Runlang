#ifndef RSL_NUMS_H
#define RSL_NUMS_H

#include <iostream>
#include <string>
#include <stack>
#include "../rsl.h"

class num{
    private:
        std::string number = "";
    public:

        // Overloading
        friend std::ostream& operator<<(std::ostream& os, const num& e); //  << 
        
        num operator*(const long double& x){ //                              *
            int carry = 0;
            std::string y = number;
            for (int i = y.length() - 1; i >= 0; i--){
                int digit = y[i] - '0';
                int res = digit * x + carry;
                y[i] = char(48 + (res % 10)); 
                carry = std::ceil(res / 10);
            }

            if (carry){
                y = std::to_string(carry) + y;
            }
            return num(y);
            
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
                    if (v.v[i] != '.' and v.v[i] != '-')
                    std::stoi(v);                   
                }catch (...){
                    raise("Invalid string to int conversion.");
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