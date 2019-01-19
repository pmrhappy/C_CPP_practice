#include <iostream>
#include <memory>

using namespace std;

class Parent
{
public:
    Parent(){
        cout << "Parent constructor" << endl;
    }
    // if no virtual -> deleting child obj will cause undefined behavior
    virtual ~Parent(){ 
        cout << "Parent destructor" << endl;
    }
};

class Child: public Parent
{
public:
    Child(){
        cout << "Child constructor" << endl;
    }
    ~Child(){
        cout << "Child destructor" << endl;
    }
};

int main()
{
    Parent *c1 = new Child();
    delete c1;
    cout << "--------------- shared_ptr:" << endl;
    shared_ptr<Parent> c2(new Child());
}
