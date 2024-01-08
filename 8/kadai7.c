#include <stdio.h>

int isLeap(int year) {
  return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int main() {
  int year;

  scanf("%d", &year);

  if (isLeap(year)) {
    printf("%d is leap year.\n", year);
  } else {
    printf("%d is not leap year.\n", year);
  }

  return 0;
}
