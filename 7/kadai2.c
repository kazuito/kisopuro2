#include <stdio.h>
#include <string.h>

int main() {
  char string[100] = "";

  while (1) {
    char tmp[100];
    scanf("%s", tmp);

    if (strcmp(tmp, "end") == 0) {
      break;
    }

    strcat(string, tmp);
  }

  printf("%s\n", string);

  return 0;
}
