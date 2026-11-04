// 01_assign_id: give an SC09 servo a new bus ID.
// Connect ONLY ONE servo while running this. Every SC09 ships with ID = 1.
// Change NEW_ID, upload, run once, power down, swap servos, repeat.
// Suggested map: 1 = thumb, 2 = index, 3 = middle, 4 = ring, 5 = pinky, 6 = spare.
//
// NOT YET VERIFIED ON HARDWARE. Adapted from the Waveshare SCServo examples.

#include <SCServo.h>

SCSCL sc;

#define RX_PIN 16        // placeholder, set to your wired pins
#define TX_PIN 17
#define CURRENT_ID 1     // factory default
#define NEW_ID 2         // the ID to assign

void setup() {
  Serial.begin(115200);
  Serial2.begin(1000000, SERIAL_8N1, RX_PIN, TX_PIN);
  sc.pSerial = &Serial2;
  delay(500);

  if (sc.Ping(CURRENT_ID) == -1) {
    Serial.println("No servo answered at the current ID. Check wiring and power.");
    return;
  }

  sc.unLockEprom(CURRENT_ID);
  sc.writeByte(CURRENT_ID, SCSCL_ID, NEW_ID);
  sc.LockEprom(NEW_ID);

  delay(200);
  if (sc.Ping(NEW_ID) != -1) {
    Serial.print("Success: servo is now ID ");
    Serial.println(NEW_ID);
  } else {
    Serial.println("ID change not confirmed. Re-run or check wiring.");
  }
}

void loop() {}
