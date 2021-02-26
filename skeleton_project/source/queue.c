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

void queue_print(elevator* el){
    printf("\n");
    for(int i = 0; i < HARDWARE_NUMBER_OF_BUTTONS; i++){
        for(int j = 0; j < HARDWARE_NUMBER_OF_FLOORS; j++){
            printf("%d\t", el->queue[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}


int queue_check_orders_above(elevator* el){
    for(int i = el->currentfloor + 1; i < HARDWARE_NUMBER_OF_FLOORS; i++){
        for(int j = 0; j < HARDWARE_NUMBER_OF_BUTTONS; j++){
            if(el->queue[i][j] == 1){
                return 1;
            }
        }
    }
    return 0;
}

int queue_check_orders_below(elevator* el){
    for(int i = 0; i < el->currentfloor; i++){
        for(int j = 0; j < HARDWARE_NUMBER_OF_BUTTONS; j++){
            if(el->queue[i][j] == 1){
                return 1;
            }
        }
    }
    return 0;
}

int queue_orders_at_floor(elevator* el){
    for(int i = 0; i < HARDWARE_NUMBER_OF_BUTTONS; i++){
        if(el->queue[el->currentfloor][i]){
            return 1;
        }
    }
    return 0; 
}

void queue_clear_executed_order(elevator* el){
    for(int i = 0; i < HARDWARE_NUMBER_OF_BUTTONS; i++){
        el->queue[el->currentfloor][i]=0;
    }

    el->queue[HARDWARE_NUMBER_OF_FLOORS-1][0]=-1;
    el->queue[0][2]=-1;
}