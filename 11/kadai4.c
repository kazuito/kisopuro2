#include <stdio.h>

#define MAGIC 1
#define NOT_MAGIC 0

#define SIZE 3

int isMagicSquare(int nums[SIZE][SIZE]) {
  int sum = 0;
  int sum2 = 0;

  for (int i = 0; i < SIZE; i++) {
    sum += nums[i][i];
    sum2 += nums[i][SIZE - (1 + i)];
  }

  if (sum != sum2) return NOT_MAGIC;

  for (int i = 0; i < SIZE; i++) {
    int sum3 = 0;
    int sum4 = 0;

    for (int j = 0; j < SIZE; j++) {
      sum3 += nums[i][j];
      sum4 += nums[j][i];
    }

    if (sum != sum3 || sum != sum4) {
      return NOT_MAGIC;
    }
  }

  return MAGIC;
}

int main() {
  int matrix[SIZE][SIZE];
  int x, y;

  for (y = 0; y < SIZE; y++) {
    for (x = 0; x < SIZE; x++) {
      scanf("%d", &matrix[x][y]);
    }
  }

  for (y = 0; y < SIZE; y++) {
    for (x = 0; x < SIZE; x++) {
      printf("%d ", matrix[x][y]);
    }
    printf("\n");
  }

  if (isMagicSquare(matrix) == MAGIC)
    printf("Magic Square\n");
  else
    printf("Not Magic Square\n");

  return 0;
}
