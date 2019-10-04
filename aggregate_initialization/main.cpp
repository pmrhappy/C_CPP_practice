#include <string>
#include <iostream>

struct S {
    int x;
    std::string y;
    bool z;


};
 
class C{
public:
    int x;
    std::string y;
    float z;
};

int main()
{
    S s1 { 1, "ablah", true};
    std::cout << s1.x << s1.y << s1.z << std::endl;

    C c1 { 1, "xxx"};
    std::cout << c1.x << c1.y << c1.z << std::endl;
}
