/* file: process-02.c
 *
 * fork : system call to create child process
 * check the return type: if greater than zero then it is child process,
 * else parent process.
 * TODO parent & child process with switch case pid check
 * Note: parent & child process will run in parallel
 */	

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
    pid_t pid;
    char *message;
    int loopn;

    printf("fork program starting\n");
    pid = fork();
    switch(pid) 
    {
    case -1:
        perror("fork failed");
        exit(1); // error exit
    case 0:
        message = "This is the child";
		printf("\n child: pid:%d ppid:%d \n", getpid(), getppid());
        loopn = 10;
        break;
    default:
        message = "This is the parent";
		printf("\n parent: pid:%d ppid:%d \n", getpid(), getppid());
        loopn = 3;
        break;
    }

    for(; loopn > 0; loopn--) {
        printf(" loop o/p : %s \n", message);
        sleep(1);
    }
    exit(0); //successful exit
}
