#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

Node *graph[MAX_N];
int color[MAX_N];

bool dfs(int v, int c) {
  // 現在の頂点を色cで塗る
  color[v] = c;
  // vの隣接リストを走査
  for (Node *cur = graph[v]; cur != NULL; cur = cur->next) {
    // 隣接する頂点が同じ色で塗られている場合、二部グラフの条件を満たさない

    if (color[cur->vertex] == c)
      return false;
    // 隣接する頂点が未訪問の場合、再帰的にdfsを呼び出し、異なる色で塗る
    if (color[cur->vertex] == -1 && !dfs(cur->vertex, 1 - c))
      return false; // dfsがfalseを返した場合、二部グラフの条件を満たさない
  }
  // すべての隣接頂点を無事に塗り分けることができた場合、trueを返す
  return true;
}

int main() {
  int N, M;
  if (scanf("%d %d", &N, &M) != 2)
    return -1;

  for (int i = 0; i < N; i++) {
    graph[i] = NULL;
    color[i] = -1;
  }

  // すべての辺のノードを一度に割り当てる
  Node *edges = malloc(2 * M * sizeof(Node));
  int idx = 0;

  for (int i = 0; i < M; i++) {
    int u, v;
    if (scanf("%d %d", &u, &v) != 2)
      return -1;
    u--;
    v--;

    edges[idx].vertex = v;
    edges[idx].next = graph[u];
    graph[u] = &edges[idx++];

    edges[idx].vertex = u;
    edges[idx].next = graph[v];
    graph[v] = &edges[idx++];
  }

  // 二部グラフであるか判定
  bool is_bipartite = true;
  for (int i = 0; i < N; i++) {
    // すべての頂点に対してループ
    if (color[i] == -1 && !dfs(i, 0)) {
      // 未訪問の頂点に対してDFSを実行
      // dfs関数は、二部グラフの条件を満たす場合にtrueを返す
      // もしdfsがfalseを返した場合、グラフは二部グラフではない
      is_bipartite = false;
      // 一つでも二部グラフの条件を満たさない場合、ループを中断
      break;
    }
  }

  printf(is_bipartite ? "Yes\n" : "No\n");

  // メモリの解放
  free(edges);
  
  return 0;
}
