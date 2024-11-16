#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PATH_MAX 1024
int main() {
    char path[PATH_MAX];

    char *current = getenv("PATH");
    if (current != NULL) {
        printf("current PATH: %s\n", current);
    } else {
        return 1;
    }

    if (unsetenv("PATH") != 0) {
        return 1;
    }

    //delete
    current = getenv("PATH");
    if (!current) {
        printf("erase current PATH\n");
    } 

    //directory
    if (getcwd(path, sizeof(path)) == NULL) {
        return 1;
    }
    printf("directory: %s\n", path);

    //change
    if (setenv("PATH", path, 1) != 0) {
        return 1;
    }

    current = getenv("PATH");
    printf("change PATH: %s\n", current);

    return 0;
}