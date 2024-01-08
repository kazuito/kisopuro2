#include <stdio.h>

int main() {
  int data[100];

  for (int i = 0; i < 100; i++) {
    data[i] = 0;
  }

  for (int i = 0; i < 5; i++) {
    int tmp;
    scanf("%d", &tmp);

    data[tmp] = 1;
  }

  for (int i = 0; i < 100; i++) {
    if (data[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}
