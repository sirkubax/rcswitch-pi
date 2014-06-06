/*
 Usage: ./send <systemCode> <unitCode> <command>
 Command is 0 for OFF and 1 for ON
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;
    char* systemCode = argv[1];
    int unitCode = atoi(argv[2]);
    int command  = atoi(argv[3]);
    
    if (wiringPiSetup () == -1) return 1;
	printf("Paruje przykladowym kodem");
	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(PIN);

	//intialize    
 	mySwitch.setPulseLength(710); 
 	mySwitch.setProtocol(2); 

 	//paruj przykladowym kodem
	while(1) {
 		mySwitch.send(250376579, 32); 
       }

    return 0;
}
