#include <iostream>

using namespace std;

class Class{
public:
    Class(){};
    ~Class(){};
    void f1(){
        cout << "f1 in class" << endl;
    };
};

struct Struct{
    void f1(){
        cout << "f1 in struct" << endl;
    };
};

class ChildClass: Class{
    public:
    ChildClass(){
        this->f1();
    };
    ~ChildClass(){};
};
struct ChildStruct: Struct{};


int main(int, char**){
    ChildClass c1;
    ChildStruct s1;
    c1.f1(); // Cannot access f1 because ChildClass private inherits from Class
    s1.f1();

}
