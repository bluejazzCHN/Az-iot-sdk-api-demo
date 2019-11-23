#include "arduino.h"
#include "oleddisplay.h"
volatile byte led = LOW;
volatile byte interruptOn = HIGH;

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
    led = !led;
    Screen.print("Button A is pressed.");
    delay(2000);
    Screen.clean();
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