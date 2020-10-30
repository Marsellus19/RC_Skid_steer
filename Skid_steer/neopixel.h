#include <Adafruit_NeoPixel.h>

#define PIXEL_COUNT 2
#define PIXEL_PIN 9
#define PIXEL_BRIGHTNESS 64

Adafruit_NeoPixel lights(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void turn_lights_on(){
    for(uint8_t i=0; i<PIXEL_COUNT; i++) lights.setPixelColor(i, 255, 255, 255);
    lights.setPixelColor(1, 255, 255, 255);
    lights.setBrightness(PIXEL_BRIGHTNESS);
    lights.show();
}


void turn_lights_off(){
    lights.clear();
    lights.show();
}
