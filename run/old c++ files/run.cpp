#include "slackerz/slackerz.h"
#include "color/termcolor.hpp"
#include "errors.h"
#include <fstream>
#include <filesystem>
#include "parser.h"
#include "global.h"

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include s_all

str fileContent;
s::list<string> fcontent;

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"
#endif





fn makef(string path){
    ofstream file(path + "\\.__run_cache__/main.h");
    file.close();
}

fn makeE(string path){
    ofstream file(path + "\\.__run_cache__/error.txt");
    file.close();  
}

bool noGnucCompiler(string path){
    ifstream file(path + ".__run_cache__/error.txt");
    if (file.good())
    {
        string sLine;
        getline(file, sLine);
        if(sLine == "g++: fatal error: no input files") return false;
        else return true;
    }
}

int main(int argc, char** argv)
{
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir( buff, FILENAME_MAX );
    string dir_path(buff);

    makeE(dir_path);
    makef(dir_path);

    if(system(std::string("cl >" + dir_path +"/.__run_cache__/reg.txt 2>" + dir_path +"/.__run_cache__/error.txt").c_str())){
        if(system(string("g++ 2>" + dir_path +"/.__run_cache__/error.txt").c_str())){
            if(noGnucCompiler(dir_path)){
                if(system(string("clang++ 2>" + dir_path +"/.__run_cache__/error.txt").c_str())){
                    cerror("No compiler found on system");
                }
            }
        }
    }

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
    writefile("namespace rslCache{");
    


    ifstream file(filename.v);
    if(!file){
        cerror("Error: File does not exist");
    }
    while (getline (file, a)) {
        string write = a;
        fcontent.append(a);
        replaceStr(write);
        handleIncludes(write);
        writefile(write + ";");


    }
    writefile("}");

    //Compile
    #ifdef _WIN32
    string x = "cl /EHsc /std:c++20 /o main " + dir_path +"/.__run_cache__/runCacher.cpp >nul 2>nul >.__run_cache__/error.txt";

    #elif __GNUC__
    warn("G++and clang is not fully supported yet. Use at your own risk");
    string x = "g++ -std=c++20 -o main " + dir_path +"/.__run_cache__/runCacher.cpp 2>.__run_cache__/error.txt"; 
    #endif
    system(x.c_str());
    
    ifstream errorF(dir_path +"/.__run_cache__/error.txt");
    if(!errorF){
        cerror("Not able to open cache. Please check space on your system, and try again");
    }
    s::list<string> errors;
    while (getline (errorF, a)) {
        errors.append(a);
    }
    errorF.close();

    #ifdef __GNUC__
    if(std::filesystem::is_empty(dir_path + "/.__run_cache__/error.txt")){
        exit(1);
    }
    #endif


    #ifdef _WIN32
    try{
    try{
        
        if(errors.v[errors.v.size() - 1] == "runCacher.obj "){

            exit(1);
        }
    }catch(...){}

    int round = 0;
    for(string k: errors.v){
        if (round !=0){

        str e = k;

        s::list<string> elist = e.split(":");

        string line = elist.v[0];

        line = str(str(line).split("(")[1]).split(")")[0];

        string errorType = elist.v[1];
        //Calculating tips
        
        string tips = "No tips found";

        givetips(errorType,tips);

        string fullerror = "";
        for(int i = elist.v.size() - 1; i > 0;i-- ){
            fullerror = elist.v[i]  + ": "+ fullerror;
        }

    
        try{

            cerrorNotem(toint(line)-1, fullerror, fcontent.v[toint(line) -1-1],fcontent.v[toint(line) -2-1],fcontent.v[toint(line) -1],tips);
        }catch(...){

            cerrorNotem(toint(line)-1, fullerror, fcontent.v[toint(line) -1-1],fcontent.v[toint(line) -2-1],"",tips);

        }
        print("\n");
        }
        round +=1;

    }
    cerror("");
    
    }catch(...){
        for(string i: errors.v){
            print(i);
        }
    }
    #else 
    try{
    int round = 0;
    for(string k: errors.v){
    if (round != 0){
    str e = k;
    s::list<string> elist = e.split(":");

    int line = toint(elist.v[1]);
    line = line/2;

    try{
        if (elist.v[3] != " error") exit(0);
    }catch (...) {exit (0);}
    string errorType = elist.v[4];

    //Calculating tips

    string tips = "No tips found";

    givetips(errorType,tips);
    print("\n");

    try{
        cerrorNotem(line,elist.v[4], fcontent.v[line -1],fcontent.v[line -2],fcontent.v[line ],tips);
    }catch(...){
        cerrorNotem(line,elist.v[2]+ ": " + elist.v[5], fcontent.v[line -1],fcontent.v[line -2],"",tips);
    }
    }
    round +=1;
    }
    cerror("");
    }catch(...){
        for(string i: errors.v){
            print(i);
        }
    }
    #endif

}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif