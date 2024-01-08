/*
  基礎プロⅡ　第6回
  課題4 「配列要素の連続回転」
  353126 伊藤和真
*/

#include <stdio.h>
#define SIZE 3

int main() {
  int tiles[SIZE][SIZE];
  int rotatedTiles[SIZE][SIZE];

  // タイルの状態を入力
  for (int y = 0; y < SIZE; y++) {
    for (int x = 0; x < SIZE; x++) {
      scanf("%d", &tiles[x][y]);
    }
  }

  for (int k = 0; k < 4; k++) {
    printf("step %d\n", k);

    // タイルを表示
    for (int y = 0; y < SIZE; y++) {
      for (int x = 0; x < SIZE; x++) {
        if (tiles[x][y]) {
          printf("■ ");
        } else {
          printf("□ ");
        }
      }
      printf("\n");
    }

    // 回転処理
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        rotatedTiles[j][i] = tiles[i][SIZE - j - 1];
      }
    }

    // tilesにrotatedTilesをコピー
    for (int y = 0; y < SIZE; y++) {
      for (int x = 0; x < SIZE; x++) {
        tiles[x][y] = rotatedTiles[x][y];
      }
    }
  }

  return 0;
}
