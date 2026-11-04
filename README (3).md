# Firmware

Arduino sketches for the ESP32-WROOM-32UE driving SC09 bus servos.

**Verification status:** these sketches were written from Waveshare's SC09 documentation and the SCServo example patterns. They have **not been confirmed running on hardware** (update this line after you test them). If a call doesn't compile, compare it to the examples that ship with the library (`SCServo/examples/arduinoIDE/SCSCL`).

## Dependencies

- Arduino IDE with the Espressif ESP32 board package
- **SCServo** library, from Waveshare's SC09 demo package:
  https://files.waveshare.com/upload/5/5a/SERVO_DRIVER_WITH_ESP32.zip
  Copy the `SCServo` folder into `Documents/Arduino/libraries/` and restart the IDE.
  (Not committed here. It's third-party code.)
- Use the `SCSCL` class for SC09, not `SMS_STS`.

## Sketches (run in order)

| Sketch | Purpose |
| --- | --- |
| `01_assign_id/` | Give each servo a unique ID. Connect **one servo at a time**. |
| `02_ping_test/` | Ping IDs 1-5 on the shared bus to confirm wiring and IDs. |
| `03_rotation_test/` | Move one servo back and forth to confirm control. |

## Pins

`RX_PIN`/`TX_PIN` are set to GPIO 16/17 as placeholders. Change them to whatever you actually wired. Avoid the strapping pins (0, 2, 5, 12, 15) and the pins already used for flex sensors and I2C. See `docs/wiring-and-pinout.md`.

## Still to write

- Movement-onset detection on flex sensor data
- `setServoAngle()` wrapper tied to the drum geometry
- Multi-servo synchronized control and load/position feedback logging
- Biosensor readout (SPI for AD5940/41, I2C for LMP91000)
- Main-loop scheduling across ADC, servo UART, SPI and I2C
