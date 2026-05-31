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

    for(int i = 0; i < 8; i++) {

        Serial.print(sensor.raw(i));
        Serial.print(" ");
    }

    Serial.println();

    delay(100);
}