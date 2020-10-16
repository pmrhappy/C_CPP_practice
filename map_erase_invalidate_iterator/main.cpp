#include<iostream>
#include<map>

using namespace std;

int main(){
    map<int, int> data;
    data[1] = 1;
    data[2] = 2;
    data[3] = 3;
    data[4] = 4;

    // crash(undefined behavior) version
//    for(auto it = data.begin(); it != data.end(); it++){
//        cerr << it->second << endl;
//        it = data.erase(it);
//    }

    // fix version
    for(auto it = data.begin(); it != data.end(); ){
        cerr << it->second << endl;
        it = data.erase(it);
    }
}
