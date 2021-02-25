#include "elevator.h"


int elev_init(){
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    while(1){
        for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
            if (hardware_read_floor_sensor(i)){
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);
                break;
            }
        }
    
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
        if (hardware_read_floor_sensor(0)){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            break;
        }
        
    } 

    return(1);
}

void set_prevoius_floor(elevator *el){

}

void set_current_floor(elevator *el){

}

HardwareMovement elev_set_motor_dir(elevator* el){
    if (el->previousfloor < el->currentfloor){
        
    }
}



