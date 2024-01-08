/**
 * ドットエディタ（最終ステップ）
 * 353126 伊藤和真
 */

#include <handy.h>
#include <stdio.h>

#define WIN_WIDTH 400.0
#define WIN_HEIGHT 400.0
#define TILES_X 12
#define TILES_Y 12

int main() {
  hgevent *event;
  double x, y;
  int tiles[TILES_X][TILES_Y];

  for (int i = 0; i < TILES_X; i++) {
    for (int j = 0; j < TILES_Y; j++) {
      tiles[i][j] = 0;
    }
  }

  double tile_h = WIN_HEIGHT / TILES_Y;
  double tile_w = WIN_WIDTH / TILES_X;

  HgOpen(WIN_WIDTH, WIN_HEIGHT);
  HgSetWidth(1.0);
  HgSetEventMask(HG_MOUSE_DOWN);

  HgSetColor(HG_WHITE);

  for (;;) {
    // 終了ボタンを描画
    HgSetFillColor(HG_RED);
    HgBoxFill(0, 0, 20, 20, 0);

    event = HgEvent();

    if (event->type == HG_MOUSE_DOWN) {
      x = event->x;
      y = event->y;

      if (x >= 0 && x <= 20 && y >= 0 && y <= 20) {
        break;
      }

      printf("x=%5.2f, y=%5.2f\n", x, y);

      int tile_x = (int)(x / tile_w);
      int tile_y = (int)(y / tile_h);

      tiles[tile_x][tile_y] = !tiles[tile_x][tile_y];
    }

    // タイルを描画
    for (int i = 0; i < TILES_X; i++) {
      for (int j = 0; j < TILES_Y; j++) {
        if (tiles[i][j] == 1) {
          HgSetFillColor(HG_BLACK);
        } else {
          HgSetFillColor(HG_WHITE);
        }
        HgBoxFill(i * tile_w, j * tile_h, tile_w, tile_h, 1);
      }
    }
  }

  return 0;
}
