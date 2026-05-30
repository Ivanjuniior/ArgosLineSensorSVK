#include <ArgosLineSensorSVK.h>

ArgosLineSensorSVK sensor;

void setup() {

    Serial.begin(115200);

    sensor.begin(
        32,
        33,
        25,
        35
    );
}

void loop() {

    sensor.read();

    Serial.print("S1:");
    Serial.print(sensor.raw(0));

    Serial.print(" S2:");
    Serial.print(sensor.raw(1));

    Serial.print(" S3:");
    Serial.print(sensor.raw(2));

    Serial.print(" S4:");
    Serial.print(sensor.raw(3));

    Serial.print(" S5:");
    Serial.print(sensor.raw(4));

    Serial.print(" S6:");
    Serial.print(sensor.raw(5));

    Serial.print(" S7:");
    Serial.print(sensor.raw(6));

    Serial.print(" S8:");
    Serial.println(sensor.raw(7));

    delay(100);
}