/*
 * ESP-NOW Receiver — Option 1
 * Toggles the LED each time a message arrives.
 */

#include <esp_now.h>
#include <WiFi.h>

// ── CONFIG ─────────────────────────────────────────────
const int LED_PIN = D10;
// ───────────────────────────────────────────────────────

typedef struct {
  bool buttonPressed;
} Message;

bool ledOn = false;

void OnDataRecv(const esp_now_recv_info *info, const uint8_t *data, int len) {
  Message incoming;
  memcpy(&incoming, data, sizeof(incoming));

  // Toggle LED on every incoming message
  ledOn = !ledOn;

  if (ledOn) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  Serial.print("Message received — LED is now: ");
  Serial.println(ledOn ? "ON" : "OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  WiFi.mode(WIFI_STA);
  esp_now_init();
  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("Receiver ready. MAC: " + WiFi.macAddress());
}

void loop() {
  delay(10);
}