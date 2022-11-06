#ifndef PARSER_H
#define PARSER_H


#include "slackerz/all.h"
void replaceStr(std::string& h) {
    bool instr = false;
    for (int i = 0; i < h.length(); i++){
        char l = h[i];
        if (l == '"' or l == '\''){
            instr = !instr;

            if (instr){

                if (l == '"'){

                    h.replace(i,1,"(str) \"");
                    i+=6;

                }else{
                    i+=6;
                    h.replace(i,1,"(str) '");
                }
            }

        }
    }
}
        



#endif