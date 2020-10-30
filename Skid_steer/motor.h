
#ifndef motors_h
#define motors_h


class Motor{
private:

    uint8_t pwm_pin, dir1_pin, dir2_pin;

    void begin(){
        #ifdef L293D_MOTOR_DRIVER
            pinMode(pwm_pin, OUTPUT);
            pinMode(dir1_pin, OUTPUT);
            pinMode(dir2_pin, OUTPUT);
        #endif
    }

public:

    void attach(uint8_t pwm_pin, uint8_t dir1_pin, uint8_t dir2_pin){
        #ifdef L293D_MOTOR_DRIVER
            this-> pwm_pin = pwm_pin;
            this-> dir1_pin = dir1_pin;
            this-> dir2_pin = dir2_pin;
        #endif
        
        begin();
    }


    void turn(uint16_t pwm){
        int16_t velocity = map(pwm, 1000, 2000, -255, 255);

        if(velocity > MOTOR_DEADBAND){
            digitalWrite(dir1_pin, LOW);
            digitalWrite(dir2_pin, HIGH);
            analogWrite(pwm_pin, velocity);
        }
        else if(velocity < -MOTOR_DEADBAND){
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
