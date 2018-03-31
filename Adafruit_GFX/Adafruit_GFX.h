#define swap(a, b) { int t = a; a = b; b = t; }

class Adafruit_GFX {

 public:

  Adafruit_GFX(int w, int h); // Constructor

  // This MUST be defined by the subclass:
  virtual void drawPixel(int x, int y, int color) = 0;

  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
  virtual void
    drawLine(int x0, int y0, int x1, int y1, int color),
    drawFastVLine(int x, int y, int h, int color),
    drawFastHLine(int x, int y, int w, int color),
    drawRect(int x, int y, int w, int h, int color),
    fillRect(int x, int y, int w, int h, int color),
    fillScreen(int color),
    invertDisplay(bool i);

  // These exist only with Adafruit_GFX (no subclass overrides)
  void
    drawCircle(int x0, int y0, int r, int color),
    drawCircleHelper(int x0, int y0, int r, int cornername,
      int color),
    fillCircle(int x0, int y0, int r, int color),
    fillCircleHelper(int x0, int y0, int r, int cornername,
      int delta, int color),
    drawTriangle(int x0, int y0, int x1, int y1,
      int x2, int y2, int color),
    fillTriangle(int x0, int y0, int x1, int y1,
      int x2, int y2, int color),
    drawRoundRect(int x0, int y0, int w, int h,
      int radius, int color),
    fillRoundRect(int x0, int y0, int w, int h,
      int radius, int color),
    drawBitmap(int x, int y, const int *bitmap,
      int w, int h, int color),
    drawChar(int x, int y, char c, int color,
      int bg, int size),
    setCursor(int x, int y),
    setTextColor(int c),
    setTextColor(int c, int bg),
    setTextSize(int s),
    setTextWrap(bool w),
    setRotation(int r);

  int
    height(void),
    width(void);

  int getRotation(void);

 protected:
  const int
    WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int
    _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  int
    textcolor, textbgcolor;
  int
    textsize,
    rotation;
  bool
    wrap; // If set, 'wrap' text at right edge of display
};