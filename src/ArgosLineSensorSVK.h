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

    int mapped(uint8_t sensor);

    void calibrate(uint32_t duration = 5000);

    int minimum(uint8_t sensor);

    int maximum(uint8_t sensor);

    int normalized(uint8_t sensor);

    long position();

    bool saveCalibration();

    bool loadCalibration();

    bool clearCalibration();

    bool isCalibrated();

    bool isLineDetected();

    bool isLost();

    bool isCentered(int tolerance = 200);

    // ==========================
    // V1.1
    // ==========================

    void setSamples(uint8_t samples);

    uint8_t samples();

    // ==========================
    // V1.2
    // ==========================

    void setLineThreshold(int threshold);

    int lineThreshold();

private:

    uint8_t _muxA;
    uint8_t _muxB;
    uint8_t _muxC;
    uint8_t _sensorOut;

    int _raw[8];

    int _min[8];
    int _max[8];

    long _lastPosition;

    bool _calibrated;

    // ==========================
    // V1.1
    // ==========================

    uint8_t _samples;

    // ==========================
    // V1.2
    // ==========================

    int _lineThreshold;

    void selectSensor(uint8_t channel);
};

#endif