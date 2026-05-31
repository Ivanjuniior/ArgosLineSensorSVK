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

    if(sensor.loadCalibration()) {

        Serial.println("CALIBRACAO CARREGADA");

    } else {

        Serial.println("CALIBRANDO...");

        sensor.calibrate(5000);

        sensor.saveCalibration();

        Serial.println("CALIBRACAO SALVA");
    }
}

void loop() {

    sensor.read();

    Serial.print("POS:");

    Serial.println(sensor.position());

    delay(100);
}