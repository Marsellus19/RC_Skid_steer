#include <Arduino.h>

void print_val(){
    for(int i= 1 ; i <= channels ; i++) Serial.print("\tch" + String(i) + ": " + String(pwm_val[i]));
    Serial.print("\n");
}
