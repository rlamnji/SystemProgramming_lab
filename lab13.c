/*
Pipe(), fork(), execlp() system call 들을 사용하여 “ps –ef | grep telnet”의 동작을 구현한다: 
- 부모 프로세스는 파이프를 통해서 “ps –ef” 명령 결과를 출력한다
- 자식 프로세스는 부모 프로세스가 출력한 결과를 받아 “grep telnet” 명령을 수행한다
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int fd[2];

    pipe(fd);

    pid = fork();
   
    if (pid == 0) {
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]); 

        execlp("grep", "grep", "telnet", NULL);
    } else {
        close(fd[0]); 
        dup2(fd[1], 1);
        close(fd[1]); 

        execlp("ps", "ps", "-ef", NULL);
    }

    return 0;
}
