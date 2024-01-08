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
  HgFanFill(x, y, size, 0.25 * M_PI, -0.25 * M_PI, 0);

  HgMoveTo(x - size, y);
  HgLineTo(x - size * 3.0, y);
  HgLineTo(x - size * 4.0, y - size);
  HgMoveTo(x - size * 3.0, y);
  HgLineTo(x - size * 4.0, y + size);

  HgSetFillColor(HG_WHITE);
  HgCircleFill(x - size / 3.0, y + size / 2.0, size / 4.0, 0);
  HgSetColor(HG_RED);

  for (int i = 0; i < 5; i++) {
    HgLine(x - size * 1.2 - i * size / 3.0, y - size / 2.0,
           x - size * 1.2 - i * size / 3.0, y + size / 2.0);
  }
}

int tooClose(double x1, double y1, double x2, double y2) {
  double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

  return distance <= 50;
}

int main() {
  srandom(time(NULL));

  double fishes[10][5] = {{}};

  for (int i = 0; i < 10; i++) {
    int size = random() % 20 + 5;

    fishes[i][2] = size;
    fishes[i][3] = -0.8 * size;
    fishes[i][4] = 0.4 * size;

    fishes[i][0] = random() % (400 - size * 4);
    fishes[i][1] = random() % (400 - size * 4);
  }

  HgOpen(400.0, 400.0);

  while (1) {
    HgClear();

    for (int i = 9; i >= 0; i--) {
      double x = fishes[i][0];
      double y = fishes[i][1];
      double size = fishes[i][2];
      double dx = fishes[i][3];
      double dy = fishes[i][4];

      if (y + dy < size || y + dy > 400 - size) {
        dy = -dy;
      }

      y += dy;

      if (x + dx < size || x + dx > 400 - size) {
        dx = -dx;
      }

      x += dx;

      if (dx < 0)
        fish_left(x, y, size);
      else
        fish_right(x, y, size);

      if (i == 0) {
        HgSetColor(HG_BLUE);
        HgCircle(x, y, size * 1.2);
      }

      fishes[i][0] = x;
      fishes[i][1] = y;
      fishes[i][2] = size;
      fishes[i][3] = dx;
      fishes[i][4] = dy;
    }

    int kingX = fishes[0][0];
    int kingY = fishes[0][1];
    int kingDx = fishes[0][3];
    int kingDy = fishes[0][4];

    for (int i = 0; i < 9; i++) {
      int x = fishes[i][0];
      int y = fishes[i][1];

      if (tooClose(x, y, kingX, kingY)) {
        fishes[i][3] = kingDx;
        fishes[i][4] = kingDy;
      }
    }

    HgSleep(0.1);
  }
}
