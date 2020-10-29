
#ifndef receiver_h
#define receiver_h

#include <PinChangeInt.h>



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
    pwm_val = new volatile uint16_t[++channels];
    for(int i=0; i<=++channels; i++) pwm_val[i] = 1500;
}


class Ppm{
    volatile uint16_t *channel_val;
public:
    void attach(uint8_t pin, uint8_t channels){
        attach_ppm(pin, channels);
        channel_val = pwm_val;
    }


    uint16_t channel(uint8_t channel_number){
        return channel_val[channel_number];
    }


    void print_val(){
        for(uint8_t i= 1 ; i <= number_of_channels ; i++) Serial.print("\tch" + String(i) + ": " + String(channel(i)));
        //Serial.print("\n");
    }

}ppm;

#endif /* receiver_h */
