#include <stdio.h>

int janken(int me, int you) {
  return (me - you + 3) % 3;
}

int main() {
  int me, you;

  scanf("%d %d", &me, &you);

  switch (janken(me, you)) {
    case 0:
      printf("Even\n");
      break;
    case 1:
      printf("You loose...\n");
      break;
    default:
      printf("You win!\n");
      break;
  }

  return 0;
}
