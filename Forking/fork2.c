/*
 *  Rick Sullivan
 *  COEN 177 Lab 1
 *  30 September 2014
 *
 *  Solution to the second part of Lab 1.
 *  Prints 7 process IDs
 */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t cpid = 0;

    const pid_t mainPid = getpid();
    printf("Main pid: %d\n", mainPid);

    /* Change this to change the number of spawned processes */
    int numProcesses = 7;

    /* If numProcesses is odd, we will have to spawn one extra process from the main process*/
    bool addExtra = numProcesses % 2 == 1;
    
    /* Iterate down tree, creating two children at each step */
    while (numProcesses > 1 && cpid == 0) {
	numProcesses -= 2;
	cpid = fork();	
	if (cpid != 0) {
	    cpid = fork();
	    /* One child does not create any children */
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
