#include <stdio.h>

int min(int A, int b) { return (A < b) ? A : b; }
int max(int A, int b) { return (A > b) ? A : b; }

int main(void) {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  double P, Q;
  double sum_q = 0;
  for (int i = 0; i < N; i++) {
    if (scanf("%lf %lf", &P, &Q) != 2)
      return -1;
    sum_q += Q / P;
  }

  printf("%.12f", sum_q);
  return 0;
}