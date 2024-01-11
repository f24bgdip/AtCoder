#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {
  ll N, K;
  if (scanf("%lld %lld", &N, &K) != 2)
    return -1;

  int A[N + 1];
  bool visited[N + 1];
  for (int i = 1; i <= N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;
    visited[i] = false;
  }

  // 現在の町
  // 出発地の町1を0とし 最初の移動先を1とする
  int current_town = 1;
  // テレポーターを使用した回数
  int count_teleport = 0;
  // 訪問済みの町にたどり着くまでループ
  // テレポーターの循環を見つける
  while (!visited[current_town]) {
    visited[current_town] = true;
    current_town = A[current_town];
    count_teleport++;
    // もしテレポーターをK回使用したら、
    // 現在の町を出力しプログラムを終了
    if (count_teleport == K) {
      printf("%d\n", current_town);
      return 0;
    }
  }

  // 循環が始まる町を記録
  // この時点での'current_town' は循環の開始点
  int start_of_cycle = current_town;
  // 循環の長さを1から開始
  int cycle_length = 1;
  // 次の町にテレポートして、循環内での移動を開始
  current_town = A[current_town];
  // 循環の全長を計算するためのループ
  while (current_town != start_of_cycle) {
    current_town = A[current_town];
    cycle_length++;
  }

  // 循環に到達するまでの回数をKから引く
  // 残りの回数を循環の長さで割った余りを計算
  K = (K - count_teleport) % cycle_length;
  // 循環内でK回テレポートして、最終的に到達する町を計算するループ
  for (int i = 0; i < K; i++) {
    // 循環内で次の町にテレポート
    start_of_cycle = A[start_of_cycle];
  }
  printf("%d\n", start_of_cycle);

  return 0;
}
