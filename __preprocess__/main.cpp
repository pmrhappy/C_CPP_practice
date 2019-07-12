#include<iostream>

using namespace std;

int main(){
    cout << __FILE__ << endl; // file name => main.cpp
    cout << __LINE__ << endl; // number of line => 7
    cout << __func__ << endl; // function name => main
}
