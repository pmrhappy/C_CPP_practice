#include <iostream>

using namespace std;

class Parent{
public:
    virtual void virtual_func(){
        cout << "Parent's virtual_func" << endl;
    }

    void non_virtual_func(){
        cout << "Parent's non_virtual_func" << endl;
    }
};

class Child: public Parent{
public:
    virtual void virtual_func(){
        cout << "Child's virtual_func" << endl;
    }

    void non_virtual_func(){
        cout << "Child's non_virtual_func" << endl;
    }
};

void test_call_func(Parent& person){
    person.virtual_func();
    person.non_virtual_func();
}

int main(){
    Child child;
    test_call_func(child);
}
