#include <stdio.h>

int main() {
  int max;

  scanf("%d", &max);

  for (int n = 0; n <= max; n++) {
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        printf("%d is not prime\n", n);
        break;
      } else if (i == n - 1) {
        printf("%d is prime\n", n);
      }
    }
  }

  return 0;
}
