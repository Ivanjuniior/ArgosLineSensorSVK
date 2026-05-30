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

    Serial.print("N1:");
    Serial.print(sensor.mapped(0));

    Serial.print(" N2:");
    Serial.print(sensor.mapped(1));

    Serial.print(" N3:");
    Serial.print(sensor.mapped(2));

    Serial.print(" N4:");
    Serial.print(sensor.mapped(3));

    Serial.print(" N5:");
    Serial.print(sensor.mapped(4));

    Serial.print(" N6:");
    Serial.print(sensor.mapped(5));

    Serial.print(" N7:");
    Serial.print(sensor.mapped(6));

    Serial.print(" N8:");
    Serial.println(sensor.mapped(7));

    delay(100);
}