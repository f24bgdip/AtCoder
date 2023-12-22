#include <stdio.h>

int main() {
  int N;
  long long S;
  scanf("%d %lld", &N, &S);

  long long A[N];
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  long long total = 0;
  for (int l = 0; l < N; l++) {
    long long sum = 0;
    int count = 0;
    for (int r = l; r < N; r++) {
      sum += A[r];
      if (sum > S) {
        count++;
        sum = A[r];
      }
    }
    total += count + 1; // 各部分列の最後の分解数を加える
  }

  printf("%lld\n", total);
  return 0;
}
