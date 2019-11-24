# 1 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\systemrestart.ino"
# 2 "d:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\systemrestart.ino" 2

int btnAState;
int btnBState;

void setup() {
  pinMode(USER_BUTTON_A, 0x1);
  pinMode(USER_BUTTON_B, 0x1);

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
    if (btnAState == 0x1 && digitalRead(USER_BUTTON_A) == 0x0)
    {
      Screen.clean();
      Screen.print("Reboot....", true);
      delay(2000);
      SystemReboot();
    }

    // press button B to sleep 5 seconds, and then restart
    if (btnBState == 0x1 && digitalRead(USER_BUTTON_B) == 0x0)
    {
      Screen.clean();
      Screen.print(1, "Sleep 5 seconds and then restart", true);
      SystemStandby(5);
    }
  }

  delay(100);
}
