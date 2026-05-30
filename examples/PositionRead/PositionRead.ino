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

    Serial.println("CALIBRANDO...");

    sensor.calibrate(5000);

    Serial.println("PRONTO");
}

void loop() {

    sensor.read();

    Serial.print("POS:");

    Serial.println(sensor.position());

    delay(100);
}