#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int fd;
    char buffer[1024];

    fd = open("myfifo", O_WRONLY);

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        write(fd, buffer, sizeof(buffer));
    }

    close(fd);
    return 0;
}