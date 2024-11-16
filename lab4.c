#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <error.h>

int main(int argc, char* argv[]) {
    int fd;
    if (argc != 2){
        printf("usage: a.out <pathname>");
    }

    if(access(argv[1], F_OK) == 0) {
        char buffer[20] = "";
        fd = open(argv[1], O_RDONLY);
        read(fd, buffer, 20);
        printf("%s\n", buffer);
    }
    else {
        fd = open(argv[1], O_CREAT | O_RDWR, 0644);
        write(fd, "hello world", 12);
    }

    close(fd);

    return 0;
}
