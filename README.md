# ArgosLineSensorSVK

Arduino/ESP32 library for SVK 8-channel line sensors.

Developed for the ARGOS robotics platform.

## Features

* Raw sensor reading
* Sensor remapping
* Automatic calibration
* Normalized values (0-1000)
* Line position detection
* ESP32 compatible

---

## Installation

Clone the repository into your Arduino libraries folder:

```bash
git clone https://github.com/Ivanjuniior/ArgosLineSensorSVK.git
```

Or copy the folder to:

```text
Arduino/libraries/
```

---

## Hardware

Sensor pins:

```cpp
sensor.begin(
    32, // MUX A
    33, // MUX B
    25, // MUX C
    35  // SENSOR OUT
);
```

The pin assignment is configurable and may be changed according to your project.

---

## Physical Sensor Layout

Physical order:

```text
S6 S1 S2 S5 S3 S7 S8 S4
```

Logical order:

```text
N1 N2 N3 N4 N5 N6 N7 N8
```

---

## Basic Example

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

    sensor.calibrate(5000);
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
7000  -> Left
3500  -> Center
0     -> Right
```

---

## Current API

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
```

---

## Development Status

Current Version: V0.5

See ROADMAP.md for upcoming features.

---

## License

MIT License

Copyright (c) Ivan Junior
