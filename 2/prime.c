#include <stdio.h>

int main() {
  int number;

  scanf("%d", &number);

  if (number < 2) {
    printf("%d is not prime\n", number);
    return 0;
  }

  for (int i = 2; i < number; i++) {
    if (number % i == 0) {
      printf("%d is not prime\n", number);
      return 0;
    }
  }
  printf("%d is prime\n", number);
  return 0;
}
