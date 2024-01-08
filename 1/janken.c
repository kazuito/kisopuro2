#include <stdio.h>

int main() {
  int hand1, hand2;

  scanf("%d", &hand1);
  scanf("%d", &hand2);

  if (hand1 == hand2) {
    printf("even\n");
  } else if ((hand1 == 1 && hand2 == 2) ||
             (hand1 == 2 && hand2 == 3) ||
             (hand1 == 3 && hand2 == 1)) {
    printf("win\n");
  } else {
    printf("lose\n");
  }

  return 0;
}
