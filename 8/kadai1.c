#include <stdio.h>

int factorial(int n) {
  int f = n;

  for (int i = n - 1; i > 1; i--) {
    f *= i;
  }

  return f;
}

int main() {
  int n, m;

  printf("n = ");
  scanf("%d", &n);

  printf("m = ");
  scanf("%d", &m);

  printf("n! + m! = %d\n", factorial(n) + factorial(m));

  return 0;
}
