#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cnt = 0;

void sig_handler(int sig)
{
    if (sig == SIGINT) {
        cnt++;
        printf("\n%d\n", cnt);
    } else if (sig == SIGQUIT) {
        exit(0);
    }
}

int main()
{
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);
    for (;;) {
        pause();
    }
    return 0;
}

