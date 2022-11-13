#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace rsl{
class exception: public std::runtime_error {
    std::string msg;
public:
    exception(const std::string &arg, const char *file, int line) :
    std::runtime_error(arg) {
        std::ostringstream o;
        o << "In file: "<< file << "\nLine: " << line << "\n" << arg;
        msg = o.str();
    }
    ~exception() throw() {}
    const char *what() const throw() {
        return msg.c_str();
    }
};

#define raise(arg) throw exception(arg, __FILE__, __LINE__);
}
#endif