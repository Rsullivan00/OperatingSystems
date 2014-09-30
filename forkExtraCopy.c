#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t cpid, skipPid;
    const pid_t mainPid = getpid();
    
    printf("Main pid: %d\n", mainPid);

    /* Main process creates two processes */ 
    for (int i = 0; i < 2; i++) {
	if (getpid() == mainPid) {
	    cpid = fork();
	}
    }

    /* Two process creates two new processes each */
    if (getpid() != mainPid) {
	cpid = fork();
	if (cpid != 0) {
	    cpid = fork();
	}
    }

    /* Main process creates one more process */
    if (getpid() == mainPid) {
	cpid = fork();
    }
	
    /* Don't show master process */
    if (getpid() != mainPid)
	printf("Process ID: %d\t Recent child ID: %d\t Parent ID: %d\n", getpid(), cpid, getppid());

    /* Wait for child processes */
    wait(NULL);
}
