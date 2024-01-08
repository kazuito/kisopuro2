#include <stdio.h>

int main() {
  int data[5];
  int max = 0;
  int maxCount = 0;

  for (int i = 0; i < 5; i++) {
    scanf("%d", &data[i]);
  }

  for (int i = 0; i < 5; i++) {
    if (data[i] > max) {
      max = data[i];
      maxCount = 1;
    } else if (data[i] == max) {
      maxCount++;
    }
  }

  printf("max ( %d 個) : %d\n", maxCount, max);
  return 0;
}
