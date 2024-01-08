#include <stdio.h>

int main() {
  int n, i, fac;

  printf("n=");
  scanf("%d", &n);

  fac = n;
  for (i = n - 1; i > 1; i--) {
    fac *= i;
  }

  printf("factorial = %d\n", fac);

  return 0;
}
