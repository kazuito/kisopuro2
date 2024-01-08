#include <handy.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fish_left(double x, double y, double size) {
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

void fish_right(double x, double y, double size) {
  HgSetColor(HG_RED);
  HgSetFillColor(HG_RED);

  HgFanFill(x + size * 3, y, size, 0.25 * M_PI, -0.25 * M_PI, 0);
  HgMoveTo(x + size * 2, y);
  HgLineTo(x, y);
  HgLineTo(x - size, y - size);
  HgMoveTo(x, y);
  HgLineTo(x - size, y + size);

  HgSetFillColor(HG_WHITE);
  HgCircleFill(x + size * 3 - size / 3.0, y + size / 2.0, size / 4.0, 0);

  HgSetColor(HG_RED);

  for (int i = 0; i < 5; i++) {
    HgLine(x + size * 3 - size * 1.2 - i * size / 3.0, y - size / 2.0,
           x + size * 3 - size * 1.2 - i * size / 3.0, y + size / 2.0);
  }
}

int main() {
  srandom(time(NULL));

  double x, y, size, dx, dy;
  double fishes[10][5] = {{}};

  for (int i = 0; i < 10; i++) {
    fishes[i][0] = random() % 400;
    fishes[i][1] = random() % 400;

    int size = random() % 15 + 5;

    fishes[i][2] = size;
    fishes[i][3] = -0.8 * size;
    fishes[i][4] = 0.4 * size;
  }

  HgOpen(400.0, 400.0);

  while (1) {
    HgClear();

    for (int i = 0; i < 10; i++) {
      x = fishes[i][0];
      y = fishes[i][1];
      size = fishes[i][2];
      dx = fishes[i][3];
      dy = fishes[i][4];

      if (y < size || y > (400.0 - size)) dy *= (-1.0);

      y += dy;

      if (x < size || x > (400.0 - size * 4)) dx *= (-1.0);

      x += dx;

      if (dx < 0)
        fish_left(x, y, size);
      else
        fish_right(x, y, size);

      fishes[i][0] = x;
      fishes[i][1] = y;
      fishes[i][2] = size;
      fishes[i][3] = dx;
      fishes[i][4] = dy;
    }

    HgSleep(0.1);
  }
}
