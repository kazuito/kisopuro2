#include <stdio.h>

int max(int nums[5]) {
  int max = -1;

  for (int i = 1; i < 5; i++) {
    if (max < nums[i]) max = nums[i];
  }

  return max;
}

int main() {
  int nums[5] = {};

  for (int i = 0; i < 5; i++) {
    scanf("%d", &nums[i]);
  }

  printf("max : %d\n", max(nums));

  return 0;
}
