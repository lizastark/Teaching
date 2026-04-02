/*
 * ESP-NOW Receiver — lights an LED based on incoming button state
 * Xiao ESP32-C3
 */

#include <esp_now.h>
#include <WiFi.h>

// ── CONFIG ─────────────────────────────────────────────
const int LED_PIN = D10;
const unsigned long TIMEOUT_MS = 200;  // turn LED off if signal drops
// ───────────────────────────────────────────────────────

typedef struct {
  bool buttonPressed;
} Message;

bool ledOn = false;
unsigned long lastMessageTime = 0;

void OnDataRecv(const esp_now_recv_info *info, const uint8_t *data, int len) {
  Message incoming;
  memcpy(&incoming, data, sizeof(incoming));

  if (incoming.buttonPressed) {
    ledOn = !ledOn;  // flip the LED state on each press
    if (ledOn) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      if (ledOn) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
    }
  }
  lastMessageTime = millis();
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  WiFi.mode(WIFI_STA);
  esp_now_init();
  esp_now_register_recv_cb(OnDataRecv);

  // Print MAC so you can paste it into the sender
  Serial.println("Receiver ready. MAC: " + WiFi.macAddress());
}

void loop() {
  // Safety timeout: if signal disappears, turn LED off
  if (ledOn && millis() - lastMessageTime > TIMEOUT_MS) {
    ledOn = false;
    digitalWrite(LED_PIN, LOW);
    Serial.println("Signal lost — LED off");
  }
  delay(10);
}