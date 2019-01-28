#include <iostream>
#include <cstdarg>

using namespace std;

void fun(const char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    std::cerr << "fmt" << fmt << std::endl;
    std::cerr << "arg: " << va_arg(args, double) << std::endl;
    std::cerr << "arg: " << va_arg(args, int) << std::endl;
    std::cerr << "arg: " << static_cast<char>(va_arg(args, int)) << std::endl;
}

int main(int, char**){
    std::cerr << "input: " << "fun(\"xxxxx\", 889, 1.25, 97)" << std::endl;
    fun("xxxxx", 889, 1.25, 97); 
}
