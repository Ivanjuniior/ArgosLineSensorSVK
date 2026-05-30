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
    Serial.println("================================");
    Serial.println("INICIANDO CALIBRACAO");
    Serial.println("================================");

    sensor.calibrate(5000);

    Serial.println();
    Serial.println("================================");
    Serial.println("CALIBRACAO FINALIZADA");
    Serial.println("================================");

    for(int i = 0; i < 8; i++) {

        Serial.print("N");
        Serial.print(i + 1);

        Serial.print(" MIN:");
        Serial.print(sensor.minimum(i));

        Serial.print(" MAX:");
        Serial.println(sensor.maximum(i));
    }
}

void loop() {

}