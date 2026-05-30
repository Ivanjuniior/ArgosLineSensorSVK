#ifndef ARGOS_LINE_SENSOR_SVK_H
#define ARGOS_LINE_SENSOR_SVK_H

#include <Arduino.h>

class ArgosLineSensorSVK {

public:

    ArgosLineSensorSVK();

    void begin(
        uint8_t muxA,
        uint8_t muxB,
        uint8_t muxC,
        uint8_t sensorOut
    );

    void read();

    int raw(uint8_t sensor);

private:

    uint8_t _muxA;
    uint8_t _muxB;
    uint8_t _muxC;
    uint8_t _sensorOut;

    int _raw[8];

    void selectSensor(uint8_t channel);
};

#endif
