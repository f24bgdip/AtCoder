#include <stdio.h>
#include <stdlib.h>

// INPUT
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

// DFS
#define MAX_N 40

int N;
char h[MAX_N][MAX_N]; // 水平方向の壁
char v[MAX_N][MAX_N]; // 垂直方向の壁
int d[MAX_N][MAX_N];  // 各マスの汚れやすさ
int visited[MAX_N][MAX_N];

void dfs(int i, int j) {
  visited[i][j] = 1;
  int DIJ[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  char DIR[4] = {'R', 'D', 'L', 'U'};

  for (int dir = 0; dir < 4; dir++) {
    int di = DIJ[dir][0];
    int dj = DIJ[dir][1];
    int i2 = i + di;
    int j2 = j + dj;

    if (0 <= i2 && i2 < N && 0 <= j2 && j2 < N && !visited[i2][j2]) {
      if ((di == 0 && v[i][j] == '0') || (dj == 0 && h[i][j] == '0')) {
        printf("%c", DIR[dir]);
        dfs(i2, j2);
        printf("%c", DIR[(dir + 2) % 4]);
      }
    }
  }
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

  // 訪問状況の初期化
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      visited[i][j] = 0;
    }
  }

  // 探索の開始
  dfs(0, N);
  printf("\n");

  return 0;
}
