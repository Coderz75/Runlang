#include "main.h"
#define RED 4

int main(){
    try{
        rslCache::main();
    }catch(const std::runtime_error& re)
    {   
        #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        
        SetConsoleTextAttribute(hConsole, RED);
        
        // speciffic handling for runtime_error
        std::cerr << "\nRuntime error: " << re.what() << std::endl;

        SetConsoleTextAttribute(hConsole, 15);
        #else
        std::cerr << "\033[1;31m";
        std::cerr << "\nRuntime error: " << re.what() << std::endl;
        std::cerr << "\033[0m";
        #endif
    }
    catch(const std::exception& ex)
    {
        #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        
        SetConsoleTextAttribute(hConsole, RED);
        
        // speciffic handling for all exceptions extending std::exception, except
        // std::runtime_error which is handled explicitly
        std::cerr << "\nError occurred: " << ex.what() << std::endl;
        SetConsoleTextAttribute(hConsole, 15);
        #else
        std::cerr << "\033[1;31m";
        std::cerr << "\nError occurred: " << ex.what() << std::endl;
        std::cerr << "\033[0m";
        #endif
    }
    catch(...)
    {   
        #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        
        SetConsoleTextAttribute(hConsole, RED);
        
        // catch any other errors (that we have no information about)
        std::cerr << "\nUnknown failure occurred. Possible memory corruption" << std::endl;
        SetConsoleTextAttribute(hConsole, 15);

        #else
        std::cerr << "\033[1;31m";
        std::cerr << "\nUnknown failure occurred. Possible memory corruption" << std::endl;
        std::cerr << "\033[0m";
        #endif

    }
}