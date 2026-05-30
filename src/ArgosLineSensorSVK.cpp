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

int ArgosLineSensorSVK::mapped(uint8_t sensor) {

    static const uint8_t mapTable[8] = {
        5, // N1 = S6
        0, // N2 = S1
        1, // N3 = S2
        4, // N4 = S5
        2, // N5 = S3
        6, // N6 = S7
        7, // N7 = S8
        3  // N8 = S4
    };

    if(sensor > 7) {
        return 0;
    }

    return _raw[ mapTable[sensor] ];
}