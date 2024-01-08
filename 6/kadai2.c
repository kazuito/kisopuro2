/*
  基礎プロⅡ　第6回
  課題2 「ビンゴ」
  353126 伊藤和真
*/

#include <stdio.h>

#define SIZE 3

int main() {
  int card[SIZE][SIZE];
  int hits[SIZE * SIZE];
  int x, y;
  int isBingo = 0;

  // ビンゴカードの番号たちを入力
  for (y = 0; y < SIZE; y++) {
    for (x = 0; x < SIZE; x++) {
      scanf("%d", &card[x][y]);
    }
  }

  // 当たりの番号たちを入力
  for (int i = 0; i < 5; i++) {
    int tmp;
    scanf("%d", &tmp);
    hits[i] = tmp;
  }

  // 新品のビンゴカードを表示
  for (y = 0; y < SIZE; y++) {
    for (x = 0; x < SIZE; x++) {
      printf(" %2d", card[x][y]);
    }
    printf("\n");
  }

  // 横線を表示
  for (int i = 0; i < SIZE; i++) {
    printf(" --");
  }
  printf("\n");

  // 穴あきのビンゴカードを表示
  for (y = 0; y < SIZE; y++) {
    for (x = 0; x < SIZE; x++) {

      // 当たりの番号だったら -1 にする
      for (int i = 0; i < 5; i++) {
        if (card[x][y] == hits[i]) {
          card[x][y] = -1;
          break;
        }
      }

      if (card[x][y] == -1) {
        printf(" ・");
      } else {
        printf(" %2d", card[x][y]);
      }
    }

    printf("\n");
  }

  // タテ・ヨコのビンゴ判定
  for (y = 0; y < SIZE; y++) {
    int isBingoRow = 1;
    int isBingoCol = 1;

    for (x = 0; x < SIZE; x++) {
      if (card[x][y] != -1) {
        isBingoRow = 0;
      }
      if (card[y][x] != -1) {
        isBingoCol = 0;
      }
    }

    if (isBingoRow || isBingoCol) {
      isBingo = 1;
      break;
    }
  }

  // ナナメのビンゴ判定
  if (!isBingo) {
    int isBingoDiag1 = 1;
    int isBingoDiag2 = 1;

    for (int i = 0; i < SIZE; i++) {
      if (card[i][i] != -1) {
        isBingoDiag1 = 0;
      }

      if (card[i][SIZE - i - 1] != -1) {
        isBingoDiag2 = 0;
      }
    }

    if (isBingoDiag1 || isBingoDiag2) {
      isBingo = 1;
    }
  }

  if (isBingo) {
    printf("Bingo!\n");
  } else {
    printf("Not Bingo\n");
  }

  return 0;
}
