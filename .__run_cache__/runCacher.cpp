#include "main.h"


int main(){
    try{
        rslCache::main();
    }catch(const std::runtime_error& re)
    {
        // speciffic handling for runtime_error
        std::cerr << "\nRuntime error: " << re.what() << std::endl;
    }
    catch(const std::exception& ex)
    {
        // speciffic handling for all exceptions extending std::exception, except
        // std::runtime_error which is handled explicitly
        std::cerr << "\nError occurred: " << ex.what() << std::endl;
    }
    catch(...)
    {
        // catch any other errors (that we have no information about)
        std::cerr << "\nUnknown failure occurred. Possible memory corruption" << std::endl;
    }
}