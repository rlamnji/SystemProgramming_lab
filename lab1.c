#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFSIZE 512

int main(int argc, char * argv[])
{
        int fd_in = 0;
	int fd_out = 0;
        int read_cnt = 0;
        char buffer[BUFSIZE];

        if(argc != 3) { exit(1); }


        fd_in = open(argv[1], O_RDONLY | O_CREAT, 0777);
	if(fd_in ==-1){exit(1);}

        fd_out = open(argv[2], O_WRONLY | O_CREAT, 0777);
	if(fd_out ==-1){
		close(fd_in);
		exit(1);
	}

	while ((read_cnt = read(fd_in, buffer, BUFSIZE)) > 0) {
        	if (write(fd_out, buffer, read_cnt) != read_cnt) {
            		close(fd_in);
            		close(fd_out);
            		exit(1);
        	}
	}

        close(fd_in);
        close(fd_out);

        return 0;
}