# 1 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\externalinterrupts.ino"
# 2 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\externalinterrupts.ino" 2
# 3 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\externalinterrupts.ino" 2
volatile byte led = 0x0;
volatile byte interruptOn = 0x1;

void setup()
{
    // Use USER_BUTTON_B to control USER_BUTTON_A
    attachInterrupt(USER_BUTTON_B, interruptSwitch, 3);
    // Use USER_BUTTON_A to control LED_USER
    if (interruptOn)
    {
        attachInterrupt(USER_BUTTON_A, blink_and_display, 2);
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
        attachInterrupt(USER_BUTTON_A, blink_and_display, 2);
    }
    else
    {
        detachInterrupt(USER_BUTTON_A);
    }
}
