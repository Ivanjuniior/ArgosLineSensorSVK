#include "ArgosLineSensorSVK.h"
#include <Preferences.h>

static Preferences prefs;

ArgosLineSensorSVK::ArgosLineSensorSVK() {

    for(int i = 0; i < 8; i++) {

        _raw[i] = 0;

        _min[i] = 4095;

        _max[i] = 0;
    }

    _lastPosition = 3500;

    _calibrated = false;
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

        5,
        0,
        1,
        4,
        2,
        6,
        7,
        3
    };

    if(sensor > 7) {

        return 0;
    }

    return _raw[mapTable[sensor]];
}

void ArgosLineSensorSVK::calibrate(uint32_t duration) {

    for(int i = 0; i < 8; i++) {

        _min[i] = 4095;

        _max[i] = 0;
    }

    uint32_t startTime = millis();

    while(millis() - startTime < duration) {

        read();

        for(int i = 0; i < 8; i++) {

            int value = mapped(i);

            if(value < _min[i]) {

                _min[i] = value;
            }

            if(value > _max[i]) {

                _max[i] = value;
            }
        }

        delay(5);
    }

    _calibrated = true;
}

int ArgosLineSensorSVK::minimum(uint8_t sensor) {

    if(sensor > 7) {

        return 0;
    }

    return _min[sensor];
}

int ArgosLineSensorSVK::maximum(uint8_t sensor) {

    if(sensor > 7) {

        return 0;
    }

    return _max[sensor];
}

int ArgosLineSensorSVK::normalized(uint8_t sensor) {

    if(sensor > 7) {

        return 0;
    }

    if(!_calibrated) {

        return 0;
    }

    int value = mapped(sensor);

    int minValue = _min[sensor];

    int maxValue = _max[sensor];

    if(maxValue <= minValue) {

        return 0;
    }

    long normalizedValue =
        ((long)(value - minValue) * 1000L) /
        (maxValue - minValue);

    if(normalizedValue < 0) {

        normalizedValue = 0;
    }

    if(normalizedValue > 1000) {

        normalizedValue = 1000;
    }

    return (int)normalizedValue;
}

long ArgosLineSensorSVK::position() {

    long weightedSum = 0;

    long total = 0;

    for(int i = 0; i < 8; i++) {

        int value = normalized(i);

        weightedSum += (long)value * (i * 1000);

        total += value;
    }

    if(total < 50) {

        return _lastPosition;
    }

    long pos = weightedSum / total;

    _lastPosition = pos;

    return pos;
}

bool ArgosLineSensorSVK::saveCalibration() {

    if(!_calibrated) {

        return false;
    }

    prefs.begin("argosline", false);

    for(int i = 0; i < 8; i++) {

        char keyMin[10];
        char keyMax[10];

        sprintf(keyMin, "min%d", i);
        sprintf(keyMax, "max%d", i);

        prefs.putInt(keyMin, _min[i]);
        prefs.putInt(keyMax, _max[i]);
    }

    prefs.putBool("valid", true);

    prefs.end();

    return true;
}

bool ArgosLineSensorSVK::loadCalibration() {

    prefs.begin("argosline", true);

    bool valid = prefs.getBool("valid", false);

    if(!valid) {

        prefs.end();

        _calibrated = false;

        return false;
    }

    for(int i = 0; i < 8; i++) {

        char keyMin[10];
        char keyMax[10];

        sprintf(keyMin, "min%d", i);
        sprintf(keyMax, "max%d", i);

        _min[i] = prefs.getInt(keyMin, 0);
        _max[i] = prefs.getInt(keyMax, 0);

        if(_max[i] <= _min[i]) {

            prefs.end();

            _calibrated = false;

            return false;
        }
    }

    prefs.end();

    _calibrated = true;

    return true;
}

bool ArgosLineSensorSVK::clearCalibration() {

    prefs.begin("argosline", false);

    prefs.clear();

    prefs.end();

    for(int i = 0; i < 8; i++) {

        _min[i] = 4095;
        _max[i] = 0;
    }

    _calibrated = false;

    return true;
}

bool ArgosLineSensorSVK::isCalibrated() {

    return _calibrated;
}

bool ArgosLineSensorSVK::isLineDetected() {

    if(!_calibrated) {

        return false;
    }

    long total = 0;

    for(int i = 0; i < 8; i++) {

        total += normalized(i);
    }

    return total > 100;
}