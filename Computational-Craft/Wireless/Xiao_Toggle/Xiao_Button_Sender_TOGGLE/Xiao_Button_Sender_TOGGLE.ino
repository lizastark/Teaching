/* Computational Craft
 * Week 11 | Wireless
 * 
 * Uses the Xiao ESP32C to send a message to the 
 * Only sends a message when the button is pressed down.
 * No keepalive needed for toggle behavior.
 */

#include <esp_now.h>
#include <WiFi.h>

// ── CONFIG ─────────────────────────────────────────────
uint8_t receiverMAC[] = {0x98, 0x3D, 0xAE, 0xAC, 0xB1, 0x0C}; //***** UPDATE THIS USING THE MAC ADDRESS CODE
const int BUTTON_PIN = D7;
const unsigned long DEBOUNCE_DELAY = 50;
// ───────────────────────────────────────────────────────

typedef struct {
  bool buttonPressed;
} Message;

Message outgoing;

int buttonState;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);
  esp_now_init();

  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, receiverMAC, 6);
  esp_now_add_peer(&peer);

  Serial.println("Sender ready. MAC: " + WiFi.macAddress());
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;

      // Only send when button is pressed down, ignore release
      if (buttonState == LOW) {
        outgoing.buttonPressed = true;
        esp_now_send(receiverMAC, (uint8_t *)&outgoing, sizeof(outgoing));
        Serial.println("Button pressed — message sent");
      }
    }
  }

  lastButtonState = reading;
  delay(10);
}