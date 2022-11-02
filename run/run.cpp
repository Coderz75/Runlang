#include "slackerz/slackerz.h"
#include "color/termcolor.hpp"
#include "errors.h"
#include <fstream>
#include <filesystem>

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
    ifstream file(filename.v);
    while (getline (file, a)) {
        writefile(a);
    }
    #ifdef _WIN32
    string x = "cl /o main .__run_cache__/data.cpp >nul 2>nul >.__run_cache__/error.txt";
    #elif __GNUC__
    print("running");
    string x = "g++ -o main .__run_cache__/data.cpp >nul 2>nul >.__run_cache__/error.txt";
    #endif
    system(x.c_str());

}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif