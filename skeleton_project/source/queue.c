#include "queue.h"

void queue_clear_all(elevator* el){
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
        for (int j = 0; j < HARDWARE_NUMBER_OF_BUTTONS;j++){
            el->queue[i][j]=0;
        }
    }
    el->queue[HARDWARE_NUMBER_OF_FLOORS-1][0]=-1;
    el->queue[0][2]=-1;
}

void queue_update(elevator* el){
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
        for (int j = 0; j < 3; i++){
            if (hardware_read_order(i, j)){ //Sjekker alle kombinasjoner av etasjer og bestillingstyper
                el->queue[i][j] = 1; //print når oppdateringen skjer
            }
        }
    }

    el->queue[HARDWARE_NUMBER_OF_FLOORS-1][0]=-1;
    el->queue[0][2]=-1;
}

void queue_set_light(elevator* el){
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
        for (int j = 0; j < 3; i++){
            if (hardware_read_order(i, j)){ //Sjekker alle kombinasjoner av etasjer og bestillingstyper
                hardware_command_order_light(i, HARDWARE_ORDER_INSIDE, 1);
            }
        }
    }
}

/*void queue_clear(elevator* el){
    el->queue[el->currentfloor][]=0;

}*/