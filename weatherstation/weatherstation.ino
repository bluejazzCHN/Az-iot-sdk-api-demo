#include <OledDisplay.h>
#include "Arduino.h"
#include "HTS221Sensor.h"
// #include "DHT.h"

// #define DHTPIN 2
// #define DHTTYPE DHT11
unsigned char BMP[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 192, 192, 224, 240, 56, 12, 192, 240, 224, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 224, 224, 224, 224, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 224, 248, 252, 254, 255, 255, 63, 15, 3, 64, 248, 254, 255, 255, 255, 255, 255, 252, 248, 224, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 240, 252, 127, 31, 3, 3, 15, 127, 254, 240, 192, 0, 0, 0, 0, 8, 28, 28, 28, 28, 156, 220, 252, 124, 60, 28, 0, 0, 0, 252, 252, 248, 0, 0, 0, 0, 0, 0, 252, 252, 248, 0, 0, 0, 0, 252, 252, 252, 112, 56, 28, 28, 28, 0, 128, 224, 240, 248, 28, 28, 12, 12, 28, 248, 248, 240, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 224, 248, 252, 255, 255, 255, 255, 63, 15, 3, 0, 0, 0, 0, 0, 0, 3, 7, 15, 31, 63, 127, 255, 255, 255, 255, 255, 252, 240, 224, 128, 0, 0, 0, 0, 0, 0, 64, 112, 124, 127, 31, 7, 7, 7, 7, 7, 7, 7, 7, 31, 127, 126, 120, 64, 0, 96, 112, 120, 126, 127, 103, 99, 97, 96, 96, 96, 0, 0, 0, 63, 127, 127, 240, 224, 224, 96, 96, 56, 127, 127, 127, 0, 0, 0, 0, 127, 127, 127, 0, 0, 0, 0, 0, 0, 15, 63, 127, 123, 243, 227, 227, 227, 227, 99, 99, 35, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 8, 8, 8, 8, 8, 12, 12, 12, 12, 12, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// DHT dht(DHTPIN, DHTTYPE);
// int redPin =20;

DevI2C *i2c;
HTS221Sensor *sensor;
float humidity = 0;
float temperature = 0;
unsigned char id;

void setup()
{
    Screen.init();
    // dht.begin();
    i2c = new DevI2C(D14, D15);
    sensor = new HTS221Sensor(*i2c);
    // init the sensor
    sensor->init(NULL);
    delay(3000);
}
void loop()
{

    sensor->enable();
    // read id
    sensor->readId(&id);

    sensor->getHumidity(&humidity);

    sensor->getTemperature(&temperature);
    char t[10];
    char h[10];
    sprintf(h, "Humi: %.1f", humidity);
    sprintf(t, "Temp: %.0f", temperature);

    int resultCode = stationDisplay(t,h);

    // Screen.print(0,"Weather Station:");
    // Screen.print(2,t);
    // Screen.print(3,h);
 
    delay(5000);
    // draw a bitmap to the screen
    Screen.draw(0, 0, 128, 8, BMP);
    sensor->disable();
    // reset
    sensor->reset();
    delay(5000);
    // clean screen ready for next loop
    Screen.clean();
}

int stationDisplay(char t[], char h[])
{
    try
    {
        Screen.print(0, "Weather Station:");
        Screen.print(2, t);
        Screen.print(3, h);
    }
    catch (int)
    {
        return 0;
    }
    return 1;
}