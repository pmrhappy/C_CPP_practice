#include <iostream> 
using namespace std; 

class Foo1 { 
public: 
    virtual void show() { // �����禡 
        cout << "Foo1's show" << endl; 
    } 
}; 

class Foo2 : public Foo1 { 
public: 
    int attr1;
    bool attr2;
    void show() { // �����禡 
        cout << "Foo2's show" << endl; 
    } 
}; 

void showFooByPtr(Foo1 *foo) {
    foo->show();
}

void showFooByRef(Foo1 &foo) {
    foo.show();
}

int main() { 
    Foo1 f1; 
    Foo2 f2; 

    // �ʺAô�� 
    showFooByPtr(&f1); 
    showFooByPtr(&f2);
    cout << endl;
 
    // �ʺAô�� 
    showFooByRef(f1); 
    showFooByRef(f2);
    cout << endl; 

    // �R�Aô�� 
    f1.show(); 
    f2.show(); 

    return 0;
}