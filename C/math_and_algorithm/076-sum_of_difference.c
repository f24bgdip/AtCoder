// 076 - Sum of difference
// 問題: 配列 A の全ての組 (i<j) について |Ai - Aj| の総和を求める。
// 解法: 値を昇順ソートし、累積和で寄与を計算。O(N log N)

#include <stdio.h>
#include <stdlib.h>

static int cmp_ll(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    long long *A = (long long *)malloc(sizeof(long long) * (size_t)N);
    if (!A) return 0;
    for (int i = 0; i < N; ++i) {
        if (scanf("%lld", &A[i]) != 1) {
            free(A);
            return 0;
        }
    }

    qsort(A, (size_t)N, sizeof(long long), cmp_ll);

    long long prefix = 0;   // 先頭から i-1 までの和
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        // 現在の要素が右側の要素として寄与する分: A[i] * i - prefix
        ans += A[i] * i - prefix;
        prefix += A[i];
    }

    printf("%lld\n", ans);

    free(A);
    return 0;
}

