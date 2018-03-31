/*********************************************************************
This is a library for our Monochrome OLEDs based on SSD1306 drivers

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution

Modified for use with Odroid by Far Horizons (2018)
*********************************************************************/

#ifndef OLED_H
#define OLED_H

#include "Adafruit_GFX/Adafruit_GFX.h"

#define BLACK 0
#define WHITE 1

#define I2C_ADDRESS   0x3C

#define LCDWIDTH 128
#define LCDHEIGHT 64


#define SETCONTRAST 0x81
#define DISPLAYALLON_RESUME 0xA4
#define DISPLAYALLON 0xA5
#define NORMALDISPLAY 0xA6
#define INVERTDISPLAY 0xA7
#define DISPLAYOFF 0xAE
#define DISPLAYON 0xAF

#define SETDISPLAYOFFSET 0xD3
#define SETCOMPINS 0xDA

#define SETVCOMDETECT 0xDB

#define SETDISPLAYCLOCKDIV 0xD5
#define SETPRECHARGE 0xD9

#define SETMULTIPLEX 0xA8

#define SETLOWCOLUMN 0x00
#define SETHIGHCOLUMN 0x10

#define SETSTARTLINE 0x40

#define MEMORYMODE 0x20

#define COMSCANINC 0xC0
#define COMSCANDEC 0xC8

#define SEGREMAP 0xA0

#define CHARGEPUMP 0x8D

#define EXTERNALVCC 0x1
#define SWITCHCAPVCC 0x2

// Scrolling #defines
#define ACTIVATE_SCROLL 0x2F
#define DEACTIVATE_SCROLL 0x2E
#define SET_VERTICAL_SCROLL_AREA 0xA3
#define RIGHT_HORIZONTAL_SCROLL 0x26
#define LEFT_HORIZONTAL_SCROLL 0x27
#define VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

class Oled : public Adafruit_GFX {
 public:
  Oled(int RST);

  void begin(int switchvcc = SWITCHCAPVCC, int i2caddr = I2C_ADDRESS);
  void command(int c);
  void data(int c);

  void clearDisplay(void);
  void invertDisplay(int i);
  void display();

  void startscrollright(int start, int stop);
  void startscrollleft(int start, int stop);

  void startscrolldiagright(int start, int stop);
  void startscrolldiagleft(int start, int stop);
  void stopscroll(void);

  void drawPixel(int x, int y, int color);

 private:
  int _i2caddr;

};

#endif
