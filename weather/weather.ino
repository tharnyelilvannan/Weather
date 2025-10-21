#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include <Adafruit_BMP085.h>

#define TFT_CS        10
#define TFT_RST        8
#define TFT_DC         9
#define TFT_MOSI      11
#define TFT_SCLK      13

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
Adafruit_BMP085 bmps;

void setup() {
  Serial.begin(9600);

  tft.initR(INITR_BLACKTAB);
  
  if (bmps.begin() != true) {
    Serial.println("Error initializing sensor.");
  }

  delay(1000);


  // opening
  tft.fillScreen(ST77XX_BLACK);

}

void printTemp(float temp) {

  if (temp > 25) {
    tft.setTextColor(ST77XX_RED);
  }
  else {
    tft.setTextColor(ST77XX_BLUE);

  }

  tft.setCursor(0, 0);
  tft.setTextWrap(true);
  tft.println("Temperature:");
  tft.print(temp);
  tft.println(" degrees C");
  float Ftemp = (temp * 1.8) + 32;
  tft.print(Ftemp);
  tft.println(" degrees F");
  tft.println("");
  tft.println("If error in readings,ensure all wires are connected or press reset button on Arduino.");
  delay(10000); // change to 1200000 when ready for practical use
  tft.fillScreen(ST77XX_BLACK);
}

float readTemp() {

  return bmps.readTemperature();

}
void loop() {
  float temp;
  temp = readTemp();
  printTemp(temp);
}