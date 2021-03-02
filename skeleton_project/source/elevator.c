#include "elevator.h"


void elev_init(elevator* el){
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1); //?????
    }

    
    //hvis den ikke er i en etasje skal den kjøre nedover og stoppe i nærmeste etasje
    while(get_current_floor(el) == -1){
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    }
    hardware_command_movement(HARDWARE_MOVEMENT_STOP); //Heisen skal stå i ro

    el->current_dir = HARDWARE_MOVEMENT_STOP; 
    el->currentfloor = get_current_floor(el);
    queue_clear_all(el);

    el->state = IDLE;
}


int get_current_floor(elevator *el){
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
        if (hardware_read_floor_sensor(i)){
            return i;
        }
    }
    return -1;
}

/*int elev_at_floor(elevator* el){
    if(hardware_read_floor_sensor(0) || hardware_read_floor_sensor(1) || hardware_read_floor_sensor(2) || hardware_read_floor_sensor(3)){
        return 1;
    }
    return 0;
}*/

HardwareMovement elev_set_motor_dir(elevator* el){
    switch(el->previous_dir){
        case HARDWARE_MOVEMENT_UP:
            if(queue_check_orders_above(el)){
                return HARDWARE_MOVEMENT_UP;
            }
            else if(queue_check_orders_below(el)){
                return HARDWARE_MOVEMENT_DOWN;
            }
            break;
        case HARDWARE_MOVEMENT_DOWN:
            if(queue_check_orders_below(el)){
                return HARDWARE_MOVEMENT_DOWN;
            }
            else if(queue_check_orders_above(el)){
                return HARDWARE_MOVEMENT_UP;
            }
            break;
        case HARDWARE_MOVEMENT_STOP:
            if(queue_check_orders_above(el)){
                return HARDWARE_MOVEMENT_UP;
            }
            else if(queue_check_orders_below(el)){
                return HARDWARE_MOVEMENT_DOWN;
            }
            break;
        
    }
}

void elev_control_range(elevator* el){
    /* Code block that makes the elevator go up when it reach the botton*/
    if(hardware_read_floor_sensor(0)){
        hardware_command_movement(HARDWARE_MOVEMENT_UP);
    }

    /* Code block that makes the elevator go down when it reach the top floor*/
    if(hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    }
}


void elev_set_floor_indicator(elevator* el){
    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        if(hardware_read_floor_sensor(f)){
            hardware_command_floor_indicator_on(f);
        }
    }
    el->currentfloor = get_current_floor(el);
}

