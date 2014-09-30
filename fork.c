/*
 *  Rick Sullivan
 *  COEN 177 Lab 1
 *  30 September 2014
 *
 *  Solution to the first part of Lab 1.
 *  Prints 7 process IDs
 */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = 0, masterPid;
    
    masterPid = getpid();
    printf("Main process ID: %d\n", masterPid);

    /* Create 7 processes */
    for (int i = 0; i < 7; i++) {
	if (pid == 0) {
	    pid = fork();
	}
    }

    /* Don't show master process */
    if (getpid() != masterPid)
	printf("Process ID: %d\t Child ID: %d\t Parent ID: %d\n", getpid(), pid, getppid());

    wait(NULL);
}
