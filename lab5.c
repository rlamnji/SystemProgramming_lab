#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "error.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    if(argc!=3){
        return 1;
    }

    const char *oldname = argv[1];
    const char *newname =argv[2];

    if(rename(oldname, newname)==0){
        printf("file renamed\n");
    }else{

        if (link(oldname, newname) == 0) {
            if (unlink(oldname) == 0) {
                printf("file renamed\n");
            } else {
                printf("Failed");
            }
        } else {
            printf("Failed");
        }

    }

    return 0;
}
