#include "uart.h"
#include "includes.h"

//#include <stdio.h>

int userApp1(void * args)
{
    printf("[Task-1]: entering task-1 ... \n");
	OSTimeDly(100);

	while(1)
	{
        printf("[Task-1]: ______ looping ______ \n");
		OSTimeDly(50);
	}
}

int userApp2(void * args)
{
    printf("[Task-2]: entering task-2 ... \n");
	OSTimeDly(50);

	while(1) {
        printf("[Task-2]: ______ looping ______ \n");
		OSTimeDly(100);
	}
}
