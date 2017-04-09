/* file: process-01.c
 *
 * fork : system call to create child process
 * check the return type: if greater than zero then it is child process,
 * else parent process.
 * 
 */	

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
	int iret1;
	printf("\n Process Creation Started...\n");
	
	system("ls -l");	
	iret1 = fork();

	if(iret1 == 0)
	{
		printf("\n Hey I am Child......PID: %d,,Parents PID:..%d.\n",getpid(),getppid());
	}
	else
	{
		printf("\n Hey I am Parent..PID= %d.. Parent PID: %d\n",getpid(),getppid());
	}
}	
