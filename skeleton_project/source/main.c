#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "elevator.h"
#include "fsm.h" //trenger vi kun inkludere denne headerfilen???
#include "timer.h"


int main(){
    printf("=== Heis-prosjekt ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevator el;
    fsm_init(&el);
    fsm_switch(&el);
    
    return 0;
}
