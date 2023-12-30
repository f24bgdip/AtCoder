// BFS algorithm in C
// https://www.programiz.com/dsa/graph-bfs

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

typedef struct {
  int x, y;
} POINT;

struct queue {
  POINT items[SIZE];
  int front;
  int rear;
};

struct queue *createQueue();
void enqueue(struct queue *q, POINT);
POINT dequeue(struct queue *q);
void display(struct queue *q);
int isEmpty(struct queue *q);
void printQueue(struct queue *q);
void freeQueue(struct queue *q);

// BFS algorithm
void bfs(int R, int C, char maze[R][C + 1], POINT start, POINT goal) {
  int visited[R][C];
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      visited[i][j] = -1;

  struct queue *q = createQueue();
  enqueue(q, start);
  visited[start.x][start.y] = 0;

  while (!isEmpty(q)) {
    // printQueue(q);

    POINT current = dequeue(q);
    // printf("Visited %d %d\n", current.x, current.y);
    if (current.x == goal.x && current.y == goal.y) {
      // ゴール時の処理
      printf("%d\n", visited[current.x][current.y]);
      break;
    }

    // 上下左右の隣接セルを探索
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
      int nx = current.x + dx[i];
      int ny = current.y + dy[i];
      if (nx >= 0 && nx < R && ny >= 0 && ny < C && maze[nx][ny] == '.' &&
          visited[nx][ny] == -1) {
        visited[nx][ny] = visited[current.x][current.y] + 1;
        enqueue(q, (POINT){nx, ny});
      }
    }
  }
  freeQueue(q);
}

// Create a queue
struct queue *createQueue() {
  struct queue *q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue *q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue *q, POINT value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
POINT dequeue(struct queue *q) {
  POINT item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = (POINT){-1, -1};
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      // printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue *q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d %d\n", q->items[i].x, q->items[i].y);
    }
  }
}

void freeQueue(struct queue *q) { free(q); }

int main() {
  int R, C;
  if (scanf("%d %d", &R, &C) != 2)
    return -1;
  POINT start;
  if (scanf("%d %d", &start.x, &start.y) != 2)
    return -1;
  start.x--, start.y--;
  POINT goal;
  if (scanf("%d %d", &goal.x, &goal.y) != 2)
    return -1;
  goal.x--, goal.y--;
  char maze[R][C + 1];
  for (int i = 0; i < R; i++) {
    if (scanf("%s", &maze[i][0]) != 1)
      return -1;
  }

  bfs(R, C, maze, start, goal);

  return 0;
}