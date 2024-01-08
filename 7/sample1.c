#include <stdio.h>

int main() {
  char string[100];
  int length = 0;

  scanf("%s", string);

  while (string[length] != '\0') {
    length++;
  }

  printf("%d\n", length);

  return 0;
}
