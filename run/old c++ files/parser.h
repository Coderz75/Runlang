#ifndef PARSER_H
#define PARSER_H


string strconv = "(rsl::string) ";
#include "slackerz/all.h"
#include "errors.h"
#include <fstream>
#include "global.h"

fn writefile(string a){
    ofstream file(".__run_cache__/main.h",std::ios_base::app);
    file << a << "\n";
}

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

void handleIncludes(std::string& h){
    string s = h;
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace),
            s.end());
    if(str(s).startswith("import")){
        s.erase(0,6);
        ifstream file (s);
        if(!file){
            cerror("File: \"" + s + "\" does not exist");
        }
        string a;
        
        while (getline (file, a)) {
            string write = a;
            fcontent.append(a);
            replaceStr(write);
            handleIncludes(write);
            writefile(write + ";");
        }
        h = "";
    }
}
        



#endif