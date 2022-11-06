#ifndef PARSER_H
#define PARSER_H

string strconv = "(rsl::string) ";
#include "slackerz/all.h"
void replaceStr(std::string& h) {
    bool instr = false;
    for (int i = 0; i < h.length(); i++){
        char l = h[i];
        if (l == '"'){
            instr = !instr;

            if (instr){
                h.replace(i,1,strconv + "\"");
                i+=strconv.length() ;
            }

        }
    }
}
        



#endif