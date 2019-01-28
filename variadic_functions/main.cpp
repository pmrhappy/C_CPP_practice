#include <iostream>
#include <cstdarg>

using namespace std;

void fun(const char* fmt, va_list args){
    std::cerr << "fmt" << fmt << std::endl;
    std::cerr << "arg: " << va_arg(args, double) << std::endl;
    std::cerr << "arg: " << va_arg(args, int) << std::endl;
    std::cerr << "arg: " << static_cast<char>(va_arg(args, int)) << std::endl;
}

void forward_fun(const char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    fun(fmt, args);
}

int main(int, char**){
    std::cerr << "input: " << "fun(\"xxxxx\", 889, 1.25, 97)" << std::endl;
    forward_fun("xxxxx", 889, 1.25, 97); 
}
