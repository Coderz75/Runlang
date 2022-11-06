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
    ofstream file(".__run_cache__/data.cpp",std::ios_base::app);
    file << a << "\n";
}
fn makef(){
    ofstream file(".__run_cache__/data.cpp");
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
        replaceStr(write);
        writefile(write + ";");
    }


    #ifdef __GNUC__
    writefile("#pragma GCC diagnostic pop");
    #endif

    //Compile
    #ifdef _WIN32
    string x = "cl /std:c++20 /o main .__run_cache__/data.cpp >nul 2>nul >.__run_cache__/error.txt";
    #elif __GNUC__
    warn("G++, gcc, and clang is not fully supported yet. Use at your own risk");
    string x = "g++ -std=c++20 -o main .__run_cache__/data.cpp >.__run_cache__/error.txt";
    #endif
    system(x.c_str());

}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif