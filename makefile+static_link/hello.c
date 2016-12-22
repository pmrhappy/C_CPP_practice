#include <iostream>
//#include "ciao.h"

using namespace std;;

/*int main(){
    return 0;
}*/

void say_hello(){
    cout << "hello!!\n";
    return;
}

int* get_int_array(){
    
    int GlobalParams[3]={2,5,6};
    int *int_array= new int[3];
    std::copy(GlobalParams, GlobalParams+3, int_array);
    return int_array;
}