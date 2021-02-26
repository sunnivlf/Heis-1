#include "elevator.h"


int elev_init(elevator* el){
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
    el->motor_dir = HARDWARE_MOVEMENT_STOP; 
    return 1;
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
    if (el->previousfloor < el->currentfloor){
        
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


