# Rehab Glove

Soft robotic hand-rehabilitation glove. An ESP32 reads flex sensors to detect voluntary finger movement, drives tendon-actuated fingers with SC09 bus servos to assist that movement, and is intended to scale assistance using a lactate biosensor as a fatigue signal.

**Author:** Diane Joseph, LI³TMES Lab, UTRGV
**Status:** early prototype. See "Status" below and be skeptical of anything not marked *tested*.

## Status (to be modified when something changes)

| Area | State | Notes |
| --- | --- | --- |
| Flex sensing (Phase 1) | Working | 5 channels on GPIO 34, 35, 32, 33, 25 |
| Finger modules + drums | Printed, not assembled | Assembly was blocked on fasteners |
| Servo firmware | Written, **not verified on hardware** | See `firmware/` |
| Flex-triggered assist | Not started | |
| Biosensor driver (AD5940/41, LMP91000) | Not started | Needs driver code from the lab |
| Lactate calibration | Not started | |
| Assist-gain function (fatigue modulation) | Not started | |

## Repo layout

```
firmware/    Arduino sketches for the ESP32 (servo bring-up so far)
cad/         Printable parts and source CAD (add files here)
biosensor/   Notes and, later, code for the potentiostat integration
docs/        Design decisions, wiring/pin map, open items
```

## Getting started

1. Install Arduino IDE and the ESP32 board package (Espressif).
2. Install the **SCServo** library from Waveshare's SC09 demo package into `Documents/Arduino/libraries/`. It is not included in this repo. See `firmware/README.md`.
3. Wire one servo per `docs/wiring-and-pinout.md`.
4. Run the sketches in `firmware/` in numeric order.

## Important safety/hardware notes

- SC09 servos are rated **4-6 V**. Run the servo rail at 5 V. Do not use a 2x18650 (7.4 V) pack.
- Keep the servo power rail separate from the ESP32 logic supply (shared ground only).
- The pins labeled "TX"/"RX" on the ESP32 board are for USB. The servo bus uses `Serial2` on numbered GPIOs.

## Licensing and sources

No license has been chosen yet. Decide with the advisor/lab before making this repo public (lab-funded work, and reference designs have mixed licenses). References used:

- MengyangGao/hand_exoskeleton (MIT)
- newdexterity/Hybrid-Exoskeleton-Glove (CC BY 4.0)
