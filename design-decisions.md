# Design decisions

These are **working decisions**, not validated on hardware yet.

| Decision | Choice | Reason | Alternative not taken |
| --- | --- | --- | --- |
| Controller | ESP32-WROOM-32UE | ADC, UART, SPI and I2C on one chip | FPGA boards (PYNQ-Z2, ULX3S, iCE40): more complexity than needed |
| Actuators | SC09 bus servos (6: 5 + 1 spare) | Position/load/voltage feedback supports the fatigue-modulation idea | MG90S PWM servos: cheaper, no feedback |
| Transmission | Pure tendon drive (Dyneema through PTFE tubing) | Follows joint motion, more compliant under patient resistance, easier to adjust per user | Rod-end linkage from the reference repo: rigid, fixed geometry |
| Finger return | Passive silicone cord on the dorsal side | One servo per finger, no antagonist control logic | Antagonist tendon + second servo: 2x servos and power |
| Drum | Printed, 12 mm winding diameter, about 150-200° sweep, about 15-21 mm tendon travel, flanged, bolted to the SC09 horn | Converts servo rotation to tendon pull | |

## Constraints worth remembering

- The PIP joint is the tightest mechanical constraint. Put tube anchors just proximal or distal to the joint crease, not on it.
- Thumb kinematics differ from the fingers. Don't treat it as a scaled finger.
- Servo total height is 27.3 mm against a 28 mm housing target, so only about 0.7 mm clearance. Re-check on the real assembly.
- Prefer slotted/adjustable anchors (about ±5-8 mm) over fixed dimensions.

## Corrected mistakes

- SC09 voltage is 4-6 V (Waveshare spec), not the 4.8-8.4 V in the reference repo's BOM notes. A 7.4 V pack would exceed it.
- Library class for SC09 is `SCSCL`, not `SMS_STS`.
- Don't use the board's TX/RX-labeled pins for the servo bus.
