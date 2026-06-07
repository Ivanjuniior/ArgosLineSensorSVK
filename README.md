# ArgosLineSensorSVK

Arduino/ESP32 library for SVK 8-channel line sensors.

Developed for the ARGOS robotics platform.

## Features

* Raw sensor reading
* Sensor remapping
* Calibration
* Persistent calibration (ESP32 Preferences)
* Normalized values (0-1000)
* Line position detection
* Line detection
* Lost line detection
* Center detection
* ESP32 compatible

---

## Installation

Clone the repository:

```bash
git clone https://github.com/Ivanjuniior/ArgosLineSensorSVK.git
```

Or copy the folder into:

```text
Arduino/libraries/
```

---

## Hardware Configuration

```cpp
sensor.begin(
    32, // MUX A
    33, // MUX B
    25, // MUX C
    35  // SENSOR OUT
);
```

Pin assignments are fully configurable.

---

## Physical Sensor Layout

Physical sensor order:

```text
S6 S1 S2 S5 S3 S7 S8 S4
```

Logical library order:

```text
N1 N2 N3 N4 N5 N6 N7 N8
```

---

## Quick Start

```cpp
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

    if(!sensor.loadCalibration()) {

        sensor.calibrate(5000);

        sensor.saveCalibration();
    }
}

void loop() {

    sensor.read();

    Serial.println(sensor.position());

    delay(50);
}
```

---

## Position Reference

```text
7000 -> Left
3500 -> Center
0    -> Right
```

---

## Available Functions

```cpp
begin()

read()

raw()

mapped()

calibrate()

minimum()

maximum()

normalized()

position()

saveCalibration()

loadCalibration()

clearCalibration()

isCalibrated()

isLineDetected()

isLost()

isCentered()
```

---

## Included Examples

```text
RawRead
MapValidation
Calibration
AutoCalibration
NormalizedRead
PositionRead
LineDetection
LostDetection
CenteredDetection
PIDLineFollower
```

---

## Tested Hardware

- ESP32 DevKit V1
- SVK 8-Channel Line Sensor
- TB6612FNG
- N20 Encoder Motors

---

## Roadmap

### V1.1.0

- Noise filtering

### V1.2.0

- Adjustable line detection threshold

### V1.3.0

- Dynamic calibration

### V2.0.0

- Advanced line tracking platform
- Multi-line detection
- Intersection detection

---

## Version

Current Version: V1.0.0

---

## License

MIT License
