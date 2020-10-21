
#ifndef motors_h
#define motors_h

#define deadband 5

class Motor{
private:

    uint8_t pwm_pin, dir1_pin, dir2_pin;

    void begin(){
        pinMode(pwm_pin, OUTPUT);
        pinMode(dir1_pin, OUTPUT);
        pinMode(dir2_pin, OUTPUT);
    }

public:

    void attach(uint8_t pwm_pin, uint8_t dir1_pin, uint8_t dir2_pin){
        this-> pwm_pin = pwm_pin;
        this-> dir1_pin = dir1_pin;
        this-> dir2_pin = dir2_pin;
        begin();
    }


    void turn(uint16_t pwm){
        int16_t velocity = map(pwm, 950, 2050, -255, 255);

        if(velocity > deadband){
            digitalWrite(dir1_pin, LOW);
            digitalWrite(dir2_pin, HIGH);
            analogWrite(pwm_pin, velocity);
        }
        else if(velocity < -deadband){
            digitalWrite(dir1_pin, HIGH);
            digitalWrite(dir2_pin, LOW);
            analogWrite(pwm_pin, abs(velocity));
        }
        else{
            digitalWrite(dir1_pin, LOW);
            digitalWrite(dir2_pin, LOW);
            digitalWrite(pwm_pin, LOW);
        }
    }
};

#endif /* motors_h */
