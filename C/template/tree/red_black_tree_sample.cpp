// 基本の型定義:

enum color_t { BLACK, RED };

struct RBnode {     // 赤黒木のノード
  RBnode *parent;   // == NULL (木のルートの時)
  RBnode *child[2]; // == NIL (子が空の時)
                    // Index is:
                    //   LEFT  := 0, if (key < parent->key)
                    //   RIGHT := 1, if (key > parent->key)
  enum color_t color;
  int key;
};

#define NIL NULL // ヌルポインタまたは番兵ノードへのポインタ
#define LEFT 0
#define RIGHT 1
#define left child[LEFT]
#define right child[RIGHT]

struct RBtree { // 赤黒木
  RBnode *root; // == NIL (木が空の時)
};

// ルートでない非NILの RBnode* N の子方向（∈ { LEFT, RIGHT }）を取得する
#define childDir(N) (N == (N->parent)->right ? RIGHT : LEFT)

RBnode *RotateDirRoot(RBtree *T, // 赤黒木
                      RBnode *P, // 部分木の根 (Tの根であってもよい)
                      int dir) { // dir ∈ { LEFT, RIGHT }
  RBnode *G = P->parent;
  RBnode *S = P->child[1 - dir];
  RBnode *C;
  assert(S != NIL); // 真のノードへのポインターを要求する
  C = S->child[dir];
  P->child[1 - dir] = C;
  if (C != NIL)
    C->parent = P;
  S->child[dir] = P;
  P->parent = S;
  S->parent = G;
  if (G != NULL)
    G->child[P == G->right ? RIGHT : LEFT] = S;
  else
    T->root = S;
  return S; // 部分木の新しい根
}

#define RotateDir(N, dir) RotateDirRoot(T, N, dir)
#define RotateLeft(N) RotateDirRoot(T, N, LEFT)
#define RotateRight(N) RotateDirRoot(T, N, RIGHT)

void RBinsert1(RBtree *T,        // -> 赤黒木
               struct RBnode *N, // -> 挿入するノード
               struct RBnode *P, // -> Nの親ノード（NULLでも可）
               byte dir) // Nを挿入するPの側（LEFTまたはRIGHT）
{
  struct RBnode *G; // -> Pの親ノード
  struct RBnode *U; // -> Nのおじ

  N->color = RED;
  N->left = NIL;
  N->right = NIL;
  N->parent = P;
  if (P == NULL) { // 親がない場合
    T->root = N;   // Nが赤黒木Tの新しい根とし、
    return;        // 挿入完了
  }

  P->child[dir] = N; // NをPのdir側の子として挿入する
  // (do while)ループを開始する
  do {
    if (P->color == BLACK) {
      // Case_I1 (Pは黒):
      return; // 挿入完了
    }
    // ここからPは赤
    if ((G = P->parent) == NULL)
      goto Case_I4; // Pは赤かつ根
    // else: Pは赤 そして G!=NULL.
    dir = childDir(P);     // ノードPが位置するGの側（右か左か）
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
    RotateDir(P, dir);          // Pは根にはならない
    N = P;                      // 新しいカレントノード
    P = G->child[dir];          // Nの新しい親
    // Case_I6に該当する
  }

  // Case_I6 (Pは赤 && Uは黒 && NはGの外側の孫):
  RotateDirRoot(T, G, 1 - dir); // Gは根である可能性がある
  P->color = BLACK;
  G->color = RED;
  return; // 挿入完了
} // RBinsert1の終了

void RBdelete2(RBtree *T,        // -> 赤黒木
               struct RBnode *N) // -> 削除対象ノード
{
  struct RBnode *P = N->parent; // -> Nの親ノード
  byte dir;                     // Nの位置するPの側 (∈ { LEFT, RIGHT })
  struct RBnode *S;             // -> Nの兄弟ノード
  struct RBnode *C;             // -> 近いおい
  struct RBnode *D;             // -> 遠いおい

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
  return; // 削除完了

Case_D3:                    // Sは赤 && P+C+Dは黒:
  RotateDirRoot(T, P, dir); // Pは根かもしれない
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
  return; // 削除完了

Case_D5:                 // C red && S+D black:
  RotateDir(S, 1 - dir); // S is never the root
  S->color = RED;
  C->color = BLACK;
  D = S;
  S = C;
  // now: D red && S black
  // fall through to Case_D6

Case_D6:                    // Dは赤 && Sは黒:
  RotateDirRoot(T, P, dir); // Pは根かもしれない
  S->color = P->color;
  P->color = BLACK;
  D->color = BLACK;
  return; // 削除終了
} // RBdelete2の終了
