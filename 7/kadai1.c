#include <stdio.h>

int main() {
  char string[100];
  int i = 0;
  int alphabetCount = 0;
  int numberCount = 0;

  scanf("%s", string);

  while (string[i] != '\0') {
    if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
      alphabetCount++;
    } else if (string[i] >= '0' && string[i] <= '9') {
      numberCount++;
    }

    i++;
  }

  int otherCount = i - alphabetCount - numberCount;

  printf("Alpha=%d Number=%d Else=%d\n", alphabetCount, numberCount, otherCount);

  return 0;
}
