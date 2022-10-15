#include "slackerz/slackerz.h"
#include "color/termcolor.hpp"
#include "errors.h"
#include <fstream>

#include s_all

str fileContent;
s::list<string> fcontent;

int main(int argc, char** argv)
{
    if (argc == 1){
        print("Runlang");
    }
    else if(argc > 2){
        cerror("To many inputs\nWe on accept one input\n");
    }
    str filename = argv[1];

    ifstream file(filename.v);
    string a;
    
    if(!file.is_open())
    {
        cerror("File does not exist");
    }

    while (getline (file, a)) {
        fileContent.v += a;
    }

    // Close the file
    file.close();


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