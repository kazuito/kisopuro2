#include "handy.h"
#include "math.h"

int main() {
  HgOpen(400.0, 400.0);

  double x[4] = {-10.0, 30.0, -30.0, 10.0};
  double y[4] = {80.0, 0.0, 0.0, 80.0};

  double a = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      int x1 = x[j] * cos(a) - y[j] * sin(a);
      int y1 = x[j] * sin(a) + y[j] * cos(a);

      int x2 = x[j + 1] * cos(a) - y[j + 1] * sin(a);
      int y2 = x[j + 1] * sin(a) + y[j + 1] * cos(a);

      HgLine(x1 + 200, y1 + 200, x2 + 200, y2 + 200);
    }

    a += (M_PI / 5);
  }

  HgGetChar();
  HgClose();
  return 0;
}
