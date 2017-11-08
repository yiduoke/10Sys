#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
    if (signo == SIGINT){//keyboard interrupt
        printf("I've been interrupted due to SIGINT, how rude!\n");
        exit(0);
    }
    else if (signo == SIGUSR1){//keyboard interrupt
        printf("hello, my mom is %d\n", getppid());
    }
}
int main(){ 
    signal(SIGINT, sighandler);//whenever the SIGNIT gets sent, RUN this function
    //yeah you're passing a function as an argument
    while (1){
        printf("hello, I'm process %d\n", getpid());
        sleep(1);//causes program to sleep for 1 second so it doesn't spam hello
    }

    return 0;
}