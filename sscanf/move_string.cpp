#include <iostream>

using namespace std;

int main(){
    float value;
    int offset_total=0, offset_now;
    // %n(=�^�ǬO�q�ĴX��Ū�쪺)
    while(sscanf("1 22 333 444 55 67 9"+offset_total, "%f%n", &value, &offset_now) > 0){
        cout << value << endl;
        offset_total+=offset_now;
    }
    return 0;
}