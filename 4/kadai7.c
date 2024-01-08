#include <stdio.h>

int main() {
  int data1[5];
  int data2[5];
  int max = 0;

  for (int i = 0; i < 5; i++) {
    scanf("%d", &data1[i]);

    if (data1[i] > max) {
      max = data1[i];
    }
  }

  int data2Index = 0;

  for (int i = 0; i < 5; i++) {
    if (data1[4 - i] == max) continue;

    data2[data2Index] = data1[4 - i];
    data2Index++;
  }

  printf("max : %d\n", max);
  for (int i = 0; i < data2Index; i++) {
    printf("data2[%d] : %d\n", i, data2[i]);
  }

  return 0;
}
