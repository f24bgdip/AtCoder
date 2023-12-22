
int cmp_int(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int cmp_int_2d(const void *a, const void *b) {
  int *a_ = (int *)a;
  int *b_ = (int *)b;

  // 値で昇順ソート
  if (a_[0] < b_[0])
    return -1;
  if (a_[0] > b_[0])
    return 1;

  // インデックスで昇順ソート
  if (a_[1] < b_[1])
    return -1;
  if (a_[1] > b_[1])
    return 1;

  return 0;
}

int main() {
  qsort(side_dish, M, sizeof(int) * 2, compare);

  return 0;
}