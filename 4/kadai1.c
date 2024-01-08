#include <stdio.h>

int main() {
  int data[5];

  for (int i = 0; i < 5; i++) {
    scanf("%d", &data[i]);
  }

  for (int i = 0; i < 5; i++) {
    printf("data%d : %d\n", i + 1, data[4 - i]);
  }
}
