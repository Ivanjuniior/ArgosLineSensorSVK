#include "ArgosLineSensorSVK.h"

ArgosLineSensorSVK::ArgosLineSensorSVK() {

    for(int i = 0; i < 8; i++) {

        _raw[i] = 0;
    }
}

void ArgosLineSensorSVK::begin(
    uint8_t muxA,
    uint8_t muxB,
    uint8_t muxC,
    uint8_t sensorOut
) {

    _muxA = muxA;
    _muxB = muxB;
    _muxC = muxC;
    _sensorOut = sensorOut;

    pinMode(_muxA, OUTPUT);
    pinMode(_muxB, OUTPUT);
    pinMode(_muxC, OUTPUT);

    analogReadResolution(12);
}

void ArgosLineSensorSVK::selectSensor(uint8_t channel) {

    digitalWrite(_muxA, channel & 0x01);

    digitalWrite(_muxB, (channel >> 1) & 0x01);

    digitalWrite(_muxC, (channel >> 2) & 0x01);
}

void ArgosLineSensorSVK::read() {

    for(int i = 0; i < 8; i++) {

        selectSensor(i);

        delayMicroseconds(50);

        _raw[i] = analogRead(_sensorOut);
    }
}

int ArgosLineSensorSVK::raw(uint8_t sensor) {

    if(sensor > 7) {

        return 0;
    }

    return _raw[sensor];
}
