#include <Arduino.h>
#line 1 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\externalinterrupts.ino"
#include "arduino.h"
#include "oleddisplay.h"
volatile byte led = LOW;
volatile byte interruptOn = HIGH;

#line 6 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\externalinterrupts.ino"
void setup();
#line 23 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\externalinterrupts.ino"
void loop();
#line 28 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\externalinterrupts.ino"
void blink_and_display();
#line 36 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\externalinterrupts.ino"
void interruptSwitch();
#line 6 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\externalinterrupts.ino"
void setup()
{
    // Use USER_BUTTON_B to control USER_BUTTON_A
    attachInterrupt(USER_BUTTON_B, interruptSwitch, FALLING);
    // Use USER_BUTTON_A to control LED_USER
    if (interruptOn)
    {
        attachInterrupt(USER_BUTTON_A, blink_and_display, CHANGE);
    }
    Screen.init();
    char buf[100];
    sprintf(buf, "1.press B_B init B_A", 1);
    Screen.print(1, buf);
    sprintf(buf, "2.press B_A change LED", 2);
    Screen.print(2, buf);
}

void loop()
{
    digitalWrite(LED_USER, led);
}

void blink_and_display()
{
    Screen.clean();
    led = !led;
    Screen.print("Button A is pressed.");
    delay(5000);
}

void interruptSwitch()
{
    interruptOn = !interruptOn;
    if (interruptOn)
    {
        attachInterrupt(USER_BUTTON_A, blink_and_display, CHANGE);
    }
    else
    {
        detachInterrupt(USER_BUTTON_A);
    }
}
