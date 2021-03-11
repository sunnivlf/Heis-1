/**
 * @file
 * @brief The finit state machine.
 */
#include "timer.h"
#include "queue.h"

/**
 * @brief Initializes the elevator and moves it to a defined state.
 * @param[in, out] el The elevator.
 */
void fsm_init(elevator* el);

/**
 * @brief Contains the logic for the finit state machine.
 * 
 * @param[in, out] el The elevator.
 * 
 * @return ???
 */
int fsm_switch(elevator* el);

/**
 * @brief IDLE. If there is a request at the floor the elevator
 * is currently at, the elevator enters state @c DOOR_OPEN. 
 * Otherwise if there is a request above or below the elevator
 * enters state @c MOVE.
 * 
 * @param[in, out] el The elevator. 
 */
void fsm_idle(elevator* el);

/**
 * @brief MOVE. Gets the new direction and starts the motor.
 * If the elevator arrives a floor with a request it should take
 * the elevator enters state @c IDLE.
 * 
 * @param[in, out] el The elevator.
 * 
 */
void fsm_move(elevator* el);

/**
 * @brief DOOR OPEN. Commands door open, starts the timer and
 * checks for any obstructions. Closes the door when the time 
 * is up and clears excecuted order. Then enters state @c IDLE.
 * 
 * @param[in, out] el The elevator.
 * 
 */
void fsm_door_open(elevator* el);

/**
 * @brief EMERGENCY STOP. Stops the elevator and sets the stop light.
 * The queue of requests is cleared. If the elevator is at a floor the 
 * door is opened and when the stop button is released the 
 * elevator enters state @c DOOR_OPEN. Otherwise it awaits until 
 * any requests is made, and then enters @c MOVE.
 * 
 * @param[in, out] el The elevator.
 */
void fsm_emergency_stop(elevator* el);
