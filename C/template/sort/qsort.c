
// ascending order
int cmp_int(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
// descending order
int cmp_int(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int cmp_int_2d(const void *a, const void *b) {
  int *a_ = (int *)a;
  int *b_ = (int *)b;

  // 最初の値で昇順ソート
  if (a_[0] < b_[0])
    return -1;
  if (a_[0] > b_[0])
    return 1;

  // 次の値で昇順ソート
  if (a_[1] < b_[1])
    return -1;
  if (a_[1] > b_[1])
    return 1;

  return 0;
}

int main() {
  qsort(weights, N, sizeof(int), cmp_int);

  int P[N][2];
  for (int i = 0; i < N; i++) {
    if (scanf("%d %d", &P[i][0], &P[i][1]) != 2)
      return -1;
  }

  qsort(b, m, sizeof(int) * 2, cmp_int_2d);

  return 0;
}