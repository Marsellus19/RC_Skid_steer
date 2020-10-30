#ifndef neopixel_h
#define neopixel_h

#ifdef NEOPIXEL_SUPPORT

#include <Adafruit_NeoPixel.h>


Adafruit_NeoPixel lights(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void on(){
    for(uint8_t i=0; i<NEOPIXEL_COUNT; i++) lights.setPixelColor(i, 255, 255, 255);
    lights.setPixelColor(1, 255, 255, 255);
    lights.setBrightness(NEOPIXEL_BRIGHTNESS);
    lights.show();
}

void off(){
    lights.clear();
    lights.show();
}

void switch_lights_on(){
    #ifdef NEOPIXEL_RC_CONTROL
        if(ppm.channel(NEOPIXEL_CONTROL_CHANNEL) > 1250) on();
        else off();
    #else
        on();
    #endif

}

#endif /* NEOPIXEL_SUPPORT */

#endif /* neopixel_h */
