/**
 * @file
 * @brief Elevator.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "queue.h"
#include <time.h>
#ifndef ELEVATOR_H
#define ELEVATOR_H


typedef enum elev_state{
    IDLE,
    MOVE,
    DOOR_OPEN,
    EMERGENCY_STOP
} elev_state;

typedef struct elevator{
    elev_state state;
    int previousfloor;
    int currentfloor;
    int queue[HARDWARE_NUMBER_OF_FLOORS][HARDWARE_NUMBER_OF_BUTTONS];
    HardwareMovement previous_dir;
    HardwareMovement current_dir;
    time_t start_time;
} elevator;

/**
 * @brief Initializes the elevator. Moves to defined state.
 */
void elev_init(elevator* el);

/**
 * @brief Function to get the current floor the elevator is at.
 */
int elev_get_current_floor(elevator *el);

/**
 * @brief Secures that the elevator does not move past
 * its range.
 */
void elev_control_range(elevator* el);

/**
 * @brief Sets the motor direction.
 */
HardwareMovement elev_set_motor_dir(elevator* el);

/**
 * @brief Sets the floor indicator light.
 */
void elev_set_floor_indicator(elevator* el);


void elev_update_dir(elevator* el);
void elev_set_current_floor(elevator* el);




#endif // ##ifndef ELEVATOR_H

//