// BFS algorithm in C
// https://www.programiz.com/dsa/graph-bfs

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

struct queue *createQueue();
void enqueue(struct queue *q, int);
int dequeue(struct queue *q);
void display(struct queue *q);
int isEmpty(struct queue *q);
void printQueue(struct queue *q);
void freeQueue(struct queue *q);

struct node {
  int vertex;
  struct node *next;
};

struct node *createNode(int);

struct Graph {
  int numVertices;
  struct node **adjLists;
  int *visited;
  int *distance;
};

// BFS algorithm
void bfs(struct Graph *graph, int startVertex) {
  struct queue *q = createQueue();

  graph->visited[startVertex] = 1;
  graph->distance[startVertex] = 0;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    // printQueue(q);
    int currentVertex = dequeue(q);
    // printf("Visited %d\n", currentVertex);

    struct node *temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        graph->distance[adjVertex] = graph->distance[currentVertex] + 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
  freeQueue(q);
}

// Creating a node
struct node *createNode(int v) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Creating a graph
struct Graph *createGraph(int vertices) {
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node *));
  graph->visited = malloc(vertices * sizeof(int));
  graph->distance = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
    graph->distance[i] = -1;
  }
  return graph;
}

// Add edge
void addEdge(struct Graph *graph, int src, int dest) {
  // Add edge from src to dest
  struct node *newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void freeGraph(struct Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    struct node *adjList = graph->adjLists[i];
    struct node *temp;

    while (adjList != NULL) {
      temp = adjList;
      adjList = adjList->next;
      free(temp);
    }
  }
  free(graph->adjLists);
  free(graph->visited);
  free(graph->distance);
  free(graph);
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
void enqueue(struct queue *q, int value) {
  if (q->rear == SIZE - 1) {
    // printf("\nQueue is Full!!");
  } else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue *q) {
  int item;
  if (isEmpty(q)) {
    // printf("Queue is empty");
    item = -1;
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
      printf("%d ", q->items[i]);
    }
  }
}

void freeQueue(struct queue *q) { free(q); }

int main() {
  int N, M;
  if (scanf("%d %d", &N, &M) != 2)
    return -1;

  struct Graph *graph = createGraph(N);

  for (int i = 0; i < M; i++) {
    int src, dest;
    if (scanf("%d %d", &src, &dest) != 2)
      return -1;
    addEdge(graph, src - 1, dest - 1);
  }

  bfs(graph, 0);

  // 全ての頂点が訪問されたかチェック
  for (int i = 0; i < N; i++) {
    if (graph->visited[i] == 0) {
      // printf("The graph is not connected.\n");
      printf("-1\n");
    } else {
      // printf("The graph is connected.\n");
      printf("%d\n", graph->distance[i]);
    }
  }

  // メモリ解放
  freeGraph(graph);

  return 0;
}