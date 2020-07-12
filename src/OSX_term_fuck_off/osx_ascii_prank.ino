#include "DigiKeyboardFr.h"
#define KEY_UP_ARROW     0x52
#define KEY_DOWN_ARROW   0x51
#define KEY_LEFT_ARROW   0x50
#define KEY_RIGHT_ARROW  0x4F
#define KEY_LEFT_GUI     0xE3
#define KEY_ESC          0x29
#define KEY_HOME         0x4A
#define KEY_INSERT       0x49
#define KEY_NUM_LOCK     0x53
#define KEY_SCROLL_LOCK  0x47
#define KEY_CAPS_LOCK    0x39
#define KEY_TAB          0x2B

void printText(fstr_t *txt) {
  DigiKeyboardFr.print(txt);
  DigiKeyboardFr.update();
}

void setup() {
  DigiKeyboardFr.sendKeyStroke(0,0);
  DigiKeyboardFr.delay(50);
  DigiKeyboardFr.delay(1000);
  DigiKeyboardFr.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  printText(F("terminal"));
  DigiKeyboardFr.delay(1000);
  DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
  DigiKeyboardFr.delay(800);
  printText(F("say C'est bien en azerty."));
  const int led=1;
  pinMode(led, OUTPUT);
  while (1) {
    digitalWrite(led, !digitalRead(led));
    DigiKeyboardFr.delay(1000);
  }
}

void loop() {}