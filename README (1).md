# Biosensor

Uses the lab-developed potentiostat board (AD5940/AD5941 over SPI, LMP91000 over I2C).

## Measurement modes

- **AT (amperometric technique):** fixed bias, current over time. Intended sensing mode.
- **CV (cyclic voltammetry):** use for electrode quality checks, not live sensing.
- Output units are picoamps, so keep wiring short and away from servo power lines.

## Chemistry

Screen-printed carbon electrodes, lactate oxidase, 5% Nafion overcoat, PBS, sodium L-lactate standards for calibration.

## To fill in

- [ ] Driver code source and where it lives (lab repo? who to ask?)
- [ ] Output data format (raw vs processed)
- [ ] Logic voltage and ESP32 compatibility
- [ ] Calibration protocol, data files and fitted curve
