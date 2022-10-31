#include "slackerz/slackerz.h"
#include "color/termcolor.hpp"
#include "errors.h"
#include <fstream>
#include "checkcompiler.h"

#include s_all

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"
#endif

str fileContent;
s::list<string> fcontent;


int main(int argc, char** argv)
{
    if(!checkcompiler())cerror("Sad");
    if (argc == 1){
        print("Runlang");
        return 1;
    }
    else if(argc > 2){
        cerror("To many inputs\nWe on accept one input\n");
    }
    
    str filename = argv[1];
    
    std::ifstream file; file.open(filename.v);

    if(!file.is_open())
    {
        cerror("File does not exist");
    }

    string a;
    s::list<string> l;
    while (getline (file, a)) {

        fileContent = fileContent.v + a;
        print(a);
        l.append(a);
    }
    // Close the file
    file.close();

    print(l);

    if (filename.endswith(".run")){
        // Compiler
        bool instring = false;
        bool typeStr = false;
        int i;
        int end = 0;
        for (i = 0; i <= fileContent.v.length(); i++){
            // check if in string
            if (fileContent.v[i] == '"' && !instring) {
                instring = !instring;
                typeStr = false;
            }else if (fileContent.v[i] == '"' && instring && !typeStr){
                instring = !instring;
            }else if (fileContent.v[i] == '\'' && !instring) {
                instring = !instring;
                typeStr = true;
            }else if (fileContent.v[i] == '\'' && instring && typeStr){
                instring = !instring;
            }

            if(fileContent.v[i] == 'f' && fileContent.v[i+1] == 'n' && !instring){
                int range = i - 1;
                string k = "";
                if (range != -1){
                    for (int x = end; x<=range; x++ ){
                        k += fileContent.v[x];
                    }
                }
                end = i;
                fcontent.append(k);
            }
        }
        int range = i-1;
        string k = "";
        if (range != -1){
            for (int x = end; x<=range; x++ ){
                k += fileContent.v[x];
            }
        }
        fcontent.append(k);
        print(fcontent);
    
    }else if (filename.endswith(".runex")){
        //execute

    }
    else{
        cerror("Invalid File");
    }
    
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif