// About 0-1 BFS
// https://betrue12.hateblo.jp/entry/2018/12/08/000020

#include <stdio.h>
#include <stdlib.h>

#define INF 1 << 29
#define MAX_K 100000

// K の倍数の各桁の和としてありうる最小の値を格納する配列
// dist[i] は、ある整数が K の倍数であり、その桁和が i である場合に使用される
int dist[MAX_K];

// Deque (Double-Ended Queue) の構造体定義
typedef struct {
  int *data;    // Deque の要素を格納する動的配列
  int front;    // Deque の前面のインデックス
  int rear;     // Deque の後面のインデックス
  int size;     // Deque に格納されている要素の数
  int capacity; // Deque の最大容量
} Deque;

// Deque 構造体を作成し、初期化する関数
Deque *createDeque(int capacity) {
  Deque *deque = (Deque *)malloc(sizeof(Deque));
  deque->data = (int *)malloc(capacity * sizeof(int));
  // Deque の先頭
  deque->front = 0;
  // Deque が空であることを示す
  deque->rear = -1;
  // Deque の現在のサイズを 0 に初期化
  deque->size = 0;
  // Deque の容量を設定
  deque->capacity = capacity;
  return deque;
}

int isFull(Deque *deque) { return deque->size == deque->capacity; }

int isEmpty(Deque *deque) { return deque->size == 0; }

// Deque の先頭に要素を挿入する関数
void push_front(Deque *deque, int value) {
  // Deque が満杯の場合、挿入を行わない
  if (isFull(deque))
    return;
  // Deque の front をデクリメントして正しい位置に更新
  // モジュロ演算(capacity)を使って循環させる
  deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
  // 新しい要素をデータ配列の更新された front 位置に挿入
  deque->data[deque->front] = value;
  // Deque のサイズをインクリメント
  deque->size++;
}

// Deque の末尾に要素を挿入する関数
void push_rear(Deque *deque, int value) {
  // Deque が満杯の場合、挿入を行わない
  if (isFull(deque))
    return;
  // Deque の rear をインクリメントして正しい位置に更新
  // モジュロ演算(capacity)を使って循環させる
  deque->rear = (deque->rear + 1) % deque->capacity;
  // 新しい要素をデータ配列の更新された rear 位置に挿入
  deque->data[deque->rear] = value;
  // Deque のサイズをインクリメント
  deque->size++;
}

// Deque の前面から要素を削除する関数
int pup_front(Deque *deque) {
  // Deque が空の場合、-1 を返して終了
  if (isEmpty(deque))
    return -1;
  // 削除される要素の値を取得
  int value = deque->data[deque->front];
  // front インデックスをインクリメントして正しい位置に更新
  // モジュロ演算を使って循環させる
  deque->front = (deque->front + 1) % deque->capacity;
  // Deque のサイズをデクリメント
  deque->size--;
  // 削除された要素の値を返す
  return value;
}

void freeDeque(Deque *deque) {
  free(deque->data);
  free(deque);
}

int main() {
  int K;
  if (scanf("%d", &K) != 1)
    return -1;

  for (int i = 0; i < K; i++) {
    dist[i] = INF;
  }

  // K のサイズで Deque を作成
  Deque *deque = createDeque(K);

  // 1 の桁和を設定
  dist[1] = 1;

  // Deque の前面に 1 を追加
  push_front(deque, 1);

  // Deque が空になるまでループ
  while (!isEmpty(deque)) {
    // Deque の前面から要素を取り出し、v に格納
    int v = pup_front(deque);

    // コスト0
    // 「×10」を試す: v に 10 を掛けた数を K で割った余りを計算
    int v2 = (v * 10) % K;
    // もし現在の桁和よりも小さければ、更新し、Deque の前面に追加
    if (dist[v2] > dist[v]) {
      dist[v2] = dist[v];
      push_front(deque, v2);
    }

    // コスト1
    // 「+1」を試す: v に 1 を足した数を K で割った余りを計算
    v2 = (v + 1) % K;
    // もし現在の桁和よりも小さければ、更新し、Deque の後面に追加
    if (dist[v2] > dist[v] + 1) {
      dist[v2] = dist[v] + 1;
      push_rear(deque, v2);
    }
  }

  printf("%d\n", dist[0]);

  freeDeque(deque);
  return 0;
}
