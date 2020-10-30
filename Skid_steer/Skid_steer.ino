
#include <Arduino.h>
#include <Servo.h>
#include "Config.h"
#include "mixer.h"
#include "receiver.h"
#include "motor.h"
#include "neopixel.h"
//#include "debug.h"

Motor left, right;
Servo arm_servo, bucket_servo;

void setup() {
    left.attach(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_DIR_1_PIN, LEFT_MOTOR_DIR_2_PIN);
    right.attach(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_DIR_1_PIN, RIGHT_MOTOR_DIR_2_PIN);
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

    switch_lights_on();
}
