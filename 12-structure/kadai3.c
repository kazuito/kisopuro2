#include <stdio.h>

typedef struct Person {
  char name[32];
  double height;
  double weight;
} Person;

double getBMT(Person p) {
  double meterHeight = p.height / 100;
  return p.weight / (meterHeight * meterHeight);
}

int main() {
  Person person[5] = {
      {"Alice", 155.0, 45.0},
      {"Bob", 170.0, 65.0},
      {"Carol", 163.0, 55.0},
      {"Dave", 180.0, 85.0},
      {"Ellen", 160.0, 56.0}};

  Person maxPerson = person[0];

  for (int i = 0; i < 5; i++) {
    double bmi = getBMT(person[i]);

    printf("%10s  %5.1f %5.1f (%5.1f)\n", person[i].name, person[i].height, person[i].weight, bmi);

    if (getBMT(maxPerson) < bmi) {
      maxPerson = person[i];
    }
  }

  printf("== MAX is\n");
  printf("%10s  %5.1f %5.1f (%5.1f)\n", maxPerson.name, maxPerson.height, maxPerson.weight, getBMT(maxPerson));

  return 0;
}
