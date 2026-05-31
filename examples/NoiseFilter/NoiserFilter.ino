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

    sensor.setSamples(10);

    if(!sensor.loadCalibration()) {

        sensor.calibrate(5000);

        sensor.saveCalibration();
    }
}

void loop() {

    sensor.read();

    Serial.print("SAMPLES: ");
    Serial.print(sensor.samples());

    Serial.print(" POS: ");

    Serial.println(sensor.position());

    delay(100);
}