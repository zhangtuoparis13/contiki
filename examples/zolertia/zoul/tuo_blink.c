/*
 * tuo_blink.c
 *
 *  Created on: 27 d�c. 2016
 *      Author: tzhang
 */

#include "contiki.h"
#include "dev/leds.h"

PROCESS(blink_process, "Blink");
AUTOSTART_PROCESSES(&blink_process);

PROCESS_THREAD(blink_process,ev,data)
{
    PROCESS_EXITHANDLER(goto exit;)
    PROCESS_BEGIN();

    while(1)
    {
        static struct etimer et;
        etimer_set(&et, CLOCK_SECOND);
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
        leds_on(LEDS_ALL);
        etimer_set(&et,CLOCK_SECOND);
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
        leds_off(LEDS_ALL);
    }

    exit:
    leds_off(LEDS_ALL);
    PROCESS_END();
}
