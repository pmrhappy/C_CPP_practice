#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;;


void exec(vector<double> v1){
    //vector<double> v1;
    vector<double> v2;
    
    for(int i=0;i<30000;i++){
        v1.insert(v1.begin()+i,i+0.5);
        v2.insert(v2.begin()+i,i+10.5);
    }
    
    //for(int j=0;j<v1.size();j++)
        //cout << "\nv1 [" << j << "] = " << v1[j];
    //for(int j=0;j<v2.size();j++)
        //cout << "\nv2 [" << j << "] = " << v2[j];
    
    v1.swap(v2);
    
    cout << "\n\n>>>>>>>>>>after swapping....\n";
    
    //for(int j=0;j<v1.size();j++)
        //cout << "\nv1 [" << j << "] = " << v1[j];
    //for(int j=0;j<v2.size();j++)
        //cout << "\nv2 [" << j << "] = " << v2[j];
    
}

int main(void){
    vector<double> v1;
    for(int i=0;i<30000;i++){
        cout <<"OOOOOOO  " << i << "  OOOOOOOO\n\n";
            exec(v1);
            //for(int j=0;j<v1.size();j++)
                //cout << "\nv1 [" << j << "] = " << v1[j];
            //system("pause");
    }
    
}