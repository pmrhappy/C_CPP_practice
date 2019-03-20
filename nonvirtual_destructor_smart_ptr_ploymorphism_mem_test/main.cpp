#include <iostream>
#include <memory>

using namespace std;

class Parent
{
public:
    Parent(){
        cout << "Parent constructor" << endl;
    }
    ~Parent(){ // should add "virtual" 
        cout << "Parent destructor" << endl;
    }
};

class Child: public Parent
{
public:
    shared_ptr<int> num;
    Child(){
        cout << "Child constructor" << endl;
        this->num = make_shared<int>(10);
    }
    ~Child(){
        cout << "Child destructor" << endl;
    }
};


void delete_function(Parent* parent){
    // If Parent's destructor is not virtual, it will only call parent's destructor
    // In this case, it will cause memory leak
    delete parent;
}

int main()
{
    Child *child = new Child();
    delete_function(child);
}
