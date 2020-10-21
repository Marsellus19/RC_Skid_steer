
#include <Arduino.h>
#include "receiver.h"
#include "motor.h"
//#include "debug.h"

Motor left, right;

void setup() {
    left.attach(3, 2, 4);
    right.attach(5, 7, 8);
    ppm.attach(11, 8);
    Serial.begin(57600);
}



void loop() {
    //ppm.print_val();

    //right.turn(ppm.channel(2));
    //left.turn(ppm.channel(1));
}
