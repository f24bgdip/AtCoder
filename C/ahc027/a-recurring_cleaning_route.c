#include <stdio.h>
#include <stdlib.h>

// Input
#define MAX_N 40

int get_int() {
  int num = 0;
  char c;
  while ((c = getchar()) != ' ' && c != '\n' && c != EOF) {
    if (c >= '0' && c <= '9') {
      num = num * 10 + (c - '0');
    }
  }
  return num;
}

void get_binary(int v, int h, int arr[v][h]) {
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < h; j++) {
      arr[i][j] = getchar() - '0';
    }
    getchar();
  }
}

// Algorithm
#define MAX_VERTEXES 1600 + 1
#define MAX_EDGES 3120 + 1

typedef struct {
  int vertex;
  int dirtiness;
} Edge;

typedef struct {
  Edge edges[MAX_EDGES];
  int size;
} EdgeList;

int parent[MAX_VERTEXES];
int visited[MAX_VERTEXES];
void init(int n) {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    visited[i] = 0;
  }
}

int find(int x) {
  if (parent[x] == x)
    return x;
  return find(parent[x]);
}

EdgeList office[MAX_EDGES];
void build_graph(int N, int h[N - 1][N], int v[N][N - 1], int d[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int vertex = i * N + j;
      office[vertex].size = 0;

      // 上方向の隣接マス
      if (i > 0 && h[i - 1][j] == 0) {
        office[vertex].edges[office[vertex].size++] =
            (Edge){(i - 1) * N + j, d[i - 1][j]};
      }

      // 下方向の隣接マス
      if (i < N - 1 && h[i][j] == 0) {
        office[vertex].edges[office[vertex].size++] =
            (Edge){(i + 1) * N + j, d[i + 1][j]};
      }

      // 左方向の隣接マス
      if (j > 0 && v[i][j - 1] == 0) {
        office[vertex].edges[office[vertex].size++] =
            (Edge){i * N + (j - 1), d[i][j - 1]};
      }

      // 右方向の隣接マス
      if (j < N - 1 && v[i][j] == 0) {
        office[vertex].edges[office[vertex].size++] =
            (Edge){i * N + (j + 1), d[i][j + 1]};
      }
    }
  }
}

void dfs_office(int vertex, int N) {
  visited[vertex] = 1;
  int x = vertex / N;
  int y = vertex % N;

  for (int i = 0; i < office[vertex].size; i++) {
    Edge nextEdge = office[vertex].edges[i];
    int nextVertex = nextEdge.vertex;
    int nextX = nextVertex / N;
    int nextY = nextVertex % N;

    if (!visited[nextVertex]) {
      // 移動方向を判断して出力
      // ...

      dfs(nextVertex, N);

      // 逆方向を出力（DFSから戻る際）
      // ...
    }
  }
}

void dfs(int vertex, int N) {
  int x = vertex / N; // 現在の頂点の行
  int y = vertex % N; // 現在の頂点の列
  visited[vertex] = 1;

  // 未訪問かつ汚れやすい頂点を優先
  for (int i = 0; i < office[vertex].size; i++) {
    int maxDirtiness = -1;
    int nextVertex = -1;

    // 次に移動する頂点を選択
    for (int j = 0; j < office[vertex].size; j++) {
      int candidateVertex = office[vertex].edges[j].vertex;
      int candidateDirtiness = office[vertex].edges[j].dirtiness;

      if (!visited[candidateVertex] && candidateDirtiness > maxDirtiness) {
        nextVertex = candidateVertex;
        maxDirtiness = candidateDirtiness;
      }
    }

    if (nextVertex != -1) {
      int nextX = nextVertex / N;
      int nextY = nextVertex % N;

      // 現在の頂点の座標
      int currentX = vertex / N;
      int currentY = vertex % N;

      // 移動方向を判断して出力
      if (nextY == currentY + 1) {
        printf("R");
      } else if (nextY == currentY - 1) {
        printf("L");
      } else if (nextX == currentX - 1) {
        printf("U");
      } else if (nextX == currentX + 1) {
        printf("D");
      }

      dfs(nextVertex, N);

      // 逆方向を出力（DFSから戻る際）
      if (nextY == currentY + 1) {
        printf("L");
      } else if (nextY == currentY - 1) {
        printf("R");
      } else if (nextX == currentX - 1) {
        printf("D");
      } else if (nextX == currentX + 1) {
        printf("U");
      }
    }
  }
}

// 平均汚れを計算する関数
double calculate_average_dirtiness(int n, int dirtiness[][n], int L) {
  int i, j;
  double sum = 0.0;

  // 指定範囲内の汚れを合計する
  for (i = L; i < 2 * L; i++) {
    for (j = L; j < 2 * L; j++) {
      sum += dirtiness[i][j];
    }
  }
  return sum / (L * L);
}

int main() {
  int N;
  N = get_int();

  int h[N - 1][N]; // 水平方向の壁
  int v[N][N - 1]; // 垂直方向の壁
  int d[N][N];     // 各マスの汚れやすさ

  get_binary(N - 1, N, h);
  get_binary(N, N - 1, v);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      d[i][j] = get_int();
  }

  init(N);

  build_graph(N, h, v, d);

  dfs(0, N);

  printf("\n");

  return 0;
}
