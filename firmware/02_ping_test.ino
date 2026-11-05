// 02_ping_test: check that every servo on the shared bus answers.
// Run after each servo has a unique ID and all are daisy-chained.
//
// NOT YET VERIFIED ON HARDWARE.

#include <SCServo.h>

SCSCL sc;

#define RX_PIN 16        // placeholder, set to your wired pins
#define TX_PIN 17
#define FIRST_ID 1
#define LAST_ID 5        // use 6 if the spare is also on the bus

void setup() {
  Serial.begin(115200);
  Serial2.begin(1000000, SERIAL_8N1, RX_PIN, TX_PIN);
  sc.pSerial = &Serial2;
  delay(500);
}

void loop() {
  for (int id = FIRST_ID; id <= LAST_ID; id++) {
    Serial.print("Servo ");
    Serial.print(id);
    Serial.println(sc.Ping(id) != -1 ? ": OK" : ": NOT responding");
    delay(100);
  }
  Serial.println("---");
  delay(2000);
}
