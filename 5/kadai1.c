#include <handy.h>
#include <math.h>
#include <stdio.h>

int main() {
  double x, y;

  HgOpen(400.0, 400.0);
  HgSetWidth(1.0);
  HgSetColor(HG_BLACK);
  HgLine(5.0, 200.0, 395.0, 200.0);
  HgLine(200.0, 5.0, 200.0, 395.0);

  x = 150.0;
  y = 90.0;

  HgSetColor(HG_BLUE);
  HgCircle(x + 200.0, y + 200.0, 3.0);

  double r = 150;
  double a = M_PI / 5;

  x = r * cos(a);
  y = r * sin(a);

  HgSetColor(HG_RED);
  HgCircle(200 + x, 200 + y, 3.0);

  HgGetChar();
  HgClose();
  return 0;
}
