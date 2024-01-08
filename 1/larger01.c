#include <stdio.h>

int main() {
  int a, b;

  scanf("%d", &a);
  scanf("%d", &b);

  printf("大きい方の数は");

  if (a > b) {
    printf("%d", a);
  } else {
    printf("%d", b);
  }

  printf("やで。\n");

  return 0;
}
