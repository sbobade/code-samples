/* file: process-03.c
 *
 * same as program process-02.c
 * only one change, parent process wait till the complete execution of child
 * process.
 * wait call from sys/wait.h, this call expects first registration on exit_status 
 * once child with exit status of child finished execution parent will also exit 
 * smoothly, target is safe complete of child process. 
 * Here:- exit_status is just for cleaner program to track child process status. 	
 */	

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int main()
{
    pid_t pid;
    char *message;
    int loopn;
	int exit_status;

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
		exit_status = 77;
        break;
    default:
        message = "This is the parent";
		printf("\n parent: pid:%d ppid:%d \n", getpid(), getppid());
        loopn = 3;
		exit_status = 0;
        break;
    }

    for(; loopn > 0; loopn--) {
        printf(" loop o/p : %s \n", message);
        sleep(1);
    }


	if(pid)	{
		int status_value, final_pid_ret;
		pid_t child_pid;

		child_pid = wait(&status_value);
		
		printf("\n Child completed with PID: %d \n", child_pid);
		
		final_pid_ret = WIFEXITED(status_value);

		if(final_pid_ret)
			printf("\n Child exited with code : %d \n", final_pid_ret);
		else
			printf("\n Child exited with un-trackable \n");
		
	}

    exit(exit_status); //successful exit
}
