
#include <Arduino.h>
#include <Servo.h>
#include "mixer.h"
#include "receiver.h"
#include "motor.h"
#include "neopixel.h"
//#include "debug.h"

Motor left, right;
Servo arm_servo, bucket_servo;

void setup() {
    left.attach(3, 2, 4);
    right.attach(5, 7, 8);
    ppm.attach(11, 8);
    arm_servo.attach(10);
    lights.begin();
    lights.show();
    Serial.begin(57600);
}



void loop() {
    ppm.print_val();

    left.turn(mix.add( ppm.channel(1), ppm.channel(2) ));
    right.turn(mix.substract( ppm.channel(1), ppm.channel(2) ));

    arm_servo.writeMicroseconds(mix.reverse( ppm.channel(3) ));

    if(ppm.channel(5) > 1500) turn_lights_on();
    else turn_lights_off();
}
