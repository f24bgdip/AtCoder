#include <stdio.h>

int sum(long long b, long long n, long long *s) {
  if (n < b) {
    *s -= n;
    return *s == 0;
  } else {
    *s -= n % b;
    if (*s < 0)
      return 0;
    return sum(b, n / b, s);
  }
}

// 基数bと数値nを受け取り、nをb進数に変換した後の各桁の和を計算する関数
long long f(long long b, long long n) { // 計算量はO(log_b(n))
  long long sum = 0;
  while (n > 0) {
    sum += n % b; // nをbで割った余り（現在の桁の値）をsumに加える
    n /= b;       // nをbで割って次の桁に進む
  }
  return sum;
}

int main(void) {
  long long n, s, b;
  int found = 0;

  if (scanf("%lld %lld", &n, &s) == 0)
    return -1;

  if (n == s) {
    printf("%lld\n", n + 1);
    return 0;
  }

  // 基数bの最大値をsqrt(n)と制限
  max = (int)sqrt(n);

  for (long long b = 2; b <= max; b++) {
    long long s_test = s;
    if (sum(b, n, &s_test)) {
      printf("%lld\n", b);
      found = 1;
      break;
    }
  }

  if (!found) {
    
  }else
    printf("-1\n");
  }

  return 0;
}