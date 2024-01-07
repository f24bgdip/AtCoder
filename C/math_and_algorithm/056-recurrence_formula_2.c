#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ll long long
#define MOD 1000000007
#define MAX_MATRIX_SIZE 3 // 最大行列サイズ

// 指定されたサイズの単位行列を初期化する関数
void initialize_identity_matrix(int size, ll matrix[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j)
        matrix[i][j] = 1;
      else
        matrix[i][j] = 0;
    }
  }
}

// 指定されたサイズの単位行列を初期化する関数
void clear_matrix(int size, ll matrix[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = 0;
    }
  }
}

// 行列乗算を行う関数
// size: 行列のサイズ
// matA: 乗算の左側にある行列
// matB: 乗算の右側にある行列
// result: 結果を格納する行列
// mod: 乗算結果に適用されるモジュラス値
void matrix_multiply(int size, ll matA[size][size], ll matB[size][size],
                     ll result[size][size], ll mod) {
  // 行列のサイズが最大値を超える場合は処理を中断
  if (size > MAX_MATRIX_SIZE)
    return;
  // 結果を一時的に格納するための行列
  ll temp[size][size];
  clear_matrix(size, temp);

  // 3重ループによる行列の乗算処理
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      for (int k = 0; k < size; k++)
        temp[i][j] = (temp[i][j] + matA[i][k] * matB[k][j]) % mod;

  memcpy(result, temp, sizeof(temp));
}

void print_matrix(int size, ll matrix[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%lld ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// 行列の累乗を行う関数
// mat: 累乗する行列
// n: 累乗の度数
void matrix_power(int size, ll mat[size][size], ll n, ll mod) {
  // nが0または1の場合、行列の累乗は不要
  if (n == 0 || n == 1)
    return;

  ll temp[size][size];
  initialize_identity_matrix(size, temp);

  while (n > 0) {
    if (n % 2 == 1) {
      matrix_multiply(size, mat, temp, temp, mod);
    }
    matrix_multiply(size, mat, mat, mat, mod);
    n /= 2;
  }
  memcpy(mat, temp, sizeof(temp));
}

ll fibonacci(ll n, ll mod) {
  int matrix_size = 2;
  if (n == 1 || n == 2)
    return 1;

  ll coeff_matrix[2][2] = {{1, 1}, {1, 0}};
  matrix_power(matrix_size, coeff_matrix, n - matrix_size, MOD);
  // n = 1, 2の結果を含んだ状態行列
  ll result_state[2][2] = {{1, 0}, {1, 1}};
  // coeff_matrixとresult_stateの内積を計算
  matrix_multiply(matrix_size, coeff_matrix, result_state, result_state, mod);

  return (result_state[0][0]);
}

ll tribonacci(ll n, ll mod) {
  int matrix_size = 3;
  // nが1または2の場合、トリボナッチ数列は1を返す
  if (n == 1 || n == 2)
    return 1;
  // nが3の場合、トリボナッチ数列は2を返す
  if (n == 3)
    return 2;

  // トリボナッチ数列の係数行列の定義
  ll coeff_matrix[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
  // coeff_matrixをn-3乗する
  matrix_power(matrix_size, coeff_matrix, n - matrix_size, mod);
  // n = 1, 2, 3の結果を含んだ状態行列、result[0][0]に解を生成する
  ll result_state[3][3] = {{2, 0, 0}, {1, 1, 0}, {1, 0, 1}};
  // coeff_matrixとresult_stateの内積を計算
  matrix_multiply(matrix_size, coeff_matrix, result_state, result_state, mod);

  return (result_state[0][0]);
}

int main() {
  ll n;
  if (scanf("%lld", &n) != 1)
    return -1;

  // fibonacci
  printf("%lld\n", fibonacci(n, MOD));
  // tribonacci
  printf("%lld\n", tribonacci(n, MOD));

  return 0;
}
