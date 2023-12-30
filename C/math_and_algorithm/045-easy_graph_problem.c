#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node *next;
};

struct node *createNode(int v);

struct Graph {
  int numVertices;
  int *visited;
  struct node **adjLists;
};

// Create a node
struct node *createNode(int v) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create graph
struct Graph *createGraph(int vertices) {
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node *));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

int countVertices(struct Graph *graph) {
  int count = 0;
  for (int i = 1; i <= graph->numVertices; i++) {
    int smallerNeighbors = 0;
    struct node *temp = graph->adjLists[i - 1];

    while (temp != NULL) {
      if (temp->vertex < i) {
        smallerNeighbors++;
      }
      temp = temp->next;
    }

    if (smallerNeighbors == 1) {
      count++;
    }
  }
  return count;
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

// Print the graph
void printGraph(struct Graph *graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node *temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
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
  free(graph);
}

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

  int result = countVertices(graph);
  printf("%d\n", result);

  freeGraph(graph);

  return 0;
}
