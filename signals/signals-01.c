/* file: signals-01.c
 *
 * Signal handler callback for SIGINT
 * Once user press "Ctrl + C" for main program we will catch/handle
 * the signal event 
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler_clbk(int signal)
{
    printf("\n Inside Signal Handler Callback- I got signal %d \n", signal);
	exit(0); /* safely exit the execution of program, as user pressed ctrl +c */
}

int main()
{
    (void) signal(SIGINT, signal_handler_clbk); /* callback regsitered for signal handler*/

	/* continuous polling while loop will make user to add his ctrl+c as per his conv.*/
    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
}
