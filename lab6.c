#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <error.h>

int match(char *s1, char *s2){
    int diff = strlen(s1)-strlen(s2);
    if(strlen(s1) >strlen(s2))
        return(strcmp(&s1[diff],s2)==0);
    else
        return(0);
}

int main(int argc, char *argv[]){
    if(argc != 3){
        return 1;
    }

    struct dirent *dp;
    DIR *dir_fd;

    if(!(dir_fd=opendir(argv[1])))	{
		 return 1;
	}


	for(; dp=readdir(dir_fd); )	{
            if((match(dp->d_name, argv[2]))){
                    printf("file name : %s\n", dp->d_name);
                    printf("i-node : %ld\n", dp->d_ino);
            }
			if((strcmp(dp->d_name, ".")) && (strcmp(dp->d_name, ".."))){
                continue;
            }

	}

    closedir(dir_fd);
    return 0;

}
	

