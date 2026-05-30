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

    Serial.println();
    Serial.println("CALIBRANDO...");

    sensor.calibrate(5000);

    Serial.println("PRONTO");
}

void loop() {

    sensor.read();

    for(int i = 0; i < 8; i++) {

        Serial.print("N");
        Serial.print(i + 1);

        Serial.print(":");

        Serial.print(sensor.normalized(i));

        Serial.print(" ");
    }

    Serial.println();

    delay(100);
}