#include <stdio.h>

#define PHRASE_SIZE 3

int is_seventeen_syllables(const unsigned int phrase[]) {
  const int HAIKU_NUM_CHARACTERS = 17;
  unsigned int sum = phrase[0] + phrase[1] + phrase[2];

  if (sum != HAIKU_NUM_CHARACTERS) {
    return -1;
  }
  return 0;
}

int is_five_seven_five_structure(const unsigned int phrase[]) {
  int five_count = 0, seven_count = 0;
  for (int i = 0; i < PHRASE_SIZE; i++) {
    if (phrase[i] == 5) five_count++;
    else if (phrase[i] == 7) seven_count++;
  }
  if (five_count == 2 && seven_count == 1) return 0;
  return -1;
}

int main(void) {
  unsigned int phrase[PHRASE_SIZE];

  if (scanf("%u %u %u", &phrase[0], &phrase[1], &phrase[2]) != PHRASE_SIZE) {
    printf("NO\n");
    return -1;
  }

  if (is_seventeen_syllables(phrase) == -1 || is_five_seven_five_structure(phrase) == -1) {
    printf("NO\n");
    return -1;
  }

  printf("YES\n");
  return 0;
}
