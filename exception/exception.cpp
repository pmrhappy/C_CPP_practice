#include <iostream>

using namespace std;

int main () {
  
  try{
    bool something_happens = true;
    if(something_happens)
        throw "something wrong";

    }
  catch (const char* msg){
    cout << "error occurs: " << msg << endl;
    }

  return 0;
}