#include <stdio.h>

int main() {
  int numbers[4][5] = {
      {9342, 9104, 9952, 9922, 9942},
      {9953, 9388, 9942, 9919, 9950},
      {9112, 9455, 9667, 9921, 9001},
      {9588, 9959, 9951, 9954, 9910},
  };

  int max = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      if (numbers[i][j] > max) {
        max = numbers[i][j];
      }
    }
  }

  printf("max = %d\n", max);

  return 0;
}
