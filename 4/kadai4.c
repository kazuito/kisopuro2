#include <stdio.h>

int main() {
  int data[5];
  int max = 0;

  for (int i = 0; i < 5; i++) {
    scanf("%d", &data[i]);
  }

  for (int i = 0; i < 5; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  printf("max : %d\n", max);
  printf("others :");

  for (int i = 0; i < 5; i++) {
    if (data[i] != max) {
      printf(" %d", data[i]);
    }
  }

  printf("\n");

  return 0;
}
