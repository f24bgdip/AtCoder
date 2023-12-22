#include <stdio.h>
#include <stdlib.h>

// 赤黒木
// ノードの色を表す列挙型
typedef enum { RED, BLACK } Color;

// 赤黒木のノードを表す構造体
typedef struct RBNode {
  int key;
  struct RBNode *parent;
  struct RBNode *child[2];
  Color color;
} RBNode;

#define NIL NULL
#define LEFT 0
#define RIGHT 1
#define left child[LEFT]
#define right child[RIGHT]

typedef struct RBTree {
  RBNode *root;
} RBTree;

// ルートでない非NILの RBNode* N の子方向（∈ { LEFT, RIGHT }）を取得する
#define childDir(N) (N == (N->parent)->right ? RIGHT : LEFT)

// 新しいノードを作成する関数
RBNode *create_rbnode(int key) {
  RBNode *new = malloc(sizeof(RBNode));
  if (new) {
    new->key = key;
    new->color = RED;
    new->parent = NULL;
    new->left = new->right = NIL;
  }
  return new;
}

RBNode *search_rbtree(RBTree *T, int key) {
  RBNode *current = T->root;
  while (current != NULL && current->key != key) {
    if (key < current->key)
      current = current->left;
    else
      current = current->right;
  }
  return current; // キーに一致するノードを返すか、見つからない場合はNULLを返す
}

