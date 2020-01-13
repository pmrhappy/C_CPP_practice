#include<iostream>
#include<string>
#include<memory>

using namespace std;

void print(const shared_ptr<string> &str, shared_ptr<string> &str2){
    cerr << *str << endl;
    cerr << *str2 << endl;
    *str = "modify";
    *str2 = "modify2";
    cerr << *str << endl;
    cerr << *str2 << endl;
//    str = make_shared<string>("reset");  // This causes compile error since const shared_ptr
    str2 = make_shared<string>("reset");  // This one is OK
}

int main(){
    auto original = make_shared<string>("original");
    auto second = make_shared<string>("second");
    print(original, second);
}
