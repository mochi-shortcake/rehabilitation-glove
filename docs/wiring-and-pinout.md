# Wiring and pin map

## ESP32 pins

| Function | Pin(s) | Notes |
| --- | --- | --- |
| Flex sensors (5, ADC) | GPIO 34, 35, 32, 33, 25 | GPIO25 is ADC2, shared with WiFi. Fine while wired, revisit if wireless is added. |
| I2C (LMP91000) | GPIO 21 (SDA), 22 (SCL) | |
| SPI chip select (AD5940/41) | GPIO 26 or 27 (not yet fixed) | CS can be any GPIO. |
| Servo bus (UART) | Two numbered GPIOs on `Serial2`, e.g. 16 and 17 | Placeholder. Use whatever you wire. |
| USB serial | GPIO 1 / 3 | Board pins labeled TX/RX. Keep free for programming. |
| Avoid | GPIO 0, 2, 5, 12, 15 | Strapping pins. |

## SC09 servo connector (3-pin, labeled S V G)

| Pin | Connects to |
| --- | --- |
| S (Signal) | Half-duplex bus node (below) |
| V (VCC) | 5 V servo rail |
| G (GND) | Common ground with the ESP32 |

## Half-duplex bus (resistor bridge)

Tie ESP32 TX and RX together through a 1 kΩ resistor and connect that junction to every servo's S pin. The SCServo library discards the echo of its own transmissions.

```
ESP32 TX --+--[1k]--+-- junction -- all servos' S pins
ESP32 RX --+
ESP32 GND ---------------------------- all servos' G pins (and the 5 V rail's ground)
5 V rail (+) ------------------------- all servos' V pins
```

A more robust option is Waveshare's reference transceiver circuit (SN74LVC1G126, SN74LVC1G125, S8550 with a TXEN line):
https://files.waveshare.com/upload/d/d3/Bus_servo_control_circuit.pdf
That needs one extra GPIO for TXEN.

## Power

- Servo rail: **5 V** (SC09 is rated 4-6 V). Worst case with all five stalled is about 5 A (1 A locked-rotor each), so size the regulator with headroom.
- Keep the servo rail separate from the ESP32 logic supply to avoid brownouts. Share ground only.
- Keep biosensor wiring (picoamp-level signals) physically away from servo power wiring.

## Daisy-chaining

The small green breakout board that came with the servos passes Signal/VCC/GND through to each servo in parallel. Confirm which pad is which with a multimeter before relying on the silkscreen.
