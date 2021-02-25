/**
 * @file
 * @brief Elevator.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include <time.h>
#ifndef ELEVATOR_H
#define ELEVATOR_H


typedef enum elev_state{
    INIT,
    IDLE,
    MOVE,
    DOOR_OPEN,
    EMERGENCY_STOP
} elev_state;

typedef enum floor{
    FLOOR_1,
    FLOOR_2,
    FLOOR_3,
    FLOOR_4
} floor;

typedef struct elevator{
    elev_state state;
    floor previousfloor;
    floor currentfloor;
    int queue[HARDWARE_NUMBER_OF_FLOORS][HARDWARE_NUMBER_OF_BUTTONS];
    HardwareMovement motor_dir;
    time_t start_time;
} elevator;


int elev_init();
void set_prevoius_floor(elevator *el);
void set_current_floor(elevator *el);
HardwareMovement elev_set_motor_dir(elevator* el);



#endif // ##ifndef ELEVATOR_H
