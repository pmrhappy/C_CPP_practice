#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

int main(){

    cout << "Before fork" << endl;
    pid_t pid = fork();
    if(pid==0){ // Child
        cout << "Child, pid=" << getpid() << endl;
        sleep(3);
        cout << "Child, end" << endl;
        sleep(3);
    }
    else{ // Parent
        cout << "Parent, pid=" << getpid() << endl;
        wait(NULL);
        cout << "Parent, stop waiting" << endl;

    }

}
