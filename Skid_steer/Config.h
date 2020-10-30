//===========================================================================
//=========================== RC RECEIVER TYPE ==============================
//===========================================================================

/**
 * PPM Receiver
 *
 */
#define PPM_RECEIVER

#ifdef PPM_RECEIVER
    #define PPM_PIN 11
    #define PPM_NUMBER_OF_CHANNELS 8
#endif


/**
 * PWM Receiver
 *
 */
//#define PWM_RECEIVER

#ifdef PWM_RECEIVER
    #define PWM_NUMBER_OF_CHANNELS 5
    #define PWM_CH_1_PIN 2
    #define PWM_CH_2_PIN 3
    //#define PWM_CH_3_PIN 4
    // ...
    // Add more if needed
#endif


/**
 * SBUS Receiver
 *
 */
//#define SBUS_RECEIVER

#ifdef SBUS_RECEIVER
    #define SBUS_NUMBER_OF_CHANNELS 8
#endif



//===========================================================================
//============================== MOTOR DRIVER ===============================
//===========================================================================

// The deadband prevents the motors from 'buzzing' when stationary.
// It adds a dead spot in the stick centre
// This is especially important when using analog receiver interfaces, like ppm, or pwm.
#define MOTOR_DEADBAND 10 // µs

/**
 * The L293D is a cheap and great H-bridge, however it takes up 6 digital pins for controlling it
 * and it can get quite hot due to a low current rating.
 * It is also difficult to source it in an smd package, and there aren't many dev boards available.
 * So probably use it only if you are putting the electronics on a perf-board.
 */
#define L293D_MOTOR_DRIVER

#ifdef L293D_MOTOR_DRIVER
    #define LEFT_MOTOR_PWM_PIN 3
    #define LEFT_MOTOR_DIR_1_PIN 2
    #define LEFT_MOTOR_DIR_2_PIN 4

    #define RIGHT_MOTOR_PWM_PIN 5
    #define RIGHT_MOTOR_DIR_1_PIN 7
    #define RIGHT_MOTOR_DIR_2_PIN 8
#endif



//===========================================================================
//============================ ADAFRUIT NEOPIXEL ============================
//===========================================================================
/**
 * Enable support for the adafruit neopixel leds.
 *
 * They have to be connected to a pwm capable pin.
 * On a typical, atmega 328 based Arduino (Uno, Nano, etc.), those pins are:
 *      3   5   6   9   10  11
 * Either one of them will work
 */

#define NEOPIXEL_SUPPORT

#ifdef NEOPIXEL_SUPPORT
    #define NEOPIXEL_COUNT 2
    #define NEOPIXEL_PIN 9

    // Specify the brightness of the pixels. It is probably a good idea to turn them down a bit.
    // They're pretty bright at full power. Especially for indors use.
    #define NEOPIXEL_BRIGHTNESS 64 // 0...255

    // Control the lights with an auxilary channel.
    // If not enabled, the lights will default to being permanently on.
    #define NEOPIXEL_RC_CONTROL
    #define NEOPIXEL_CONTROL_CHANNEL 5
#endif
