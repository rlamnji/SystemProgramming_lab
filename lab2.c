#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <error.h>

int main(){
	int fd1, fd2;
	ssize_t testRead1;
	ssize_t testRead2;

	char buffer1[100] = {0};
	char buffer2[100] = {0};

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	if(fd1 == -1){exit(1);}
	if(fd2 == -1){exit(1);}

	lseek(fd1, 10, SEEK_SET);
	lseek(fd2, -5, SEEK_END);

	testRead1 = read(fd1, buffer1, sizeof(buffer1)-1);
	testRead2 = read(fd2, buffer2, sizeof(buffer2)-1);

	printf("%s", buffer1);
	printf("%s\n", buffer2);

	close(fd1);
	close(fd2);

	return 0;

}

