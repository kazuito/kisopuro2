#include <stdio.h>

int main() {
  int a, b, c, ans;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if (a > b && a > c)
    ans = a;
  else if (b > a && b > c)
    ans = b;
  else
    ans = c;

  printf("Max: %d\n", ans);
  return 0;
}
