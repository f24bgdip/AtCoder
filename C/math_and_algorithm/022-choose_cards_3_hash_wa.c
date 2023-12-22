#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100000
#define HASH_SIZE 100001 // MAX_VALUE + 1

int hash[HASH_SIZE] = {0};

int main() {
  int N;
  scanf("%d", &N);

  int A[200000];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    hash[A[i]]++;
  }

  int count = 0;
  for (int i = 0; i < N; i++) {
    int complement = MAX_VALUE - A[i];
    if (complement >= 0 && hash[complement]) {
      if (complement == A[i]) {
        // 同じ値の場合、自分自身を除く
        count += hash[complement] - 1;
      } else {
        count += hash[complement];
      }
    }
  }

  // 特殊ケース
  if (hash[50000] > 1) {
    count += (hash[50000] * (hash[50000] - 1) / 2);
  }

  // 各ペアが2回カウントされているため、2で割る
  printf("%d\n", count / 2);
  return 0;
}
