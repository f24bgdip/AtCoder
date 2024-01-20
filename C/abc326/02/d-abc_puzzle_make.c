#include <stdio.h>
#include <string.h>

#define MAX_PATTERN_SIZE 5

void swap(char *x, char *y) {
  char temp = *x;
  *x = *y;
  *y = temp;
}

int next_permutation(char *array, int size) {
  int i = size - 2;
  while (i >= 0 && array[i] >= array[i + 1]) {
    i--;
  }

  if (i < 0) {
    return 0;
  }

  int j = size - 1;
  while (array[j] <= array[i]) {
    j--;
  }

  swap(&array[i], &array[j]);

  int left = i + 1;
  int right = size - 1;
  while (left < right) {
    swap(&array[left++], &array[right--]);
  }

  return 1;
}

void generate_patterns(char start_char) {
  char chars[MAX_PATTERN_SIZE] = "ABC  ";
  int size = strlen(chars);

  do {
    if (chars[0] == start_char && strchr(chars + 1, 'A') == NULL &&
        strchr(chars + 1, 'B') == NULL && strchr(chars + 1, 'C') == NULL) {
      printf("%s\n", chars);
    }
  } while (next_permutation(chars, size));
}

int main() {
  printf("Patterns starting with 'A':\n");
  generate_patterns('A');

  printf("\nPatterns starting with 'B':\n");
  generate_patterns('B');

  printf("\nPatterns starting with 'C':\n");
  generate_patterns('C');

  return 0;
}
