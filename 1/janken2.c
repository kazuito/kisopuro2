#include <stdio.h>
int main() {
  int hand1, hand2;

  scanf("%d", &hand1);
  scanf("%d", &hand2);

  int result = (hand1 - hand2 + 3) % 3;

  if (result == 0) {
    printf("even\n");
  } else if (result == 1) {
    printf("lose\n");
  } else {
    printf("win\n");
  }
  return 0;
}
