/*
Popen()과 pclose()를 사용하여 “who | sort”를 실행 시킬 수 있는 프로그램을 작성하라.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    FILE *fp;
    FILE *fp1;
    char buffer[BUFSIZ +1];
    int chars_read;

    fp = popen("who", "r");
    fp1 = popen("sort", "w");

    if(fp != NULL && fp1 != NULL){
        chars_read = fread(buffer, sizeof(char), BUFSIZ, fp);
        fwrite(buffer, sizeof(char), chars_read, fp1);

        pclose(fp);
        pclose(fp1);
        exit(0);
    }
    exit(1);
}
