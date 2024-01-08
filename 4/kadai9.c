#include <stdio.h>

int main() {
  int data[100];

  for (int i = 0; i < 100; i++) {
    data[i] = 0;
  }

  for (int i = 0; i < 5; i++) {
    int tmp;
    scanf("%d", &tmp);

    data[tmp]++;
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < data[i]; j++) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}
