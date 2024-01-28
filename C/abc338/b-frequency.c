#include <stdio.h>
#include <string.h>

int main() {
  char S[1001];
  if (scanf("%s", S) != 1)
    return -1;

  int frequency[26] = {0};
  for (int i = 0; S[i] != '\0'; i++) {
    frequency[S[i] - 'a']++;
  }

  char result = 'a';
  int maxFrequency = 0;
  for (int i = 0; i < 26; i++) {
    if (frequency[i] > maxFrequency) {
      maxFrequency = frequency[i];
      result = 'a' + i;
    }
  }

  printf("%c\n", result);

  return 0;
}
