#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200001

int parent[MAX_N];
int rank[MAX_N];
long long diff[MAX_N];

void init(int n) {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
    diff[i] = 0;
  }
}

int find(int x) {
  if (parent[x] == x) {
    return x;
  } else {
    int root = find(parent[x]);
    diff[x] += diff[parent[x]]; // 累積差分を更新
    return parent[x] = root;
  }
}

int unite(int x, int y, long long d) {
  int rootX = find(x);
  int rootY = find(y);
  d += diff[x] - diff[y]; // 差分を加算

  if (rootX == rootY) {
    return (d == 0); // 矛盾がないか確認
  }

  if (rank[rootX] < rank[rootY]) {
    parent[rootX] = rootY;
    diff[rootX] = -d;
  } else {
    parent[rootY] = rootX;
    diff[rootY] = d;
    if (rank[rootX] == rank[rootY])
      rank[rootX]++;
  }
  return 1;
}

int main() {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  init(N + 1); // 頂点数はN+1（1ベース）

  for (int i = 1; i <= Q; i++) {
    int a, b;
    long long d;
    scanf("%d %d %lld", &a, &b, &d);

    if (!unite(a, b, d)) {
      // 矛盾があれば、その条件は無視
      continue;
    }
    printf("%d ", i); // 良い集合に条件のインデックスを追加
  }
  printf("\n");

  return 0;
}
