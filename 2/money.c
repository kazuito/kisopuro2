#include <stdio.h>

int main() {
  int amount;
  int coin_count = 6;
  int coins[] = {500, 100, 50, 10, 5, 1};
  int coin_nums[coin_count];

  scanf("%d", &amount);

  for (int i = 0; i < coin_count; i++) {
    coin_nums[i] = amount / coins[i];
    amount %= coins[i];
  }

  for (int i = 0; i < coin_count; i++) {
    printf("%d:%d", coins[i], coin_nums[i]);

    if (i < coin_count - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }

  return 0;
}
