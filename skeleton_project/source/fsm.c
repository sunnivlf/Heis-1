#include "fsm.h"

int fsm_switch(elevator* el){

    switch(el->state){
        case INIT:
            if (elev_init()){
                el->state = IDLE;
            }
            break;
        case IDLE:
            queue_update(el);
            

    }
}