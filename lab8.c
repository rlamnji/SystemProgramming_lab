#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
   pid_t pid;
   int len;
   char buffer[BUFSIZ];
   int fd1, fd2;
   int readfd1;


   if ((fd1 = open("sample.txt", O_RDONLY)) == -1) {
       exit(1);
   }


   if ((readfd1 = read(fd1, buffer, BUFSIZ)) == -1) {
       close(fd1);
       exit(1);
   }

   buffer[readfd1] = '\0'; 
   len = strlen(buffer);
   close(fd1);


   if ((fd2 = open("output.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1) {
       exit(1);
   }
   close(fd2);
   
   for (int i = 0; i < len; i++) {
       pid = fork();
       if (pid == -1) {
           exit(1);
       } else if (pid == 0) {
           fd2 = open("output.txt", O_WRONLY | O_APPEND);
           if (fd2 == -1) {
               exit(1);
           }

           buffer[i + 1] = '\0';
           write(fd2, buffer, i + 1);
           write(fd2, "\n", 1);

           close(fd2); 
           exit(0); 
       }else{
            waitpid(pid, NULL, 0);
       }
   }

   return 0;
}
