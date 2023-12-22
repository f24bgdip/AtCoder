#include <stdio.h>
#include <stdlib.h>

long long *input(long n, long max) {
  long long *cnt = (long long *)calloc(max, sizeof(long long));
  if (cnt == NULL)
    return NULL;

  long val, times;
  for (long i = 0; i < n; i++) {
    if (scanf("%ld %ld", &val, &times) != 2) {
      free(cnt);
      return NULL;
    }
    cnt[val] += times;
  }
  return cnt;
}

long process(long long *cnt, long long k, long max) {
  long val;
  for (val = 1; val < max; val++) {
    if (cnt[val] >= k)
      break;
    else
      k -= cnt[val];
  }
  return val;
}

int main(void) {
  const long MAX = 100001;
  long n;
  long long k;

  if (scanf("%ld %lld", &n, &k) != 2)
    return -1;

  long long *cnt = input(n, MAX);
  if (cnt == NULL)
    return -1;

  long val = process(cnt, k, MAX);

  printf("%ld\n", val);

  free(cnt);
  return 0;
}
