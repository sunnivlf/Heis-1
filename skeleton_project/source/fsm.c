#include "fsm.h"

//En tilstandsswitch som endrer heisens tilstand
int fsm_switch(elevator* el){

    while(1){

        if(hardware_read_stop_signal()){
            el->state = EMERGENCY_STOP;
        }

        elev_set_floor_indicator(el); //oppdaterer etasjelys og currentfloor kontinuerlig
        queue_update(&el);
        queue_set_light(&el);

        switch(el->state){
            case IDLE:
                fsm_idle(el);
                break;
            case MOVE:
                break;
            case DOOR_OPEN:
                break;
            case EMERGENCY_STOP:
                break;
        }
    } 

} 

void fsm_idle(elevator* el){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    if(queue_orders_at_floor(el)){
    el->state = DOOR_OPEN;
    }
    else if(queue_check_orders_above(el) || queue_check_orders_below(el)){
        el->state = MOVE;
    }
}

void fsm_move(elevator* el){
    elev_control_range(el);
    /*if(queue_take_order(el)){

    }*/
}


void fsm_door_open(elevator* el){

}

void fsm_emergency_stop(elevator* el){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    hardware_command_stop_light(1);
}