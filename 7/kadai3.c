#include <stdio.h>
#include <string.h>

int main() {
  char buf[100] = "";

  while (1) {
    char input[100];
    char safeBuf[100];

    printf("string >> ");
    scanf("%s", input);

    if (strcmp(input, "end") == 0) {
      break;
    }

    strcpy(safeBuf, buf);

    sprintf(buf, "%s %s", safeBuf, input);

    if (strlen(buf) >= 20) {
      printf("#%s#\n", safeBuf);
      strcpy(buf, input);
    }
  }

  printf("#%s#\n", buf);

  return 0;
}
