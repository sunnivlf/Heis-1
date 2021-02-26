#ifndef QUEUE_H
#define QUEUE_H

#include "elevator.h"

void queue_clear_all(elevator* el);
void queue_update();
void queue_set_light(elevator* el);
void queue_print(elevator* el);
int queue_check_orders_above(elevator* el);
int queue_check_orders_below(elevator* el);
int queue_orders_at_floor(elevator* el);
void queue_clear_executed_order(elevator* el);

//void queue_clear(elevator* el);




#endif // #ifndef QUEUE_H

//el->motor_dir = elev_choose_dir;
