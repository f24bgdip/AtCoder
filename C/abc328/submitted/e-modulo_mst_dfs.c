/*
 * With respect to the original solution.
 * This program is based on a solution example (#47533147)
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEXES 8 + 1
#define MAX_EDGES 28 + 1

typedef struct {
  int vertex;
  long long weight;
} Edge;

typedef struct {
  Edge edges[MAX_EDGES];
  int size;
} EdgeList;

EdgeList graph[MAX_EDGES];
long long int K;
long long int min_cost = LLONG_MAX;

void init(int n) {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
}

int find(int x) {
  if (parent[x] == x)
    return x;
  return find(parent[x]);
}

int dfs(int u, int n, long long int cost) {
  if (u == n) {
    if (min_cost > cost)
      min_cost = cost;
    // printf("min: %lld cost:%lld\n", cost, min_cost);
    return 1;
  }
  for (int i = 1; i <= graph[u].size; i++) {
    int v = graph[u].edges[i].vertex;
    long long int weight = graph[u].edges[i].weight;
    // printf("size: %d u:%d v:%d weight %lld\n", graph[u].size, u, v, weight);

    int parent1 = find(u);
    int parent2 = find(v);

    if (parent1 != parent2) {
      int temp = parent[parent1];
      parent[parent1] = parent2;
      dfs(u + 1, n, (cost + weight) % K);
      parent[parent1] = temp;
    }
  }
  // printf("min: %lld total:%lld\n", cost, min_cost);

  return 0;
}

int main() {
  int n, m;
  if (scanf("%d %d %lld", &n, &m, &K) != 3)
    return -1;

  for (int i = 1; i <= m; i++) {
    int u, v;
    long long int w;
    if (scanf("%d %d %lld", &u, &v, &w) != 3)
      return -1;

    graph[u].edges[graph[u].size + 1] = (Edge){v, w};
    graph[u].size++;
    graph[v].edges[graph[v].size + 1] = (Edge){u, w};
    graph[v].size++;
  }

  init(n);

  dfs(1, n, 0);

  printf("%lld\n", min_cost);

  return 0;
}
