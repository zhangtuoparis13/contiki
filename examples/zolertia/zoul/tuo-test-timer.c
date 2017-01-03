/*
 * tuo-test-timer.c
 *
 *  Created on: 29 d�c. 2016
 *      Author: tzhang
 */
#include "contiki.h"
#include "dev/leds.h"
#include <stdio.h>

#define SECONDS 2

PROCESS(test_timer_process, "Test timer");
AUTOSTART_PROCESSES(&test_timer_process);

PROCESS_THREAD(test_timer_process, ev, data)
{
    PROCESS_BEGIN();
    static struct etimer et;
    while(1)
    {
        etimer_set(&et, CLOCK_SECOND * SECONDS);
        PROCESS_WAIT_EVENT();
        if(etimer_expired(&et))
        {
            printf("hello world!\n");
            etimer_reset(&et);
        }
    }
    PROCESS_END();
}
