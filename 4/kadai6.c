#include <stdio.h>

int main() {
  int data1[5];
  int data2[5];

  for (int i = 0; i < 5; i++) {
    scanf("%d", &data1[i]);
  }

  for (int i = 0; i < 5; i++) {
    data2[4 - i] = data1[i];
  }

  for (int i = 0; i < 5; i++) {
    printf("data2[%d] : %d\n", i, data2[i]);
  }

  return 0;
}
