#include <handy.h>
#include <math.h>

int main() {
  HgOpen(400.0, 400.0);

  double x[4] = {-10.0, 30.0, -30.0, 10.0};
  double y[4] = {80.0, 0.0, 0.0, 80.0};
  double base_x = 200 - 150, base_y = 200 - 50;
  double a = 0;

  // 軸を描画
  HgSetWidth(1.0);
  HgSetColor(HG_BLACK);
  HgLine(5.0, 200.0, 395.0, 200.0);
  HgLine(200.0, 5.0, 200.0, 395.0);

  HgSetColor(HG_BLUE);

  for (int i = 0; i < 5; i++) {
    // 三角形を描画
    for (int j = 0; j < 3; j++) {
      // 辺の始点座標を計算
      int x1 = x[j] * cos(a) - y[j] * sin(a) + base_x;
      int y1 = x[j] * sin(a) + y[j] * cos(a) + base_y;

      // 辺の終点座標を計算
      int x2 = x[j + 1] * cos(a) - y[j + 1] * sin(a) + base_x;
      int y2 = x[j + 1] * sin(a) + y[j + 1] * cos(a) + base_y;

      HgLine(x1, y1, x2, y2);
    }

    // 三角形の基準点を移動
    base_x += 60;
    base_y += 40;

    // 回転角度を増加
    a += (M_PI / 4);
  }

  HgGetChar();
  HgClose();
  return 0;
}
