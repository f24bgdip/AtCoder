#include <stdio.h>

typedef long long ll;

ll solve(ll N) {
  ll payment = 0;
  while (N > 1) {
    if (N % 2 == 0) { // 偶数の場合
      payment += N;
    } else { // 奇数の場合
      payment += (N + 1);
    }
    N /= 2; // Nを半分にする
  }
  payment += N; // Nが1になった場合の支払い金額
  return payment;
}

int main() {
  ll N;
  scanf("%lld", &N);
  ll result = solve(N);
  printf("%lld\n", result);
  return 0;
}
