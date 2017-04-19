/*
* file:thread-02-join.c
* create a thread: main programs just completes after creating thread
* we are not joinint the thread, so as soon as main program execution completes
* we come out of execution process and can't get any thread function/thread execution details.	
*
*/

#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

int a=20, b=10;
char message[] = "Shrikant";

void *thread_function(void *arg);

int main()
{
	int th;
	void *thread_result;
	pthread_t a_thread;

	th = pthread_create(&a_thread, NULL, thread_function, (void*)message);
	
	printf("\n TID Return Value: %d\n", th);

	if(th!=0)
	printf("\n Thread prepration failed ! \n");

	th = pthread_join(a_thread, &thread_result);
	printf("\n Thread is joined it returned : %s and the global message: %s ", (char *)thread_result, message);	

	printf("\n Main program execution completed \n");

	return 0;
}

void *thread_function(void *arg)
{
	int j;
	printf("\n Thread Function is Running argument was %s \n", (char *)arg);

	for(j=0;j<10;j++)
	printf("\n thread function for loop \n");
			
	strcpy(message, "Bye");
	pthread_exit(" Thanks You!");
}

