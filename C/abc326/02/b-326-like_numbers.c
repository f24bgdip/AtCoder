#include <stdio.h>

int like_326(int n) {
  int d[3];
  for (int i = 0; i < 3; i++) {
    d[i] = n % 10;
    n /= 10;
  }
  return (d[2] * d[1] == d[0]);
}

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int n = N;
  while (!like_326(n))
    n++;

  printf("%d\n", n);

  return 0;
}
