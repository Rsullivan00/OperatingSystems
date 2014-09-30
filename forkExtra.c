#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t cpid = 0;

    const pid_t mainPid = getpid();
    printf("Main pid: %d\n", mainPid);

    int numProcesses = 7;
    bool addExtra = numProcesses % 2 == 1;
    
    while (numProcesses > 1 && cpid == 0) {
	numProcesses -= 2;
	cpid = fork();	
	if (cpid != 0) {
	    cpid = fork();
	    if (cpid == 0)
		break;
	}
    }

    /* If there is an odd number, split the last process from the main process */
    if (getpid() == mainPid && addExtra)
	cpid = fork();

    /* Don't show master process */
    if (getpid() != mainPid)
	printf("Process ID: %d\t Recent child ID: %d\t Parent ID: %d\n", getpid(), cpid, getppid());

    /* Wait for child processes */
    wait(NULL);
}
