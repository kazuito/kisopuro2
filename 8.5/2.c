#include <stdio.h>

int main() {
  char str[100];
  char reversed[100];

  scanf("%s", str);

  int i = 0;

  while (str[i] != '\0') {
    i++;
  }

  int len = i;

  for (int i = 0; i < len; i++) {
    reversed[i] = str[len - i - 1];
  }

  printf("%s\n", reversed);

  return 0;
}
