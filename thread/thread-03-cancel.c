/*
* file:thread-03-cancel.c
* create a thread: main programs cancels created thread after 4 seconds, 
* observe, the thread function is around 10 seconds length & we are
* stopping/cancelling it after say 4 seconds.
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

	sleep(4);
	
	pthread_cancel(a_thread);

	printf("\n Main program execution completed \n");

	return 0;
}

void *thread_function(void *arg)
{
	int j;
	printf("\n Thread Function is Running argument was %s \n", (char *)arg);

	for(j=0;j<10;j++) {
	printf("\n thread function for loop \n");
	sleep(1);
	}
	strcpy(message, "Bye");
	pthread_exit(" Thanks You!");
}

