# Open items and next steps

## Do first

- [ ] Get fasteners (M2/M3), assemble and test **one** finger: tendon travel (predicted 15-21 mm), silicone return force (target about 1-2 N), cycle durability, PIP binding.
- [ ] Run the three firmware sketches on hardware and record what changes were needed.
- [ ] Request AD5940/41 driver code, output format and logic levels from the lab. Confirm whether AD5940/41 or LMP91000 is the primary channel.

## Then

- [ ] Movement-onset detection on flex data.
- [ ] `setServoAngle()` wrapper and synchronized 5-servo control.
- [ ] Remaining four fingers; redesign the thumb separately.
- [ ] Electrode fabrication (screen-printed carbon, lactate oxidase, Nafion), CV check, then AT calibration against lactate standards (expect roughly log-linear response per the literature review).
- [ ] Assist-gain function mapping lactate to servo assistance, and a plan for the slow biosensor update (about 60 s) versus the fast flex loop.

## Risks

- Scheduling ADC, servo UART, SPI and I2C together has not been designed or tested.
- Human-subject testing may need approval. Ask the advisor before any wearable test.
- Choose a repo visibility and license with the advisor before publishing.
