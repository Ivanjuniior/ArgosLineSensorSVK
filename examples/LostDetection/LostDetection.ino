#include <ArgosLineSensorSVK.h>

ArgosLineSensorSVK sensor;

void setup() {

    Serial.begin(115200);

    sensor.begin(
        32, // MUX A
        33, // MUX B
        25, // MUX C
        35  // Sensor OUT
    );

    Serial.println();
    Serial.println("ARGOS LINE SENSOR V0.8");
    Serial.println();

    if(sensor.loadCalibration()) {

        Serial.println("CALIBRACAO CARREGADA");

    } else {

        Serial.println("CALIBRANDO");

        sensor.calibrate(5000);

        sensor.saveCalibration();

        Serial.println("CALIBRACAO SALVA");
    }

    Serial.println();
}

void loop() {

    sensor.read();

    Serial.print("LINE: ");
    Serial.print(sensor.isLineDetected());

    Serial.print(" | LOST: ");
    Serial.print(sensor.isLost());

    Serial.print(" | POS: ");
    Serial.println(sensor.position());

    delay(100);
}