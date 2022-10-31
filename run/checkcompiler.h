#ifndef CHECKCOMPILER_H
#define CHECKCOMPILER_H

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#include "slackerz/all.h"
#include "errors.h"

#ifdef _WIN32
std::string Runexec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
#else
std::string Runexec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
#endif

bool checkcompiler(){
    #ifdef _WIN32
        string contents = Runexec("cl");
        print(contents);
        if (contents.find("'cl' is not recognized") != string::npos){
            cerror("You need to download visual c++");
        }else return true;
    #elif __GNUC__
    system("g++ <test.txt");
        str contents = Runexec("g++");
        print(contents);
        if (contents.startswith("g++")) return true;
        else cerror("You need to download g++");
    #else
        print("You are not on a supported system yet");
    #endif

}

#endif