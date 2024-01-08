#include <stdio.h>
#include <math.h>
#include <handy.h>

void fish(double x, double y, double size) {
  HgSetColor(HG_RED);
  HgSetFillColor(HG_RED);
  HgFanFill(x, y, size, 1.25 * M_PI, 0.75 * M_PI, 0);
  HgMoveTo(x + size, y);
  HgLineTo(x + size * 3.0, y);
  HgLineTo(x + size * 4.0, y - size);
  HgMoveTo(x + size * 3.0, y);
  HgLineTo(x + size * 4.0, y + size);
  HgSetFillColor(HG_WHITE);
  HgCircleFill(x + size / 3.0, y + size / 2.0, size / 4.0, 0);
  HgSetColor(HG_RED);

  for (int i = 0; i < 5; i++) {
    HgLine(x + size * 1.2 + i * size / 3.0, y - size / 2.0,
           x + size * 1.2 + i * size / 3.0, y + size / 2.0);
  }
}

int main() {
  double x, y, size, dx, dy;

  HgOpen(400.0, 400.0);

  x = 200.0;
  y = 200.0;
  size = 10.0;
  dx = -0.8 * size;
  dy = 0.4 * size;

  while (1) {
    HgClear();

    fish(x, y, size);

    if (y < size || y > (400.0 - size)) dy *= (-1.0);
    y += dy;
    if (x < size || x > (400.0 - size)) dx *= (-1.0);
    x += dx;
    HgSleep(0.1);
  }
}
