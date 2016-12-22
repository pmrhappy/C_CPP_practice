#include <iostream> 
using namespace std; 

class Foo1 { 
public: 
    virtual void show() { // µÍ¿¿®Á¶° 
        cout << "Foo1's show" << endl; 
    } 
}; 

class Foo2 : public Foo1 { 
public: 
    int attr1;
    bool attr2;
    void show() { // µÍ¿¿®Á¶° 
        cout << "Foo2's show" << endl; 
    } 
}; 

void showFooByPtr(Foo1 *foo) {
    foo->show();
}

void showFooByRef(Foo1 &foo) {
    foo.show();
}
