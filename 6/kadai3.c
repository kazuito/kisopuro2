#include <stdio.h>
#define SIZE 3

int main() {
  int tiles[SIZE][SIZE];
  int rotatedTiles[SIZE][SIZE];

  for (int y = 0; y < SIZE; y++) {
    for (int x = 0; x < SIZE; x++) {
      scanf("%d", &tiles[x][y]);
    }
  }

  printf("before\n");

  // 回転前のタイルを表示
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

  printf("after\n");

  // 回転後のタイルを表示
  for (int y = 0; y < SIZE; y++) {
    for (int x = 0; x < SIZE; x++) {
      if (rotatedTiles[x][y]) {
        printf("■ ");
      } else {
        printf("□ ");
      }
    }
    printf("\n");
  }
}
