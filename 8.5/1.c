#include <stdio.h>

int main() {
  char str[100] = "Hello, World!";

  int i = 0;

  while (str[i] != '\0') {
    if (str[i] == 'l') {
      str[i] = '1';
    }
    i++;
  }

  printf("%s\n", str);

  return 0;
}
