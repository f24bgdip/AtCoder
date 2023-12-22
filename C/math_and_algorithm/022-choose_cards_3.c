#include <stdio.h>

#define MAX_VALUE 100000
#define HASH_SIZE 100001

int hash[HASH_SIZE] = {0};

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  for (int i = 0; i < N; i++) {
    int value;
    if (scanf("%d", &value) != 1)
      return -1;
    hash[value]++;
  }

  long long count = 0;
  for (int i = 0; i <= 50000; i++) {
    if (i == 50000) {
      count += (long long)hash[i] * (hash[i] - 1) / 2;
    } else {
      int complement = MAX_VALUE - i;
      count += (long long)hash[i] * hash[complement];
    }
  }

  printf("%lld\n", count);
  return 0;
}
