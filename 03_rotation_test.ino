// 03_rotation_test: move one servo between two positions and read it back.
// Position range is 0-1023 across 300 degrees (about 0.293 deg/step).
// Reversal needs no special command: asking for a lower position turns it back.
//
// Keep the tendon slack / drum unloaded for the first run.
// NOT YET VERIFIED ON HARDWARE.

#include <SCServo.h>

SCSCL sc;

#define RX_PIN 16        // placeholder, set to your wired pins
#define TX_PIN 17
#define SERVO_ID 2

// Start with a small sweep (about 60 degrees) and widen it after it works.
#define POS_A 400
#define POS_B 600
#define SPEED 1500

void setup() {
  Serial.begin(115200);
  Serial2.begin(1000000, SERIAL_8N1, RX_PIN, TX_PIN);
  sc.pSerial = &Serial2;
  delay(500);
}

void loop() {
  sc.WritePos(SERVO_ID, POS_B, 0, SPEED);
  delay(1500);
  readFeedback();

  sc.WritePos(SERVO_ID, POS_A, 0, SPEED);
  delay(1500);
  readFeedback();
}

void readFeedback() {
  if (sc.FeedBack(SERVO_ID) != -1) {
    Serial.print("pos=");
    Serial.print(sc.ReadPos(-1));
    Serial.print(" load=");
    Serial.print(sc.ReadLoad(-1));
    Serial.print(" voltage=");
    Serial.println(sc.ReadVoltage(-1));
  } else {
    Serial.println("No feedback from servo.");
  }
}
