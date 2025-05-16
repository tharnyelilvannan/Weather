#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        8
#define TFT_DC         9
#define TFT_MOSI      11
#define TFT_SCLK      13

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void) {
  Serial.begin(9600);
  Serial.println(F("Hello! Initializing..."));

  tft.initR(INITR_BLACKTAB);

  Serial.println(F("Initialized."));

  // opening
  tft.fillScreen(ST77XX_BLACK);

  for (int16_t y = 0; y < tft.height(); y += 10) {
    tft.drawFastHLine(0, y, tft.width(), ST77XX_MAGENTA);
  }
  for (int16_t x = 0; x < tft.width(); x += 10) {
    tft.drawFastVLine(x, 0, tft.height(), ST77XX_BLUE);
  }

  delay(3000);

  tft.fillScreen(ST77XX_BLACK);

}

void loop() {
  // put your main code here, to run repeatedly:

}
