#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    struct stat buf;

    if (argc != 2) {
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return 1;
    }

    if (fstat(fd, &buf) == -1) {
        close(fd);
        return 1;
    }

    printf("inode number: %ld\n", (long)buf.st_ino);
    printf("date/time of last status change: %s", ctime(&buf.st_ctime));
    printf("last updated date/time: %s", ctime(&buf.st_mtime));
    printf("last accessed date/time: %s", ctime(&buf.st_atime));

    close(fd);

    return 0;
}