Rick Sullivan
10/8/2014
COEN 177 Lab 1


******************
Part I
******************

My first solution creates a chain of 7 processes that appears like the following:

M
 \
  p1
   \
    p2
     \
      ...
       \
	p(n)

I do this simply by iterating with a for loop. Each iteration, the parent process breaks out of the loop, while the newly created child process forks a new process.

The number of processes spawned can be changed simply by changing the number of iterations of the loop.

I compiled and ran this program with the following commands:

g++ fork.c -o fork
./fork


******************
Part II
******************

The requirements for the second part of the lab can be restated as "Each process must create 0, 2, or 3 other processes." Thinking about the problem in this way, I came up with an algorithm to create a process tree that looks like this:

EVEN N:

    M
   / \
  p1  p2
     /  \
    p3  p4
       /  \
      p5   ...
	  /  \
     p(n-1)   p(n)

N te that this will create any EVEN number of processes with each process having either 0 or 2 children. We can simply create any ODD number of processes n by creating n-1 processes in the manner shown above, and then creating one final process from the main process.
th solutions, I am printing the Parent process I

ODD N:

    M--p(n)
   / \
  p1  p2
     /  \
    p3  p4
       /  \
      p5   ...
	  /  \
     p(n-2)   p(n-1)

The number of processes spawned can be changed by changing the value assigned to numProcesses.
I compiled and ran this program with the following commands:

g++ fork2.c -o fork2
./fork2

For both solutions, I am printing the Parent process ID, the current process ID, and the last child process ID spawned. The process tree can easily be reconstructed using that information (we do not need every child ID, because any children will list the spawning process as their parent).
