#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pidChild1, pidChild2;

    pidChild1 = fork();
    if(pidChild1 == 0){
        execl("/bin/echo", "echo", "This is Child1", (char *)0);
        exit(1);
    }

    pidChild2 = fork();
    if(pidChild2==0){
        execl("/bin/echo", "echo", "This is Child2", (char *)0);
        exit(1);
    }

    printf("Parent: Waiting for children\n");
    wait(NULL);
    wait(NULL);
    printf("Parent: All Children terminated\n");
    exit(0);
}