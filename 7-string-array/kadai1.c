#include <handy.h>
#include <stdio.h>

int main() {
  char string[100];
  printf("input string >> ");
  scanf("%s", string);
  HgOpen(400.0, 400.0);
  HgSetFont(HG_M, 20);

  int i = 0;

  while (string[i] != '\0') {
    HgText(100.0 + 20 * i, 100.0 + 20 * i, "%c", string[i]);
    i++;
  }

  HgGetChar();
  HgClose();

  return 0;
}
