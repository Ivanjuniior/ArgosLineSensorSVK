# ArgosLineSensorSVK Roadmap

## V0.1 - Raw Reading

* [x] ESP32 support
* [x] Multiplexer control
* [x] Raw sensor reading
* [x] `begin()`
* [x] `read()`
* [x] `raw()`

---

## V0.2 - Sensor Mapping

* [x] Physical sensor remapping
* [x] `mapped()`

Physical sensor order:

S6 S1 S2 S5 S3 S7 S8 S4

Logical order:

N1 N2 N3 N4 N5 N6 N7 N8

---

## V0.3 - Calibration

* [x] Calibration routine
* [x] `calibrate()`
* [x] `minimum()`
* [x] `maximum()`

---

## V0.4 - Normalized Reading

* [x] Sensor normalization
* [x] `normalized()`
* [x] Range 0-1000

Where:

* 0 = White
* 1000 = Black

---

## V0.5 - Position Detection

* [x] Weighted position calculation
* [x] Last valid position memory
* [x] `position()`

Position range:

* 0 = Right side
* 3500 = Center
* 7000 = Left side

---

## V0.6 - EEPROM Support

* [x] Save calibration data
* [x] Load calibration data
* [x] Factory reset calibration

Functions:

* `saveCalibration()`
* `loadCalibration()`
* `clearCalibration()`

---

## V0.7 - Line Detection

* [x] Detect line presence
* [x] `isLineDetected()`

---

## V0.8 - Calibration Status

* [X] isLost()

---

## V0.9 - Lost Line Detection

* [ ] Lost line detection
* [ ] `isLost()`

---

## V1.0

* [ ] Stable API
* [ ] Complete examples
* [ ] PID line follower example
* [ ] Documentation
* [ ] Arduino Library Manager preparation
