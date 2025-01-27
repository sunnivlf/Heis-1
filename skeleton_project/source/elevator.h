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

/**
 * @brief The elevator's different states.
 */
typedef enum elev_state{
    IDLE,
    MOVE,
    DOOR_OPEN,
    EMERGENCY_STOP
} elev_state;

/**
 * @brief A structure to represent the elevator.
 */
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
 * @brief Gets the floor the elevator is currently on.
 * 
 * @return -1 if the elevator is between floors, otherwise the floor's index.
 */
int elev_get_current_floor();

/**
 * @brief Sets the current floor when the elevator reaches a new
 * floor.
 * 
 * @param[in, out] el The elevator.
 */
void elev_set_current_floor(elevator* el);

/**
 * @brief Sets the floor indicator light for the floor the elevator
 * is currently on. If the elevator is between two floors, the floor 
 * indicator light is lit for the floor the elevator just left.
 * 
 * @param[in] el The elevator.
 */
void elev_set_floor_indicator(elevator* el);

/**
 * @brief Sets the motor direction depending on previous
 * direction and next orders.
 * 
 * @param[in] el The elevator.
 * 
 * @return @c HARDWARE_MOVEMENT_UP, @c HARDWARE_MOVEMENT_STOP, @c HARDWARE_MOVEMENT_DOWN
 */
HardwareMovement elev_set_motor_dir(elevator* el);

/**
 * @brief Updates the directions. The previous direction is set
 * equal to the current direction and the current direction is set
 * by @c elev_set_motor_dir.
 * 
 * @param[in, out] el The elevator.
 */
void elev_update_dir(elevator* el);

/**
 * @brief Secures that the elevator does not move past
 * its range by changing the motor direction when it reaches 
 * the top/bottom floor.
 * @param[in] el The elevator.
 */
void elev_control_range(elevator* el);




#endif // ##ifndef ELEVATOR_H
