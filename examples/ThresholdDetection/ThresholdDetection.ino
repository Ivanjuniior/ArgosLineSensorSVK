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

    sensor.setLineThreshold(100);

    if(!sensor.loadCalibration()) {

        sensor.calibrate(5000);

        sensor.saveCalibration();
    }
}

void loop() {

    sensor.read();

    Serial.print("THRESHOLD: ");
    Serial.print(sensor.lineThreshold());

    Serial.print(" LINE: ");
    Serial.println(sensor.isLineDetected());

    delay(100);
}