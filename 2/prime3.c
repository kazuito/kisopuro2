#include <stdio.h>

int main() {
  int max;

  scanf("%d", &max);

  for (int num = 2; num <= max; num++) {
    int isPrime = 1;

    for (int i = 2; i < num; i++) {
      if (num % i == 0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime) {
      printf("%d is prime\n", num);
    } else {
      printf("%d is not prime\n", num);
    }
  }

  return 0;
}
