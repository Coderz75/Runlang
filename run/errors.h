#ifndef ERRORS_H
#define ERRORS_H

#include "slackerz/default.h"
#include "color/termcolor.hpp"

void cerror(int line, string error, string faultline,string tips = ""){
    std::cout << termcolor::red << "ERROR: On line: " + to_string(line) + "\n\n"<<termcolor::underline<< line << "| " << faultline<<termcolor::reset<<termcolor::red<<"\n\n"<<error << termcolor::green<<"\n\nTips:\n\t" << tips << termcolor::red<< "\nCompilation Terminated\n";
    cout<< termcolor::reset;
    exit(EXIT_FAILURE);
}

void cerror(int line, string error, string faultline,string prevline,string nextline,string tips = ""){
    std::cout << termcolor::red << "ERROR: On line: " + to_string(line) + "\n";

    std::cout << termcolor::reset << line-1 << "| " << prevline << "\n";

    cout<< termcolor::red<<termcolor::underline<< line << "| " << faultline << "\n";
    cout << termcolor::reset << line +1 << "| "<< nextline;
    cout << termcolor::reset<<termcolor::red<<"\n\n"<<error;
    cout<< termcolor::green<<"\n\nTips:\n\t" << tips ;
    cout<<termcolor::red<< "\nCompilation Terminated\n";
    cout<< termcolor::reset;
    exit(EXIT_FAILURE);
}

void cerror(string error){
    std::cout << termcolor::red << error << "\nCompilation Terminated\n";
    cout << termcolor::reset;
    exit(EXIT_FAILURE);
}

void warn(string warnmsg){
    cout << termcolor::yellow << "WARNING: " << warnmsg << termcolor::reset << "\n";
}

void warn(int line, string warnmsg){
    cout << termcolor::yellow << "WARNING [line: "<<tostring(line)<< "]: " << warnmsg << termcolor::reset << "\n";
}


void givetips(string& errorType, string& tips){
    
    if(errorType == " error C2143" or errorType == " expected ‘)’ before ‘;’ token"){
        
        tips = "You might be missing a ')' in one of the previous lines";
    }
}

#endif