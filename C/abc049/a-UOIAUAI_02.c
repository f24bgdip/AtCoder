#include <stdio.h>

int main(void) {
  const char *vowels = "aeiou";
  char c;

  if (scanf("%c", &c) != 1)
    return -1;

  for (int i = 0; vowels[i] != '\0'; i++) {
    if (vowels[i] == c) {
      printf("vowel\n");
      return 0;
    }
  }

  printf("consonant\n");
  return 0;
}
