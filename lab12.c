/*아래와 같은 프로그램을 작성하라 : 
- 아래의 signal handle(int_handler(int sig))를  등록/호출한다
- Parent 프로세스는 child 프로세스를 fork()한다
- Child 프로세스는 while(1)을 실행한다(사실상 infinite loop 실행)
- Parent는 kill system call을 사용하여 child에게 SIGINT 시그널을 보낸다
- 시그널을 받은 child 는 종료 status 값을 가지고 exit 한다 
- Parent는 wait 시스템 호출을 이용하여 child의 종료를 기다린다. 종료하는 child에 대하여 WIFEXITED 매크로를 호출하여 정상종료인지 확인하고, WEXITSTATUS 매크로를 호출하여 종료 status 값을 출력한다.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void int_handler(int sig) {
    printf("Process %d received signal %d\n", getpid(), sig);
    exit(0); // 이 인자에 따라 status 출력값 달라짐
}

int main(){
    pid_t pid;
    int status;

    signal(SIGINT, int_handler);
    pid = fork();

    if(pid==0){
        while (1)
        {
            sleep(1);
        }
        
    }else{
        kill(pid, SIGINT);
        wait(&status);

        if(WIFEXITED(status)){
            printf("%d\n", WEXITSTATUS(status));
        }
    }
}