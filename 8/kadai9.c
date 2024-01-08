#include <stdio.h>

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int data[6];

  int maxScore = 0, minScore = 50;

  for (int i = 0; i < 6; i++) {
    scanf("%d", &data[i]);

    maxScore = max(maxScore, data[i]);
    minScore = min(minScore, data[i]);
  }

  int acceptedSum = 0;
  int isMaxExcepted = 0, isMinExcepted = 0;

  for (int i = 0; i < 6; i++) {
    if (data[i] == maxScore && !isMaxExcepted) {
      isMaxExcepted = 1;
    } else if (data[i] == minScore && !isMinExcepted) {
      isMinExcepted = 1;
    } else {
      acceptedSum += data[i];
    }
  }

  printf("平均 = %.1f\n", acceptedSum / 4.0);

  return 0;
}
