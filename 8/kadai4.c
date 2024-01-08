#include <stdio.h>

int withTax(int price, float taxRate) {
  return price * taxRate;
}

int main() {
  int price;
  float taxRate;

  printf("price = ");
  scanf("%d", &price);

  printf("taxRate = ");
  scanf("%f", &taxRate);

  printf("result = %d\n", withTax(price, taxRate));

  return 0;
}
