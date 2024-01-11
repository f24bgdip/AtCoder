#include <stdio.h>
#include <stdlib.h>

int main() {
  long long N, X, Y;
  if (scanf("%lld %lld %lld", &N, &X, &Y) != 3)
    return -1;

  // 距離の偶奇性と到達可能距離をチェック
  // 距離の偶奇性: コマが N ステップで (,)(X,Y) に到達するためには、X+Y と N
  // の偶奇が一致していなければならない
  // 到達可能距離: N ステップで到達できる最大の距離は N。したがって、
  // |X∣+∣Y∣ は N を超えてはならず、|X∣ +∣Y∣ ≤ N でなければならない
  if (((abs(X) + abs(Y)) <= N) && ((N - abs(X) - abs(Y)) % 2 == 0)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
