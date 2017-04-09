/* file: process-01.c
 *
 * fork : system call to create child process
 * check the return type: if greater than zero then it is child process,
 * else parent process.
 * NOTE: the child parent pid need to match with parent's pid, but in case
 * if parent exit/finishes execution early, we will get pid of upstart process
 */	

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
	pid_t iret1;
	printf("\n Process Creation Started...\n");
	
	system("ls -l");	
	iret1 = fork();

	if(iret1 == 0)
	{
		printf("\n Hey I am Child Process My PID: %d & My Parent's PID:%d \n", getpid(), getppid());
	}
	else
	{
		printf("\n Hey I am Parent My PID= %d \n", getpid());
	}

}	
