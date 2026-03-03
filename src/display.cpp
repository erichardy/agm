
#include "display.h"

void displayInit() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
  display.display();
  delay(1000);
  display.setRotation(2); // vertical flip
  display.setTextSize(1.5);
  display.setTextSize(2);

  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.display();
  display.clearDisplay();
  //
}


