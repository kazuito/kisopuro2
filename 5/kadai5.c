#include <handy.h>
#include <math.h>

int main() {
  HgOpen(400.0, 400.0);
  HgSetWidth(1.0);
  HgSetColor(HG_BLACK);
  HgLine(5.0, 200.0, 395.0, 200.0);
  HgLine(200.0, 5.0, 200.0, 395.0);

  double x[4] = {-10.0, 30.0, -30.0, 10.0};
  double y[4] = {80.0, 0.0, 0.0, 80.0};
  double base_x = 200 - 150, base_y = 200 - 50;

  HgSetColor(HG_BLUE);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      int x1 = x[j] + base_x;
      int y1 = y[j] + base_y;

      int x2 = x[j + 1] + base_x;
      int y2 = y[j + 1] + base_y;

      HgLine(x1, y1, x2, y2);
    }

    base_x += 60;
    base_y += 40;
  }

  HgGetChar();
  HgClose();
  return 0;
}
