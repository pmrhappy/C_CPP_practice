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
        sleep(1);
        cout << "Child, end" << endl;
        sleep(1);
        auto rc = execl("/bin/ls", "ls", "-alh", NULL);
        cout << "Child, rc:" << rc << endl;
        exit(WEXITSTATUS(rc));
    }
    else{ // Parent
        cout << "Parent, pid=" << getpid() << endl;
        int status(1);
        wait(&status); // status == 0 if the child process stop normally
        cout << "Parent, stop waiting, child status=" << WEXITSTATUS(status) << endl;
        exit(WEXITSTATUS(status));

    }

}
