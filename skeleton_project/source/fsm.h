#include "timer.h"
#include "queue.h"

int fsm_switch(elevator* el);
void fsm_idle(elevator* el);
void fsm_move(elevator* el);
void fsm_door_open(elevator* el);
void fsm_emergency_stop(elevator* el);
