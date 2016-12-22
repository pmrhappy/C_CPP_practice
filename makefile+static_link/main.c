#include <iostream>
#include "ciao.h"
#include "hello.h"

using namespace std;;

int main(){
    say_hello();
    say_ciao();
    int *int_array;
    cout << "start to get int array\n";
    int_array = get_int_array();
    //int_array = get_int_array();
    cout << "end to get int array\n";
    cout << "The 1st element is: " << int_array[0] << " " << int_array[1];
    //call_ciao_main();
    return 0;
}