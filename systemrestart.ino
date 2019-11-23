#include "Arduino.h"

int btnAState;
int btnBState;

void setup() {
  pinMode(USER_BUTTON_A, INPUT);
  pinMode(USER_BUTTON_B, INPUT);

  btnAState = digitalRead(USER_BUTTON_A);
  btnBState = digitalRead(USER_BUTTON_B);

  Screen.init();
  Screen.print(0, "System Func: ");
  Screen.print(1, "Press A to reboot", true);
  Screen.print(3, "Press B to sleep", true);
}

void loop() {
  while (1)
  {
    // press button A to reboot
    if (btnAState == HIGH && digitalRead(USER_BUTTON_A) == LOW)
    {
      Screen.clean();
      Screen.print("Reboot....", true);
      SystemReboot();
    }

    // press button B to sleep 5 seconds, and then restart
    if (btnBState == HIGH && digitalRead(USER_BUTTON_B) == LOW)
    {
      Screen.clean();
      Screen.print(1, "Sleep 5 seconds and then restart", true);
      SystemStandby(5);
    }
  }

  delay(100);
}
