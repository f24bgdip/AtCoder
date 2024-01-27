// This code is based on #46435210.

#include <float.h>
#include <stdio.h>

// 制約条件を満たすかを判定する関数
int is_valid(int n, int a[n], int b[n], int c[n], double k) {
  double lb = 0, ub = k;
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      double new_ub = (c[i] - b[i] * k) / (double)(a[i] - b[i]);
      if (ub > new_ub)
        ub = new_ub;
    } else if (a[i] < b[i]) {
      double new_lb = (b[i] * k - c[i]) / (double)(b[i] - a[i]);
      if (lb < new_lb)
        lb = new_lb;
    } else if (c[i] < b[i] * k) {
      return 0;
    }
  }
  return lb <= ub;
}

int main() {
  int n;
  if (scanf("%d", &n) != 1)
    return -1;

  int a[n], b[n], c[n];
  for (int i = 0; i < n; ++i) {
    if (scanf("%d %d %d", &a[i], &b[i], &c[i]) != 3)
      return -1;
  }

  double lb = 0, ub = 1e9;
  for (int i = 0; i < 100; ++i) {
    double mid = (lb + ub) / 2;
    if (is_valid(n, a, b, c, mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }

  printf("%.15f\n", lb);
  return 0;
}
