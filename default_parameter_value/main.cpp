#include <iostream>
#include <string>

using namespace std;


void say_sth(int num=99, string sth="default words"){
    cout << sth << num << endl;
}

int main()
{
    say_sth();
    say_sth(77);
    say_sth(100, "hello world!!");
}
