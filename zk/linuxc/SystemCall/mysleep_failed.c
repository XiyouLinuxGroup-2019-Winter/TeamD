#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_alrm(int signo) {

}

unsigned int mysleep(unsigned int nsecs) {
    struct sigaction newact, oldact;
    unsigned int unslept;

    newact.sa_handler = sig_alrm;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGALRM, &newact, &oldact);

    alarm(nsecs);
    pause();

    unslept = alarm(0);
    sigaction(SIGALRM, &oldact, NULL);

    return unslept;
}

int main() {
    while (1) {
        mysleep(2);
        printf("Two seconds passed\n");
    }
    return 0;
}