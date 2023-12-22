#include <stdbool.h>
#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int total = 0;
  for (int M = 1; M <= N; M++) {
    int D;
    scanf("%d", &D);

    int d = M % 10;
    int dd = d * 10 + d;

    if (M == d || M == dd) {
      int cnt = 0;
      if (D >= dd) {
        cnt = 2;
      } else if (D >= d) {
        cnt = 1;
      }
      total += cnt;
    }
  }

  printf("%d\n", total);

  return 0;
}
