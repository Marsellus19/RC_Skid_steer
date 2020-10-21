#include <PinChangeInterrupt.h>

class Ppm{


};


volatile uint64_t prev_time;
//volatile uint16_t *pwm_val = NULL;
volatile uint16_t pwm_val[8 +1];

volatile uint16_t pulse;
volatile uint8_t pulse_no;

uint8_t number_of_channels;
uint8_t ppm_pin;
const uint16_t blank = 3000;


void ppm_isr(void){
    uint64_t curr_time = micros();
    pulse = curr_time - prev_time;
    prev_time = curr_time;

    if(pulse > blank){
        pulse_no = 0;
    }
    else{
        pulse_no++;
        if(pulse_no <= number_of_channels){
            pwm_val[pulse_no] = pulse;
        }
    }
}


void attach_ppm(uint8_t pin, uint8_t channels){
    ppm_pin = pin;
    number_of_channels = channels;
    pinMode(ppm_pin, INPUT);
    attachPinChangeInterrupt(ppm_pin, ppm_isr, FALLING);
}
