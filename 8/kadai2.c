#include <stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  }

  return b;
}

int main() {
  int a, b;

  printf("a = ");
  scanf("%d", &a);

  printf("b = ");
  scanf("%d", &b);

  printf("max = %d\n", max(a, b));

  return 0;
}
