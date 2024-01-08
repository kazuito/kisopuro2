#include <handy.h>
#include <math.h>

int main() {
  HgOpen(400.0, 400.0);

  double blue_x = 150.0, blue_y = 90.0;
  double a = 0;

  // 軸を描画
  HgSetWidth(1.0);
  HgSetColor(HG_BLACK);
  HgLine(5.0, 200.0, 395.0, 200.0);
  HgLine(200.0, 5.0, 200.0, 395.0);

  // 青い点を描画
  HgSetColor(HG_BLUE);
  HgCircle(blue_x + 200, blue_y + 200, 3);

  HgSetColor(HG_RED);

  // 赤い点をループで描画
  for (int i = 0; i < 10; i++) {
    a += M_PI / 10;

    int red_x = blue_x * cos(a) - blue_y * sin(a);
    int red_y = blue_x * sin(a) + blue_y * cos(a);

    HgCircle(200 + red_x, 200 + red_y, 3.0);
  }

  HgGetChar();
  HgClose();
  return 0;
}
