#include "slackerz/slackerz.h"
#include "color/termcolor.hpp"
#include "errors.h"
#include <fstream>
#include <filesystem>
#include "parser.h"
#include s_all

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"
#endif



str fileContent;
s::list<string> fcontent;

fn writefile(string a){
    ofstream file(".__run_cache__/main.cpp",std::ios_base::app);
    file << a << "\n";
}
fn makef(){
    ofstream file(".__run_cache__/main.cpp");
    file.close();
}

fn makeE(){
    ofstream file(".__run_cache__/error.txt");
    file.close();  
}

int main(int argc, char** argv)
{
    makef();
    makeE();

    if (argc == 1){
        print("Runlang");
        return 1;
    }
    else if(argc > 2){
        cerror("To many inputs\nWe on accept one input\n");
    }
    string a;
    str filename = argv[1];
    writefile("#include \"rsl/rsl.h\"");

    #ifdef __GNUC__
    writefile("#pragma GCC diagnostic push");
    writefile("#pragma GCC diagnostic ignored \"-Wwrite-strings\"");
    #endif


    ifstream file(filename.v);
    while (getline (file, a)) {
        string write = a;
        fcontent.append(a);
        replaceStr(write);
        writefile(write + ";");

    }

    file.close();
    #ifdef __GNUC__
    writefile("#pragma GCC diagnostic pop");
    #endif

    //Compile
    #ifdef _WIN32
    string x = "cl /std:c++20 /o main .__run_cache__/main.cpp >nul 2>nul >.__run_cache__/error.txt";
    #else
    warn("G++, gcc, and clang is not fully supported yet. Use at your own risk");
    string x = "g++ -std=c++20 -o main .__run_cache__/main.cpp >.__run_cache__/error.txt";
    #endif
    system(x.c_str());
    
    ifstream errorF(".__run_cache__/error.txt");
    if(!errorF){
        cerror("Not able to open cache. Please check space on your system, and try again");
    }
    s::list<string> errors;
    while (getline (errorF, a)) {
        errors.append(a);
    }
    errorF.close();
    #ifdef _WIN32
    try{
        if(errors.v[8] == "main.obj"){
            exit(1);
        }
    }catch(...){}

    str e = errors.v[1];
    s::list<string> elist = e.split(":");

    string line = elist.v[0];

    line = line[line.length() -1 - 1];
    string errorType = elist.v[1];

    //Calculating tips

    string tips = "No tips found";

    givetips(errorType,tips);

    try{
        cerror(toint(line),elist.v[2]+ ": " + elist.v[3], fcontent.v[toint(line) -1],fcontent.v[toint(line) -2],fcontent.v[toint(line) ],tips);
    }catch(...){
        cerror(toint(line),elist.v[2]+ ": " + elist.v[3], fcontent.v[toint(line) -1],fcontent.v[toint(line) -2],"",tips);
    }
    

    #endif

}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif