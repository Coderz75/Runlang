
#include <iostream>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <filesystem>
#endif


using namespace std;

int main(int argc, char *argv[]){

    
    string fstring = "";

    for (int i = 1; i < argc; ++i)
        fstring += string(argv[i]) + " ";
    
    

    #ifdef _WIN32
        char buffer[MAX_PATH];
        GetModuleFileNameA(NULL, buffer, MAX_PATH);
        std::string::size_type pos = std::string(buffer).find_last_of("\\/");
        
        string x = std::string(buffer).substr(0, pos);
        
        system(("python " + x + "/run.py " + fstring).c_str());
        

    #else
        string x(std::filesystem::canonical("/proc/self/exe"));
        size_t found = x.find_last_of("/\\");
        x = x.substr(0, found);
        system(("python3 " + x + "/run.py " + fstring).c_str());
    #endif
}