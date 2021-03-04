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

/*typedef enum floor{
    FLOOR_1,
    FLOOR_2,
    FLOOR_3,
    FLOOR_4
} floor;*/

typedef struct elevator{
    elev_state state;
    int previousfloor;
    int currentfloor;
    int queue[HARDWARE_NUMBER_OF_FLOORS][HARDWARE_NUMBER_OF_BUTTONS];
    HardwareMovement previous_dir;
    HardwareMovement current_dir;
    time_t start_time;
} elevator;


void elev_init(elevator* el);
int get_current_floor(elevator *el);
void elev_control_range(elevator* el);
//int elev_at_floor(elevator* el);
HardwareMovement elev_set_motor_dir(elevator* el);
void elev_set_floor_indicator(elevator* el);
void elev_clear_all_lights(elevator* el);
void elev_update_dir(elevator* el);




#endif // ##ifndef ELEVATOR_H

//