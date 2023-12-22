#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 8 + 1

typedef struct {
  int u, v;
  long long int weight;
} Edge;

long long int K;
int parent[MAX_VERTEX];

void init(int n) {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
}

int find(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y)
    parent[x] = y;
}

int compare_edge(const void *a, const void *b) {
  long long int diff = ((Edge *)a)->weight - ((Edge *)b)->weight;
  if (diff < 0)
    return -1;
  else if (diff > 0)
    return 1;
  else
    return 0;
}

long long int kruskal(Edge *edges, int n, int m) {
  long long int cost = 0;
  qsort(edges, m, sizeof(Edge), compare_edge);
  init(n);

  for (int i = 0; i < m; i++) {
    Edge e = edges[i];
    if (find(e.u) != find(e.v)) {
      cost += e.weight;
      cost %= K;
      unite(e.u, e.v);
    }
  }
  return cost;
}

int main() {
  int n, m;
  if (scanf("%d %d %lld", &n, &m, &K) != 3)
    return -1;

  Edge edges[m];
  for (int i = 0; i < m; i++) {
    if (scanf("%d %d %lld", &edges[i].u, &edges[i].v, &edges[i].weight) != 3)
      return -1;
  }

  long long int result = kruskal(edges, n, m);
  printf("%lld\n", result);

  return 0;
}
