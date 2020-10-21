
#include <Arduino.h>
#include "Receiver.h"
#include "Motors.h"
//#include "Debug.h"

motor right(5, 7, 8);
motor left(3, 2, 4);

void setup() {
    Serial.begin(57600);
    attach_ppm(11, 8);
}

void loop() {
    //print_val();

    //right.turn(ppm.channel(2));
    //left.turn(ppm.channel(1));
    //right.turn(pwm_val[2]);
    //left.turn(pwm_val[1]);
}
