#include <stdio.h>

typedef struct Person {
  char name[32];  // name
  double height;  // height
  double weight;  // weight
} Person;

double getBMT(Person p) {
  double meterHeight = p.height / 100;
  return p.weight / (meterHeight * meterHeight);
}

int main() {
  Person bob = {"bob", 170.0, 65.0};

  double bmi = getBMT(bob);

  printf("%10s  %5.1f %5.1f (%5.1f)\n", bob.name, bob.height, bob.weight, bmi);

  return 0;
}
