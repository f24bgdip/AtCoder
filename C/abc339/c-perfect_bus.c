#include <stdio.h>

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  // 開始乗客数の初期値
  long long start_passengers = 0;
  // 現在の乗客数の初期値
  long long current_passengers = 0;
  for (int i = 0; i < N; i++) {
    long long A;
    if (scanf("%lld", &A) != 1)
      return -1;

    // 現在の乗客数を更新
    current_passengers += A;
    if (current_passengers < 0) {
      // 負になった分だけ開始乗客数を増やす
      start_passengers += -current_passengers;
      // 乗客数を0にリセット
      current_passengers = 0;
    }
  }

  printf("%lld\n", current_passengers);
  return 0;
}
