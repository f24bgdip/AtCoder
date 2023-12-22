#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200001
#define MAX_TREE_SIZE 10

#include <stdio.h>
#include <stdlib.h>

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

void preorder(Node *node) {
  if (node != NULL) {
    printf("%d\n", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}

void inroder(Node *node) {
  if (node != NULL) {
    inroder(node->left);
    printf("%d ", node->data);
    inroder(node->right);
  }
}

void postorder(Node *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    printf("%d\n", node->data);
  }
}

int getmin(Node *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node->data;
}

void delete_node(Node **node, int data) {
  if (*node == NULL) {
    return;
  }
  if (data < (*node)->data) {
    delete_node(&((*node)->left), data);
  } else if (data > (*node)->data) {
    delete_node(&((*node)->right), data);
  } else {
    // ノードの削除と子ノードの再配置を行う
    // ...
  }
}

bool is_full(Node *node) { return node_count >= MAX_TREE_SIZE; }

void free(Node *node) {
  if (node != NULL) {
    free(node->left);
    free(node->right);
    free(node);
  }
}

int main() {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  int A[N], freq[MAX_N] = {0};
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    if (A[i] < MAX_N) {
      freq[A[i]]++;
    }
  }

  int mex = 0;
  Node *mex_root = NULL;
  while (is_empty(&mex_root)) {
    if (!freq[mex])
      insert(&mex_root, mex);
    mex++;
  }

  for (int q = 0; q < Q; q++) {
    int i, x;
    if (scanf("%d %d", &i, &x) != 2)
      return -1;

    i--;

    // 更新前A[i]
    if (A[i] < MAX_N) {
      freq[A[i]]--;
      if (freq[A[i]] == 0 && mex > A[i])
        mex = A[i];
    }

    // 更新
    A[i] = x;

    // 更新後A[i]
    if (A[i] < MAX_N) {
      freq[A[i]]++;

      // 現在の mex 候補を取り出す
      mex = getmin(&mex_root);

      // 二分木が空なら、再構築する
      if (freq[A[i]] > 0) {
        while (is_empty(&mex_root)) {
          if (!freq[mex])
            insert(&mex_root, mex);
          mex++;
        }
      }
    }

    printf("%d\n", mex);
  }

  free(root);

  return 0;
}
