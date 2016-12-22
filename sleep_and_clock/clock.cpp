#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main(){
    for(int i=0 ; i<20 ; i++){
        clock_t start = clock();
        Sleep(1);
        clock_t end = clock();
        double d = (double)(end - start) / CLOCKS_PER_SEC;
        cout << d << " s" << endl;
    }
}