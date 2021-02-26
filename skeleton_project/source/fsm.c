#include "fsm.h"

//Funksjon som setter initalbetingelser for heisen
void fsm_init(elevator* el){
   el->state = INIT; //Heisen starter i initialiseringen
   el->currentfloor = get_current_floor(el);
   queue_clear_all(el);
}

//En tilstandsswitch som endrer heisens tilstand
int fsm_switch(elevator* el){

    switch(el->state){
        case INIT:
            if (elev_init(el)){
                el->state = IDLE;
            }
            break;
        case IDLE:
            queue_update(el);
            if(hardware_read_stop_signal()){
                el->state = EMERGENCY_STOP;
            }
            else{
                if(queue_orders_at_floor(el)){
                el->state = DOOR_OPEN;
                }
                else if(queue_check_orders_above(el) || queue_check_orders_below(el)){
                    el->state = MOVE;
                }
                else{
                    el->state = IDLE;
                }
            }
            
            break;
            

    }
}