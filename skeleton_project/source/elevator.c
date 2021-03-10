#include "elevator.h"


void elev_init(elevator* el){
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1); //?????
    }

    
    //hvis den ikke er i en etasje skal den kjøre nedover og stoppe i nærmeste etasje
    while(elev_get_current_floor() == -1){
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    }
    hardware_command_movement(HARDWARE_MOVEMENT_STOP); //Heisen skal stå i ro

    queue_clear_all_lights(el);
    el->current_dir = HARDWARE_MOVEMENT_STOP; 
    el->currentfloor = elev_get_current_floor();
    //elev_set_floor_indicator(el); //oppdaterer etasjelys og currentfloor kontinuerlig
    queue_clear_all(el);

    el->state = IDLE;
}


int elev_get_current_floor(){
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
        if (hardware_read_floor_sensor(i)){
            return i;
        }
    }
    return -1;
}


HardwareMovement elev_set_motor_dir(elevator* el){
    switch(el->previous_dir){
        case HARDWARE_MOVEMENT_UP:
            if(queue_orders_above(el)){
                return HARDWARE_MOVEMENT_UP;
            }
            else if(queue_orders_below(el)){
                return HARDWARE_MOVEMENT_DOWN;
            }
            break;
        case HARDWARE_MOVEMENT_DOWN:
            if(queue_orders_below(el)){
                return HARDWARE_MOVEMENT_DOWN;
            }
            else if(queue_orders_above(el)){
                return HARDWARE_MOVEMENT_UP;
            }
            break;
        case HARDWARE_MOVEMENT_STOP:
            if(queue_orders_above(el)){
                return HARDWARE_MOVEMENT_UP;
            }
            else if(queue_orders_below(el)){
                return HARDWARE_MOVEMENT_DOWN;
            }
            break;
        
    }
}

void elev_update_dir(elevator* el){
    el->previous_dir = el->current_dir;
    el->current_dir = elev_set_motor_dir(el);
}

void elev_control_range(elevator* el){
    // Code block that makes the elevator go up when it reach the botton
    if(hardware_read_floor_sensor(0)){
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        el->current_dir = HARDWARE_MOVEMENT_UP; // kanskje endre current_dir til next
    }
    /*if(hardware_read_floor_sensor(0)){
        hardware_command_movement(HARDWARE_MOVEMENT_UP);
    }*/

    if(hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        el->current_dir = HARDWARE_MOVEMENT_DOWN;
    }
    // Code block that makes the elevator go down when it reach the top floor
    /*if(hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    }*/
}


void elev_set_floor_indicator(elevator* el){
    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        if(hardware_read_floor_sensor(f)){
            hardware_command_floor_indicator_on(f);
        }
    }  
}

void elev_set_current_floor(elevator* el){
    int temp = elev_get_current_floor();

    if (temp== -1){ //gjør slik at curentfloor ikke blir satt lik -1
        return;
    }
    
    el->previousfloor = el->currentfloor;
    el->currentfloor = temp;
}

