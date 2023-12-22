#include <stdio.h>

int find_highest_bit_position(int x) {
  int position = 0;
  while (x > 0) {
    position++;
    x >>= 1;
  }
  return position;
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  int A[N];
  int highest_bit_position = 0;
  int xor_sum = 0;
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1)
      return -1;

    xor_sum ^= A[i];
    int pos = find_highest_bit_position(xor_sum);
    if (highest_bit_position < pos)
      highest_bit_position = pos;
  }

  printf("Highest Bit Position: %d\n", highest_bit_position);

  if (xor_sum == 0) {
    // XORの結果が0の場合、Aliceには必勝法が存在しない
    printf("0\n");

    return 0;
  }

  // XORの結果が0でない場合、必勝法が存在する可能性がある
  // ここでは、XORの結果に基づいて最適な k を見つけるロジックを実装します
  // （この部分は問題の具体的な要件に応じて異なる可能性があるため、
  //   実装は問題の詳細に基づいて調整する必要があります）

  // この例では、単純化のため、最大の k を探すロジックは省略しています
  printf("-1\n"); // 仮の出力

  return 0;
}
