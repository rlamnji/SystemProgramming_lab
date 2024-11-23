/*
FIFO를 이용하여 다음과 같은 프로그램을 작성하라
- Fifo-serv 프로그램에서는 “myfifo”라는 이름의 FIFO를 생성한다
- Fifo-clnt 프로그램에서는 stdin으로 부터 한번에 최대 1024byte 크기의 데이터를 읽어들인 후, 데이터를 “myfifo”에 쓴다
- Fifo-serv 에서 “myfifo”에 쓰여진 데이터를 읽어서 stdout에 출력한다
- Mkfifo, open, close, read, write 등의 system call을 사용하면 작성할 수 있다
테스트 입력으로 다음을 사용한다 : 
This is junior-level 
System Programming course
Fall semester of year 2024
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[1024];

    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_RDONLY);

    while (1) {
        ssize_t rread = read(fd, buffer, sizeof(buffer));
        if (rread <= 0) break;  
        buffer[rread] = '\0';
        printf("%s", buffer);
    }

    close(fd);
    return 0;
}
