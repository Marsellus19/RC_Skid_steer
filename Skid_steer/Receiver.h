
#ifndef receiver_h
#define receiver_h

#include <PinChangeInterrupt.h>



volatile uint64_t prev_time;
volatile uint16_t *pwm_val;

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
    pwm_val = new uint16_t[++channels];
}


class Ppm{
public:
    volatile uint16_t *channel_pwm;
    Ppm(){
        channel_pwm = pwm_val;
    }


    uint16_t channel(uint8_t channel_no){
        return channel_pwm[channel_no];
    }


    void print_val(){
        for(uint8_t i= 1 ; i <= number_of_channels ; i++) Serial.print("\tch" + String(i) + ": " + String(pwm_val[i]));
        Serial.print("\n");
    }


    void attach(uint8_t pin, uint8_t no_of_channels){
        attach_ppm(pin, no_of_channels);
    }

}ppm;

#endif /* receiver_h */
