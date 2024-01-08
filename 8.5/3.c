#include <stdio.h>
#include <string.h>

int main() {
  char str1[100];
  char str2[100];

  scanf("%s", str1);
  scanf("%s", str2);

  int lenDiff = strlen(str1) - strlen(str2);

  if (lenDiff < 0) {
    lenDiff = -lenDiff;
  }

  printf("長さの差は%dです。\n", lenDiff);

  printf("%sと%sは", str1, str2);

  if (strcmp(str1, str2) == 0) {
    printf("同じ文字列です。\n");
  } else {
    printf("異なる文字列です。\n");
  }

  return 0;
}
