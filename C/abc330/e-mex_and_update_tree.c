#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200001
// #define MAX_N 9
#define MAX_TREE_SIZE 10

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

int node_count = 0;

Node *create(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

bool is_full() { return node_count >= MAX_TREE_SIZE; }

void insert(Node **node, int data) {
  if (*node == NULL) {
    if (!is_full()) {
      (*node) = create(data);
      node_count++;
    }
    return;
  }
  if (data < (*node)->data) {
    insert(&((*node)->left), data);
  } else if (data > (*node)->data) {
    insert(&((*node)->right), data);
  }
}

Node *find_min(Node *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

void delete(Node **node, int data) {
  if (data < (*node)->data) {
    delete (&((*node)->left), data);
  } else if (data > (*node)->data) {
    delete (&((*node)->right), data);
  } else {
    if ((*node)->left == NULL && (*node)->right == NULL) {
      // 葉ノードの削除
      free(*node);
      *node = NULL;
      node_count--;
    } else if ((*node)->left == NULL) {
      // 右の子のみを持つノードの削除
      Node *temp = *node;
      *node = (*node)->right;
      free(temp);
      node_count--;
    } else if ((*node)->right == NULL) {
      // 左の子のみを持つノードの削除
      Node *temp = *node;
      *node = (*node)->left;
      free(temp);
      node_count--;
    } else {
      // 二つの子を持つノードの削除
      Node *temp = find_min((*node)->right);
      (*node)->data = temp->data;
      delete (&((*node)->right), temp->data);
    }
  }
}

int getmin(Node *node) {
  Node *temp = find_min(node);
  return temp->data;
}

void free_node(Node *node) {
  if (node != NULL) {
    free_node(node->left);
    free_node(node->right);
    free(node);
  }
}

void build_tree(Node **root, int *freq) {
  int mex = 0;
  while (node_count < MAX_TREE_SIZE && mex < MAX_N) {
    if (!freq[mex]) {
      insert(root, mex);
      node_count++;
    }
    mex++;
  }
}

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);

  int A[N], freq[MAX_N] = {0};
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    if (A[i] < MAX_N) {
      freq[A[i]]++;
    }
  }

  // 二分木構築
  int mex = 0;
  Node *root = NULL;
  build_tree(&root, freq);

  mex = getmin(root);

  for (int q = 0; q < Q; q++) {
    int i, x;
    scanf("%d %d", &i, &x);

    i--;

    // 更新前
    if (A[i] < MAX_N) {
      freq[A[i]]--;
      // 空いたとき
      if (freq[A[i]] == 0 && mex > A[i]) {
        mex = A[i];
        insert(&root, mex);
      }
    }

    // 更新
    A[i] = x;

    // 更新後
    if (A[i] < MAX_N) {
      freq[A[i]]++;
      // 埋まったとき
      if (freq[A[i]] == 1)
        delete (&root, A[i]);

      // 空っぽのとき、二分木構築
      if (root == NULL)
        build_tree(&root, freq);

      if (mex == A[i])
        mex = getmin(root);
    }
    printf("%d\n", mex);
  }

  free_node(root);

  return 0;
}
