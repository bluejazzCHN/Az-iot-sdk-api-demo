# AZ-IOT-SDK-Api-Demo with Arduino
## Requirement

1. [AZ3166 IOT Developer Kit](https://www.seeedstudio.com/AZ3166-IOT-Developer-Kit.html)
2. [Azure subscription](https://ms.portal.azure.com)
3. [VScode dev tool](https://code.visualstudio.com/)
4. [API reference](https://microsoft.github.io/azure-iot-developer-kit/docs/projects/)
5. [ AZ3166 IOT Developer Kit](https://www.seeedstudio.com/AZ3166-IOT-Developer-Kit.html)

## API Demo
1. oleddisplay.ino -- how to control screan to display text or img
2. externalinterrupts.ino -- how to use external interrupt to response in realtime
3. systemrestart.ino -- how to use system api to restart device on conditions
4. weatherstation.ino -- use internal display and external DHT sensor. program use arduino internal pin 5 mapping to external pin 4 (microbit extend pad). [reference](https://jeremylindsayni.wordpress.com/2017/11/11/using-the-mxchip-az3166-azure-devkit-with-arduino-coding-with-pin-names-instead-of-numbers/): doc/az 3166 map

## Privacy Statement
The [Microsoft Enterprise and Developer Privacy Statement](https://www.microsoft.com/en-us/privacystatement/EnterpriseDev/default.aspx) describes the privacy statement of this software.

## Tips
1.when uploading code to device ,please comfirm **Only One** ino file include setup() or loop() at same time is exiting in current workbench. Fix the problem in future.
2.c_cpp_properties.json
```
{
    "configurations": [
        {
            "name": "Win32",
            "defines": [
                "ARDUINO=10800"
            ],
            "includePath": [
                "${workspaceFolder}",
                "C:\\Users\\SJ\\AppData\\Local\\Arduino15\\packages\\AZ3166\\tools\\**",
                "C:\\Users\\SJ\\AppData\\Local\\Arduino15\\packages\\AZ3166\\hardware\\stm32f4\\1.6.3\\**",
                "C:\\Users\\SJ\\AppData\\Local\\Arduino15\\packages\\AZ3166\\hardware\\stm32f4\\1.6.5\\**",
                "D:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\include\\**"   here is path that is external libary existed generally include *.cpp and *.h file;
            ],
            "forcedInclude": [
                "C:\\Users\\SJ\\AppData\\Local\\Arduino15\\packages\\AZ3166\\hardware\\stm32f4\\1.6.3\\cores\\arduino\\Arduino.h",
                "C:\\Users\\SJ\\AppData\\Local\\Arduino15\\packages\\AZ3166\\hardware\\stm32f4\\1.6.5\\cores\\arduino\\Arduino.h",
                "D:\\WorkFolder\\Hardware\\aziot\\SDK_Demo\\include\\DHT.h"  here is header file in C or C++
            ],
            "intelliSenseMode": "clang-x64",
            "cStandard": "c11",
            "cppStandard": "c++17"
        }
    ],
    "version": 4
}
```



## Contact Me
songjiangzhang@hotmail.com