// 赤黒木に新しいノードを挿入し、親ノードを設定する関数
// TはNULLでないこと
RBNode *find_parent(RBTree *T, int key) {
  RBNode *parent = NULL;

  // 親を探索し、挿入する向きを調べる
  RBNode *current = T->root;
  while (current != NULL) {
    parent = current;
    if (key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return parent;
}

// 赤黒木
// 部分木の根 (Tの根であってもよい)
// dir ∈ { LEFT, RIGHT }
RBNode *rotate_dir_root(RBTree *T, RBNode *P, int dir) {
  RBNode *G = P->parent;         // Grandparent Node
  RBNode *S = P->child[1 - dir]; // Sibling node
  RBNode *C = S->child[dir];     // Child of the sibling

  // 更新 P の子を S の子に置き換える
  P->child[1 - dir] = C;
  if (C != NULL)
    C->parent = P;

  // 更新 S の子を P に置き換える
  S->child[dir] = P;
  P->parent = S;

  // 更新 S を新しい親に設定
  S->parent = G;
  if (G != NULL)
    G->child[P == G->child[RIGHT] ? RIGHT : LEFT] = S;
  else
    T->root = S;

  return S; // 部分木の新しい根
}

// 方向に応じて回転するヘルパー関数
#define rotate_dir(N, dir) rotate_dir_root(T, N, dir)
#define rotate_left(N) rotate_dir_root(T, N, LEFT)
#define rotate_right(N) rotate_dir_root(T, N, RIGHT)

// 赤黒木にノードを挿入する関数
void insert_rbnode(RBTree *T, RBNode *N) {
  // 赤黒木が空の場合、新しいノードがツリーの根になる
  if (T->root == NULL) {
    T->root = N;
    return; // 挿入完了
  }

  // 親ノードの設定
  N->parent = find_parent(T, N->key);
  int dir = childDir(N); // ノードPが位置するGの側（右か左か）
  N->parent->child[dir] = N; // NをPのdir側の子として挿入する

  // 赤黒木の性質を修復する処理
  RBNode *G = N->parent->parent; // 祖父ノード
  RBNode *P = N->parent;         // 親ノード
  RBNode *U;                     // おじノード
  do {
    if (P->color == BLACK) {
      // Case_I1 (Pは黒):
      return; // 挿入完了
    }
    // ここからPは赤
    if ((G = P->parent) == NULL)
      goto Case_I4; // Pは赤かつ根

    // else: Pは赤 そして G!=NULL.
    int dir = childDir(P); // ノードPが位置するGの側（右か左か）
    U = G->child[1 - dir]; // おじ
    if (U == NIL || U->color == BLACK) // Uが黒とみなされると
      goto Case_I56;                   // Pは赤 && Uは黒
                                       // Case_I2 (PとUが赤):
    P->color = BLACK;
    U->color = BLACK;
    G->color = RED;
    N = G; // 新しいカレントノード
    // 1段階上の黒を反復
    //   (= 2の木レベル)
  } while ((P = N->parent) != NULL);
  // (do while)ループの終了

  // (do while)ループを抜ける(Case_I2から抜け出した後)。
  // Case_I3: Nは根であり、赤。
  return; // 挿入完了

Case_I4: // Pは根かつ赤:
  P->color = BLACK;
  return; // 挿入完了

Case_I56:                       // Pは赤 && Uは黒:
  if (N == P->child[1 - dir]) { // Case_I5 (Pは赤 && Uは黒 && NはGの内側の孫):
    rotate_dir(P, dir);         // Pは根にはならない
    N = P;                      // 新しいカレントノード
    P = G->child[dir];          // Nの新しい親
    // Case_I6に該当する
  }

  // Case_I6 (Pは赤 && Uは黒 && NはGの外側の孫):
  rotate_dir_root(T, G, 1 - dir); // Gは根である可能性がある
  P->color = BLACK;
  G->color = RED;

  return; // 挿入完了
}

void delete_node(RBTree *T, RBNode *N) {
  RBNode *P = N->parent;  // -> Nの親ノード
  RBNode *S;              // -> Nの兄弟ノード
  RBNode *C;              // -> 近いおい
  RBNode *D;              // -> 遠いおい
  RBNode *original_N = N; // 解放用
  int dir;                // Nの位置するPの側 (∈ { LEFT, RIGHT })

  // P != NULL, Nは根ではないので。
  dir = childDir(N); // ノードNが位置する親Pの側（LEFT か RIGHT）
  // 親PのNをNILに置き換える:
  P->child[dir] = NIL;
  goto Start_D; // ループに移動する

  // (do while)-ループの開始:
  do {
    dir = childDir(N); // ノードNの位置する親Pの側
  Start_D:
    S = P->child[1 - dir]; // Nの兄弟 (黒高さ >= 1)
    D = S->child[1 - dir]; // 遠いおい
    C = S->child[dir];     // 近いおい
    if (S->color == RED)
      goto Case_D3; // Sが赤 ===> P+C+Dが黒
    // S is black:
    if (D != NIL && D->color == RED) // 黒でないとみなす
      goto Case_D6;                  // Dが赤 && Sが黒
    if (C != NIL && C->color == RED) // 黒でないとみなす
      goto Case_D5;                  // Cが赤 && S+Dが黒
    // ここでは、両方のおい == NIL (最初の反復) または黒 (上位の反復).
    if (P->color == RED)
      goto Case_D4; // Pが赤 && C+S+Dが黒

    // Case_D1 (P+C+S+Dは黒):
    S->color = RED;

    N = P; // 新しいカレントノード (根かもしれない)
    // 1黒レベル(1木レベル)を上げながら反復する
  } while ((P = N->parent) != NULL);
  // (do while)-ループの終了

  // Case_D2 (P == NULL):
  free(original_N);
  return; // 削除完了

Case_D3:                      // Sは赤 && P+C+Dは黒:
  rotate_dir_root(T, P, dir); // Pは根かもしれない
  P->color = RED;
  S->color = BLACK;
  S = C; // != NIL
  // ここで: Pは赤 && Sは黒
  D = S->child[1 - dir]; // 遠いおい
  if (D != NIL && D->color == RED)
    goto Case_D6;    // Dは赤 && Sは黒
  C = S->child[dir]; // 近いおい
  if (C != NIL && C->color == RED)
    goto Case_D5; // Cは赤 && S+Dは黒
  // それ以外のC+Dは黒とみなす。
  // Case_D4に該当する。

Case_D4: // Pは赤 && S+C+Dは黒:
  S->color = RED;
  P->color = BLACK;
  free(original_N);
  return; // 削除完了

Case_D5:                  // C red && S+D black:
  rotate_dir(S, 1 - dir); // S is never the root
  S->color = RED;
  C->color = BLACK;
  D = S;
  S = C;
  // now: D red && S black
  // fall through to Case_D6

Case_D6:                      // Dは赤 && Sは黒:
  rotate_dir_root(T, P, dir); // Pは根かもしれない
  S->color = P->color;
  P->color = BLACK;
  D->color = BLACK;
  free(original_N);
  return; // 削除終了
}

void free_rbtree(RBNode *N) {
  if (N != NULL && N != NIL) {
    free_rbtree(N->left);
    free_rbtree(N->right);
    free(N);
  }
}

// 赤黒木全体を解放する関数
void free_entire_rbtree(RBTree *T) { free_rbtree(T->root); }

int main() {
  // RBTree root
  RBTree T;
  T.root = NULL;

  // テストデータで赤黒木に挿入
  insert_rbnode(&T, create_rbnode(10));
  insert_rbnode(&T, create_rbnode(20));
  insert_rbnode(&T, create_rbnode(30));

  // 赤黒木の状態を確認するためのコード（省略）

  free_entire_rbtree(&T);

  return 0;
}