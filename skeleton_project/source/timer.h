
#include <time.h>
#include <stdio.h>
#include "elevator.h"

/**
 * @file
 * @brief Functions to keep the door open for a period of time.
 */

#define DOOR_TIME 3



/**
 * @brief Starts the timer. 
 * @param[in, out] el The elevator.
 */
void start_timer(elevator* el);


/**
 * @brief Checks if the time is up. 
 * @param[in, out] el The elevator.
 * @return 1 if the time is up, 0 if not. 
 */
int times_up(elevator* el);


