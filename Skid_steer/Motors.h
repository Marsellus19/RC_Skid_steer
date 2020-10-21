#include <Arduino.h>

class motor{
private:

    byte pwm, dir1, dir2;

    void begin(){
        pinMode(pwm, OUTPUT);
        pinMode(dir1, OUTPUT);
        pinMode(dir2, OUTPUT);
    }

public:

    motor(byte pwm, byte dir1, byte dir2){
        this-> pwm = pwm;
        this-> dir1 = dir1;
        this-> dir2 = dir2;
        begin();
    }

    void turn(int input_velocity){
        int velocity = map(input_velocity, 950, 2050, -255, 255);

        if(input_velocity > 1505){
            digitalWrite(dir1, LOW);
            digitalWrite(dir2, HIGH);
            analogWrite(pwm, velocity);
        }
        else if(input_velocity < 1495){
            digitalWrite(dir1, HIGH);
            digitalWrite(dir2, LOW);
            analogWrite(pwm, abs(velocity));
        }
        else{
            digitalWrite(dir1, LOW);
            digitalWrite(dir2, LOW);
            digitalWrite(pwm, LOW);
        }
    }
};
