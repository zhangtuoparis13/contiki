/*
 * Hi.c
 *
 *  Created on: 27 déc. 2016
 *      Author: tzhang
 */

#include "contiki.h"
#include <stdio.h>

static struct etimer et;
PROCESS(tester, "hi this is testing, just titile that does nothing.");
AUTOSTART_PROCESSES(&tester);
PROCESS_THREAD(tester, ev, data)
{
	PROCESS_BEGIN();

	etimer_set(&et,CLOCK_SECOND);

	PROCESS_WAIT_EVENT();
	int i = 0;
	while(i<10)
	{
		PROCESS_WAIT_EVENT();
		printf("This is to be printed : %d \n", ev);
		etimer_reset(&et);
		i++;
	}

	PROCESS_END();
}


