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

  sensor.calibrate();

  Serial.println("FINALIZADO");
}

void loop() {

}