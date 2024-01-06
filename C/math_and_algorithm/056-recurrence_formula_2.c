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

// 行列の累乗を行う関数
// mat: 累乗する行列
// n: 累乗の度数
void matrix_power(int size, ll mat[size][size], ll n, ll mod) {
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

  return (coeff_matrix[0][0] + coeff_matrix[0][1]);
}

// トリボナッチ数列の第 N 項を計算する関数
ll tribonacci(ll n, ll mod) {
  int matrix_size = 3;
  if (n == 1 || n == 2)
    return 1;
  if (n == 3)
    return 2;

  ll coeff_matrix[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
  matrix_power(matrix_size, coeff_matrix, n - matrix_size, MOD);

  return (coeff_matrix[0][0] + coeff_matrix[0][1] + coeff_matrix[0][2]) % MOD;
}

int main() {
  ll n;
  if (scanf("%lld", &n) != 1)
    return -1;

  // printf("fibonacci = %lld\n", fibonacci(n, MOD));
  printf("tribonacci = %lld\n", tribonacci(n, MOD));

  return 0;
}
