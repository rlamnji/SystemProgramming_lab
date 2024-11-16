#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t pidChild1, pidChild2;

    pidChild1 = fork();
    if(pidChild1 == 0){
        execl("/bin/echo", "echo", "This is Child1", (char *)0);
        exit(1);
    }

    pidChild2 = fork();
    if(pidChild2 == 0){
        execl("/bin/echo", "echo", "This is Child2", (char *)0);
        exit(1);
    }

    printf("Parent: Waiting for children\n");
    for (int i = 0; i < 2; i++) {
        pid_t endChild = waitpid(-1, &status, 0);
        if(endChild == pidChild1) {
            printf("Parent: First Child: ");
        }else if(endChild == pidChild2){
            printf("Parent: Second Child: ");
        }

        if(WIFEXITED(status)){
            printf("terminated with status %d\n", WEXITSTATUS(status));
        }
    }
    printf("Parent: All Children terminated\n");
    exit(0);
}
