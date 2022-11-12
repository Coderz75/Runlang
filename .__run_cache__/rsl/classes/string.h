#ifndef STRING_H
#define STRING_H
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

namespace rsl{

    class str{
            public:
                //Operator overloading
                friend std::ostream& operator<<(std::ostream& os, const str& string);
                operator std::string () const {
                    return v;
                }
                str operator+(const str& string) { //Plus: str + str
                    str new_str;
                    new_str.v = this->v + string.v;
                    return new_str;
                }
                str operator+(const std::string& string) { //Plus: str + std::string
                    str new_str;
                    new_str.v = this->v + string;
                    return new_str;
                }       
                bool operator==(const str& string) {
                    if(this->v == string.v){
                        return true;
                    }else{
                        return false;
                    }
                }
                bool operator==(const std::string& string) { //!= Bool
                    if(this->v == string){
                        return true;
                    }else{
                        return false;
                    }
                }
                bool operator!=(const str& string) {
                    if(this->v != string.v){
                        return true;
                    }else{
                        return false;
                    }
                }
                bool operator!=(const std::string& string) { //!= Bool
                    if(this->v != string){
                        return true;
                    }else{
                        return false;
                    }
                }

                //Constructors
                std::string v;
                str(std::string s){
                    v = s;
                }
                str(char* a){
                    v = a;
                }
                str(){
                    v = "";
                }
   
                //Actual stuff
                str upper(){
                    std::string data = v;
                    std::for_each(data.begin(), data.end(), [](char & c){
                        c = ::toupper(c);
                    });
                    return data;
                }
                str lower(){
                    std::string data = v;
                    std::for_each(data.begin(), data.end(), [](char & c){
                        c = ::tolower(c);
                    });
                    return data;
                }
                std::vector<std::string>  split(std::string x = " ", int m = false){
                    std::vector<std::string> so {};
                    std::string* s;
                    s = new std::string;
                    *s = v;
                    std::string* delim;
                    delim = new std::string;
                    *delim = x;
                    auto start = 0;
                    auto end = (*s).find(*delim);
                    if (m != false){

                        int it = 0;
                        while (end != std::string::npos && it < m)
                        {
                            std::string m = (*s).substr(start, end - start);
                            so.push_back(m);
                            start = end + (*delim).length();
                            end = (*s).find(*delim, start);
                            it = it+1;
                        }
                    }else{
                        while (end != std::string::npos)
                        {
                            std::string m = (*s).substr(start, end - start);
                            so.push_back(m);
                            start = end + (*delim).length();
                            end = (*s).find(*delim, start);
                        }
                

                
                    so.push_back((*s).substr(start, end));
                    delete delim;
                    delete s;
                    return so;
                  }
                return{v};
                }
                str capitilize(){
                    std::string a = v;
                    a[0] = toupper(a[0]); 
                    return a;
                }
                bool isupper(){
                    std::string* m;
                    m = new std::string;
                    *m = v;
                    for (int i = 0; i < (*m).length(); i++) {
                      if(::isupper((*m)[i])){  
                      }else{
                          delete m;
                          return false;
                      }
                    }
                    delete m;
                    return true;
                }
                bool islower(){
                    std::string* m;
                    m = new std::string;
                    *m = v;
                    for (int i = 0; i < (*m).length(); i++) {
                      if(::islower((*m)[i])){  
                      }else{
                          delete m;
                          return false;
                      }
                    }
                    delete m;
                    return true;
                }

                str center(int s, std::string a = " "){
                    int* spaces ;
                    spaces = new int;
                    *spaces = s - v.length();
                    *spaces = *spaces/2;
                    std::string returnval = v;
                    for(int i = 0; i<*spaces; i++){
                        returnval = a + returnval;
                    }
                    for(int i = 0; i<*spaces; i++){
                        returnval = returnval+a;
                    }
                    delete spaces;
                    return returnval;
                    
                }
                str zfill(int length){
                    std::string l = v;
                    int zeros = length - v.length();
                    for(int i = 0; i< zeros; i++){
                        l = "0" + l; 
                    }
                    return l;
                }
                str swapcase(){
                    std::string a = v;
                    for(int i = 0; i < a.length(); i++){
                        if(::islower(a[i])){
                            a[i] = toupper(a[i]);
                        }else{
                            a[i] = tolower(a[i]);
                        }
                    }
                    return a;
                }
                bool startswith(std::string a, int b = 0, int c = 0){
                    std::string l = v;
                    int x = c;
                    if (x== 0){
                        x = a.length();
                    }
                    for (int i = 0; i< a.length(); i++){
                        if (a[i+b] != l[i+b]){
                            return false;
                        }
                    }
                    return true;
                }
                bool endswith(std::string suffix){
                    if (v.length() < suffix.length()) {
                        return false;
                    }
                    return std::equal(suffix.rbegin(), suffix.rend(), v.rbegin());
                }
                std::string cpp_str(){
                    return v;
                }
                auto c_str(){
                    return v.c_str();
                }
                
        };
std::ostream& operator<<(std::ostream& os, const str& string)
{
    os << string.v;
    return os;
}

}
#endif
