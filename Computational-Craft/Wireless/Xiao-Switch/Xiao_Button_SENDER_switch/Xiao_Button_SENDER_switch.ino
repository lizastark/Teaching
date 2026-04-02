/*
 * ESP-NOW Sender — reads a button and broadcasts its state
 * Xiao ESP32-C3
 */

#include <esp_now.h>
#include <WiFi.h>

// ── CONFIG ─────────────────────────────────────────────
uint8_t receiverMAC[] = {0x98, 0x3D, 0xAE, 0xAC, 0xB1, 0x0C}; // ← change this
const int BUTTON_PIN = D7;
const unsigned long KEEPALIVE_MS = 100;  // resend every 100ms while held
// ───────────────────────────────────────────────────────

typedef struct {
  bool buttonPressed;
} Message;

Message outgoing;
bool lastState = HIGH;
unsigned long lastSendTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // HIGH = not pressed, LOW = pressed

  WiFi.mode(WIFI_STA);
  esp_now_init();

  // Register receiver as a peer
  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, receiverMAC, 6);
  esp_now_add_peer(&peer);

  Serial.println("Sender ready. MAC: " + WiFi.macAddress());
}

void send(bool pressed) {
  outgoing.buttonPressed = pressed;
  esp_now_send(receiverMAC, (uint8_t *)&outgoing, sizeof(outgoing));
  lastSendTime = millis();
}

void loop() {
  bool state = digitalRead(BUTTON_PIN);

  // Send once when state changes
  if (state != lastState) {
    send(state == LOW);
    lastState = state;
    Serial.println(state);
  }

  // Resend periodically while held (keepalive)
  if (state == LOW && millis() - lastSendTime > KEEPALIVE_MS) {
    send(true);
  }

  delay(10);
}