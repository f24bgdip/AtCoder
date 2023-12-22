#include <stdio.h>
#include <stdlib.h>

#define MAX_REPUNIT 16

long long generate(int n) {
  long long repunit = 0;
  for (int i = 0; i < n; i++) {
    repunit = repunit * 10 + 1;
  }
  return repunit;
}

int compare(const void *a, const void *b) {
  long long val1 = *(const long long *)a;
  long long val2 = *(const long long *)b;
  if (val1 < val2)
    return -1;
  if (val1 > val2)
    return 1;
  return 0;
}

int main() {
  long long repunits[MAX_REPUNIT];
  long long sums[MAX_REPUNIT * MAX_REPUNIT * MAX_REPUNIT];
  int n, sumIndex = 0;

  for (int i = 1; i <= MAX_REPUNIT; i++) {
    repunits[i - 1] = generate(i);
  }

  for (int i = 0; i < MAX_REPUNIT; i++) {
    for (int j = 0; j < MAX_REPUNIT; j++) {
      for (int k = 0; k < MAX_REPUNIT; k++) {
        sums[sumIndex++] = repunits[i] + repunits[j] + repunits[k];
      }
    }
  }

  qsort(sums, sumIndex, sizeof(long long), compare);

  int uniqueIndex = 1;
  for (int i = 1; i < sumIndex; i++) {
    if (sums[i] != sums[i - 1]) {
      sums[uniqueIndex++] = sums[i];
    }
  }

  scanf("%d", &n);
  printf("%lld\n", sums[n - 1]);

  return 0;
}
