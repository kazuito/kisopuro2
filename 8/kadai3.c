#include <stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  }

  return b;
}

int main() {
  int a, b, c;

  printf("a = ");
  scanf("%d", &a);

  printf("b = ");
  scanf("%d", &b);

  printf("c = ");
  scanf("%d", &c);

  printf("max = %d\n", max(max(a, b), c));

  return 0;
}
