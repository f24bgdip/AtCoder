#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *adjList[MAX_N]; // 隣接リスト

// 新しいノードを作成する関数
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// 無向エッジを追加する関数
void addEdge(int src, int dest) {
  // ソースから目的地へのエッジ
  Node *newNode = createNode(dest);
  newNode->next = adjList[src];
  adjList[src] = newNode;

  // 目的地からソースへのエッジ（無向のため）
  newNode = createNode(src);
  newNode->next = adjList[dest];
  adjList[dest] = newNode;
}

// 無向木を表示する関数
void printGraph(int N) {
  for (int v = 0; v < N; v++) {
    Node *temp = adjList[v];
    printf("Adjacency list of vertex %d\n head ", v);
    while (temp) {
      printf("-> %d", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  // 隣接リストの初期化
  for (int i = 0; i < N; i++) {
    adjList[i] = NULL;
  }

  // エッジを追加
  for (int i = 1; i < N; i++) {
    int u, v;
    if (scanf("%d %d", &u, &v) != 2)
      return -1;
    addEdge(u, v);
  }

  // 無向木を表示
  printGraph(N);

  return 0;
}
