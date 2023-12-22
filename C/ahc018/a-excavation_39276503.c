// Author: Psyho
// Twitter: https://twitter.com/fakepsyho

// TODO:
//  - choose path preference based on sum of distances to all houses
//  - post-optimize?
//  - gather digging stats via getting full map
//  - some things may be approximated by ML

// [FAIL] - choose vertex that would maximize closest distance
// [DONE] - take all houses into account every move
// [DONE] - switch to 10K tests later?
// [DONE] - add script that batch gens vis
// [DONE] - psytester: add an option to rerun test in case of fail
// [DONE] - check: why sometimes it doesn't detect that the test is done?
// [DONE] - when digging take surround into account (important when next to the
// water/scanned cell) [DONE] - try different shapes of grids [DONE] - support
// multiple starts [DONE] - refactor to make a global grid

// TEMPLATE

#pragma GCC optimize "Ofast,omit-frame-pointer,inline,unroll-all-loops"

#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;

#define INLINE inline __attribute__((always_inline))
#define NOINLINE __attribute__((noinline))

#define byte unsigned char
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a) FOR(i, 0, a)
#define ZERO(m) memset(m, 0, sizeof(m))
#define MINUS(m) memset(m, -1, sizeof(m))
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define S size()
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MP make_pair
#define X first
#define Y second
#define VC vector
#define PII pair<int, int>
#define PDD pair<double, double>
#define PIII pair<PII, int>
#define VB VC<byte>
#define VVB VC<VB>
#define VI VC<int>
#define VVI VC<VI>
#define VVVI VC<VVI>
#define VPII VC<PII>
#define VVPII VC<VPII>
#define VD VC<double>
#define VVD VC<VD>
#define VVVD VC<VVD>
#define VVVVD VC<VVVD>
#define VF VC<float>
#define VVF VC<VF>
#define VVVF VC<VVF>
#define VS VC<string>
#define VVS VC<VS>

// ペア<A, B>を出力するためのオーバーロードされた演算子ペアを"(A,
// B)"の形式で出力する
template <typename A, typename B>
ostream &operator<<(ostream &os, pair<A, B> p) {
  os << "(" << p.X << "," << p.Y << ")";
  return os;
}

// タプル<A, B, C>を出力するためのオーバーロードされた演算子タプルを"(A, B,
// C)"の形式で出力する
template <typename A, typename B, typename C>
ostream &operator<<(ostream &os, tuple<A, B, C> p) {
  os << "(" << get<0>(p) << "," << get<1>(p) << "," << get<2>(p) << ")";
  return os;
}

// ベクターを出力するためのオーバーロードされた演算子ベクターの要素を"{element1,
// element2, ...}"の形式で出力する
template <typename T> ostream &operator<<(ostream &os, VC<T> v) {
  os << "{";
  REP(i, v.S) {
    if (i)
      os << ", ";
    os << v[i];
  }
  os << "}";
  return os;
}

// セットを出力するためのオーバーロードされた演算子セットの要素を"{element1,
// element2, ...}"の形式で出力する
template <typename T> ostream &operator<<(ostream &os, set<T> s) {
  VS vs(ALL(s));
  return os << vs;
}

// 整数や浮動小数点数などの値を文字列に変換するための関数
template <typename T> string i2s(T x) {
  ostringstream o;
  o << x;
  return o.str();
}

// 与えられた文字列を特定の区切り文字で分割する関数分割された各部分はベクターとして返される
VS splt(string s, char c = ' ') {
  VS all;
  int p = 0, np;
  while (np = s.find(c, p), np >= 0) {
    if (np != p)
      all.PB(s.substr(p, np - p));
    p = np + 1;
  }
  if (p < s.S)
    all.PB(s.substr(p));
  return all;
}

// 引数の個数を決定するための内部マクロ：最大9個の引数をサポート
#define ARGS_SIZE_(a1, a2, a3, a4, a5, a6, a7, a8, a9, size, ...) size
#define ARGS_SIZE(...) ARGS_SIZE_(__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1)

// 引数が1つの場合のデバッグ出力用マクロ：変数名と値を出力
#define DB_1(x) #x << "=" << (x) <<

// 引数が2つ以上の場合のデバッグ出力用マクロ：最初の変数を出力し、残りの引数に対して再帰的に処理を行う
#define DB_2(x, ...) #x << "=" << (x) << ", " << DB_1(__VA_ARGS__)
#define DB_3(x, ...) #x << "=" << (x) << ", " << DB_2(__VA_ARGS__)
// ... 同様に、DB_4, DB_5, ..., DB_9まで定義されている

// 内部使用のためのマクロ：引数の数に応じて適切なDB_xマクロを呼び出す
#define DB__(size, ...) DB_##size(__VA_ARGS__)

// ARGS_SIZEマクロを使用して引数の数を決定し、それに基づいてDB__マクロを呼び出す
#define DB_(size, ...) DB__(size, __VA_ARGS__)

// ユーザーが使用するデバッグ出力マクロ：引数の数を自動的に判断し、適切なフォーマットで出力する
#define DB(...)                                                                \
  do {                                                                         \
    cerr << DB_(ARGS_SIZE(__VA_ARGS__), __VA_ARGS__) endl;                     \
  } while (0)

double get_time() {
  timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

// メルセンヌ・ツイスター疑似乱数生成器の実装
struct RNG {
  unsigned int MT[624]; // 状態配列
  int index;            // 現在のインデックス

  // コンストラクタ：シード値を受け取り、初期化を行う
  RNG(int seed = 1) { init(seed); }

  // シード値を用いて状態配列を初期化する
  void init(int seed = 1) {
    MT[0] = seed;
    FOR(i, 1, 624) MT[i] = (1812433253UL * (MT[i - 1] ^ (MT[i - 1] >> 30)) + i);
    index = 0;
  }

  // 乱数生成のための内部関数：状態配列を更新する
  void generate() {
    const unsigned int MULT[] = {0, 2567483615UL};
    REP(i, 227) {
      unsigned int y = (MT[i] & 0x8000000UL) + (MT[i + 1] & 0x7FFFFFFFUL);
      MT[i] = MT[i + 397] ^ (y >> 1);
      MT[i] ^= MULT[y & 1];
    }
    FOR(i, 227, 623) {
      unsigned int y = (MT[i] & 0x8000000UL) + (MT[i + 1] & 0x7FFFFFFFUL);
      MT[i] = MT[i - 227] ^ (y >> 1);
      MT[i] ^= MULT[y & 1];
    }
    unsigned int y = (MT[623] & 0x8000000UL) + (MT[0] & 0x7FFFFFFFUL);
    MT[623] = MT[623 - 227] ^ (y >> 1);
    MT[623] ^= MULT[y & 1];
  }

  // 乱数を生成し、返す
  unsigned int rand() {
    if (index == 0)
      generate();
    unsigned int y = MT[index];
    y ^= y >> 11;
    y ^= y << 7 & 2636928640UL;
    y ^= y << 15 & 4022730752UL;
    y ^= y >> 18;
    index = index == 623 ? 0 : index + 1;
    return y;
  }

  // 次の乱数を返す関数群
  INLINE int next() { return rand(); }
  INLINE int next(int x) { return rand() % x; }
  INLINE int next(int a, int b) { return a + (rand() % (b - a)); }
  INLINE double next_double() { return (rand() + 0.5) * (1.0 / 4294967296.0); }
  INLINE double next_double(double a, double b) {
    return a + next_double() * (b - a);
  }
};

static RNG rng; // RNGインスタンスのグローバル宣言

double start_time = get_time();

double elapsed() { return get_time() - start_time; }

// SOLUTION

// 定数の定義：グリッドの最大サイズ、水源の最大数、家の最大数を定義している
const int MAX_N = 200; // グリッドの最大サイズ（行または列の数）
const int MAX_W = 4;  // 水源の最大数
const int MAX_K = 10; // 家の最大数

// 2次元座標を1次元インデックスに変換する関数
int P1D(int r, int c) { return r * MAX_N + c; }

// 1次元インデックスを2次元座標に変換する関数
PII P2D(int p) { return PII(p / MAX_N, p % MAX_N); }

// グリッド内の隣接セルに移動するための方向配列
int dd[] = {-MAX_N, -1, +1, +MAX_N}; // 行の移動
int dr[] = {-1, +1, 0, 0};           // 列の移動
int dc[] = {0, 0, -1, +1};           // 列の移動

// グリッドのサイズ、水源と家の数、体力消費に関するパラメータ
int N, W, K, C; // グリッドのサイズ、水源の数、家の数、体力消費パラメータ
VPII VW, VH;    // 水源と家の座標を格納するベクター
int CLEV;       // 体力消費に関連するレベル

// グリッドの各セルに関する情報を格納する配列
int extracted[MAX_N][MAX_N]; // 掘削が完了したかどうかを示すフラグ
int good[MAX_N][MAX_N];   // 特定の条件を満たすセルを示すフラグ
int dig_lo[MAX_N][MAX_N]; // 掘削の最小強度の推定値
int dig_hi[MAX_N][MAX_N]; // 掘削の最大強度の推定値
int dig_last[MAX_N][MAX_N]; // 最後に行った掘削の強度

// 掘削の完了状態を追跡するフラグ
bool dig_done = false;

// 特定のセルで掘削を行う関数
// r: 掘削を行う行の位置
// c: 掘削を行う列の位置
// v: 掘削に使用するパワー
int dig(int r, int c, int v) {
  // すでに全ての家に水が届いている場合、掘削は不要
  if (dig_done) {
    extracted[r][c] = 1;
    return 2;
  }

  // 掘削命令を標準出力に出力し、ジャッジからの結果を受け取る
  cout << r << ' ' << c << ' ' << v << endl;
  int rv;
  cin >> rv;

  // 掘削に関連するデータを更新
  dig_last[r][c] = v;
  dig_lo[r][c] = dig_hi[r][c] + 1;
  dig_hi[r][c] += v;
  dig_lo[r][c] = min(dig_lo[r][c], 5000);
  dig_hi[r][c] = min(dig_hi[r][c], 5000);

  // 掘削結果に応じて、セルの状態を更新
  if (rv == 1 || rv == 2)
    extracted[r][c] = 1, dig_lo[r][c] = max(dig_lo[r][c], 10);

  // 掘削が完了した場合、デバッグ情報を出力
  if (rv == 2)
    DB(r, c, v);

  // 掘削が全て完了したかどうかを更新
  dig_done |= rv == 2;

  // ジャッジからの返り値を返す
  return rv;
}

// 掘削に使用する最適なパワーを計算する関数
// lo: 掘削の最小強度の推定値
// hi: 掘削の最大強度の推定値
int find_best_power(int lo, int hi) {
  int exp = (lo + hi) / 2; // 推定される岩盤の強度
  double bv = 1e9; // 最適な値を探すための変数（最初は大きな値で初期化）
  int power = 0; // 最適なパワー

  // 掘削時の無駄を調整するための係数
  const double V_WASTE_MUL[] = {1.2, 1.2, 1.6, 2.3, 3.2, 3.2, 4.3, 7.0};

  // 掘削パワーを1から1000まで試す
  FOR(p, 1, 1001) {
    double v_waste = p * 0.5; // 掘削パワーに基づく無駄の計算
    double c_waste = (exp + p - 1) / p * C; // 体力の消費に基づく無駄の計算

    // 総無駄の計算（パワーによる無駄と体力消費の無駄の合計）
    double av = v_waste * V_WASTE_MUL[CLEV] + c_waste;

    // より少ない無駄をもたらすパワーを見つけた場合、それを記録する
    if (av < bv) {
      bv = av;
      power = p;
    }
  }

  // 最適なパワーを返す
  return power;
}

// グリッド上の二点間の掘削コストを計算する関数
// r1, c1: 開始点の行と列の位置
// r2, c2: 終了点の行と列の位置
int edge_cost(int r1, int c1, int r2, int c2) {
  // 未知の掘削コストを体力消費レベルに応じて調整する配列
  const int UNKNOWN_DIG_COST[] = {135, 150, 150, 110, 170, 150, 180, 165};

  // 開始点と終了点のマンハッタン距離を計算
  int d = abs(r1 - r2) + abs(c1 - c2);
  if (d == 0)
    return 0; // 同じ点ならコストは0

  // 開始点と終了点の推定掘削コストを計算
  int v1 = extracted[r1][c1]
               ? (max(dig_lo[r1][c1], 10) + dig_hi[r1][c1]) / 2 + 6
               : UNKNOWN_DIG_COST[CLEV] +
                     (int)(dig_hi[r1][c1] * (105 - 4 * CLEV) /
                           (pow(log(dig_hi[r1][c1] + 1), 2.0) + 1));
  int v2 = extracted[r2][c2]
               ? (max(dig_lo[r2][c2], 10) + dig_hi[r2][c2]) / 2 + 6
               : UNKNOWN_DIG_COST[CLEV] +
                     (int)(dig_hi[r2][c2] * (105 - 4 * CLEV) /
                           (pow(log(dig_hi[r2][c2] + 1), 2.0) + 1));

  // 総掘削コストを計算
  // コストには、距離、体力消費、掘削コストが含まれる
  return (d - 1) * (1.0 * C + max(v1, v2) * 0.40 + min(v1, v2) * 0.60) +
         (extracted[r1][c1] ? 0 : C) + (extracted[r2][c2] ? 0 : C) +
         (r1 != r2 && c1 != c2 ? 0 : 80);
}

// グリッド内の各セルを表すためのマップとベクター
map<PII, int> vmap; // セルの座標からそのインデックスへのマッピング
VPII vv;            // セルの座標のリスト
VPII vs;            // 各セルに関連するスタートポイント
VVI ve; // エッジのリスト（各セルから接続されているセルへのインデックス）

// グリッド内の二つのセル間にエッジを追加する関数
// p1, p2: エッジを形成する二つのセルの座標
void add_edge(PII p1, PII p2) {
  // p1がまだvmapにない場合、新しいエントリを追加する
  if (vmap.count(p1) == 0) {
    vmap[p1] = vv.S;
    vv.PB(p1);
    ve.PB(VI());
    vs.PB(MP(-1, -1));
  }

  // p2がまだvmapにない場合、新しいエントリを追加する
  if (vmap.count(p2) == 0) {
    vmap[p2] = vv.S;
    vv.PB(p2);
    ve.PB(VI());
    vs.PB(MP(-1, -1));
  }

  // p1とp2のインデックスを取得
  int v1 = vmap[p1];
  int v2 = vmap[p2];

  // p1からp2へのエッジが既に存在するか確認
  bool exist = false;
  for (int v : ve[v1])
    exist |= v == v2;
  if (exist)
    return; // 既にエッジが存在する場合は何もしない

  // p1からp2、およびp2からp1へのエッジを追加
  ve[v1].PB(v2);
  ve[v2].PB(v1);
}

// グリッド上にグラフを構築する関数
// SCAN_DIST: グリッドをスキャンする際の距離
// targets: ターゲットとなるセルのリスト
void build_graph(int SCAN_DIST, VPII targets) {
  // スキャンのオフセットを計算
  int SCAN_OFFSET = 0;
  int scan_sum = 1;
  while (scan_sum + SCAN_DIST < 200)
    scan_sum += SCAN_DIST;
  SCAN_OFFSET = (200 - scan_sum) / 2;

  // グラフのデータ構造を初期化
  vmap.clear();
  vv.clear();
  vs.clear();
  ve.clear();

  // グリッド全体をスキャンし、エッジを追加
  for (int r = SCAN_OFFSET; r < 200; r += SCAN_DIST / 2)
    for (int c = SCAN_OFFSET; c < 200; c += SCAN_DIST / 2) {
      // 特定のパターンに従ってエッジを追加
      if (r % SCAN_DIST != c % SCAN_DIST)
        continue;
      if (r < N - SCAN_DIST)
        add_edge(MP(r, c), MP(r + SCAN_DIST, c));
      if (c < N - SCAN_DIST)
        add_edge(MP(r, c), MP(r, c + SCAN_DIST));
      if (r < N - SCAN_DIST / 2 && c > SCAN_DIST / 2)
        add_edge(MP(r, c), MP(r + SCAN_DIST / 2, c - SCAN_DIST / 2));
      if (r < N - SCAN_DIST / 2 && c < 200 - SCAN_DIST / 2)
        add_edge(MP(r, c), MP(r + SCAN_DIST / 2, c + SCAN_DIST / 2));

      // ターゲットに近いセルにエッジを追加
      for (PII &target : targets)
        if (abs(r - target.X) < SCAN_DIST && abs(c - target.Y) < SCAN_DIST &&
            abs(r - target.X) + abs(c - target.Y) > 0)
          add_edge(MP(r, c), target);

      // 最適なスタートポイントを見つける
      PII bstart = MP(-1, -1);
      int bv = 1e9;
      FOR(nr, max(0, r - SCAN_DIST + 1), min(N, r + SCAN_DIST))
      FOR(nc, max(0, c - SCAN_DIST + 1), min(N, c + SCAN_DIST)) {
        bool ok = false;
        ok |= good[nr][nc];
        for (PII &p : VW)
          ok |= p == MP(nr, nc);
        if (!ok)
          continue;
        int av = edge_cost(r, c, nr, nc);
        if (av < bv) {
          bv = av;
          bstart = MP(nr, nc);
        }
      }
      vs[vmap[MP(r, c)]] = bstart;
    }
}

// グリッド上の指定されたターゲットに対する最短経路を見つける関数
// targets: 最短経路を見つけたいターゲットのリスト
int last_find_path_cost = 0;
VPII find_path(VPII targets) {
  // 優先度付きキューを使用して最短経路を計算
  static priority_queue<PII, VPII, greater<PII>> pq;

  // 各ノードまでの最短距離と前のノードを記録する配列
  static int mdist[200 * 200];
  static int mprev[200 * 200];

  // 最短距離配列を初期化
  memset(mdist, 0x3F, sizeof(mdist[0]) * vv.S);
  while (!pq.empty())
    pq.pop();

  // グラフの各ノードに対して、スタートポイントからの距離を計算し、優先度付きキューに追加
  REP(i, vv.S) if (vs[i].X != -1) {
    int dst = edge_cost(vv[i].X, vv[i].Y, vs[i].X, vs[i].Y);
    pq.push(MP(dst, i));
    mprev[i] = -1;
    mdist[i] = dst;
  }

  // ターゲットに対する最短経路を探索
  PII final_v = MP(-1, -1);
  while (!pq.empty()) {
    PII p = pq.top();
    pq.pop();
    int dst = p.X;
    int cur = p.Y;

    // すでにより短い経路が見つかっている場合、スキップ
    if (mdist[cur] < dst)
      continue;

    // ターゲットに到達した場合、経路とコストを記録
    for (PII &target : targets)
      if (cur == vmap[target]) {
        last_find_path_cost = dst;
        final_v = target;
      }
    if (final_v.X != -1)
      break;

    // 隣接するノードに対して、最短距離を更新
    for (int next : ve[cur]) {
      int ndst = dst + edge_cost(vv[cur].X, vv[cur].Y, vv[next].X, vv[next].Y);
      if (mdist[next] <= ndst)
        continue;
      mdist[next] = ndst;
      mprev[next] = cur;
      pq.push(MP(ndst, next));
    }
  }

  // 最短経路の終点から始点までを逆順に辿る
  int cur = vmap[final_v]; // 経路の終点のインデックスを取得
  VPII path;               // 最短経路を格納するリスト

  // 経路を逆順に辿りながら、各点をpathリストに追加する
  while (mprev[cur] != -1) {
    path.PB(vv[cur]); // 現在の点をリストに追加
    cur = mprev[cur]; // 前の点に移動
  }
  path.PB(vv[cur]); // スタートポイントもリストに追加
  path.PB(vs[cur]); // スタートポイントのスタート位置もリストに追加

  // 最短経路リストを正しい順序に反転させる
  reverse(ALL(path));

  // 最短経路のリストを返す
  return path;
}

int main(int argc, char **argv) {
  // C++の入出力を高速化するための設定
  ios_base::sync_with_stdio(false);

  // 問題からグリッドのサイズ、水源の数、家の数、体力消費パラメータを入力
  cin >> N >> W >> K >> C;
  cerr << "[DATA] N = " << N << endl;
  cerr << "[DATA] W = " << W << endl;
  cerr << "[DATA] K = " << K << endl;
  cerr << "[DATA] C = " << C << endl;

  // 水源と家の位置を入力
  VW = VPII(W); // 水源の位置を格納するベクター
  REP(i, W) cin >> VW[i].X >> VW[i].Y;
  VH = VPII(K); // 家の位置を格納するベクター
  REP(i, K) cin >> VH[i].X >> VH[i].Y;

  // 体力消費レベルを計算
  CLEV = 0;
  while ((1 << CLEV) < C)
    CLEV++;
  DB(CLEV); // デバッグ出力

  // 水源と家の位置に関するデバッグ出力
  DB(VW);
  DB(VH);

  // 掘削に関するパワーの計算
  double SCAN_POW = 1.07 + 0.065 * CLEV;
  double SCAND_POW = max(1.0, 0.85 + 0.085 * CLEV);
  const int GRID_SIZE = 18;

  // 家の位置での掘削を開始
  for (PII &p : VH) {
    int power = max(16, C); // 初期掘削パワー
    while (!extracted[p.X][p.Y]) {
      dig(p.X, p.Y, power); // 掘削実行
      // 掘削パワーを更新
      power = min((int)(power * SCAN_POW), 5000 - dig_hi[p.X][p.Y]);
    }
  }

  // 無限ループ：全ての家に水が届くまで続ける
  while (true) {
    // 全ての家に水が届いた場合、ループを抜ける
    if (dig_done)
      break;

    // 水がまだ届いていない家のリストを作成
    VPII houses_left;
    for (PII &house : VH) {
      if (!good[house.X][house.Y]) {
        houses_left.PB(house);
      }
    }

    // グリッド上にグラフを構築：現在水が届いていない家をターゲットとする
    build_graph(GRID_SIZE, houses_left);

    // 内部ループ：全ての家に水が届くまで続ける
    while (true) {
      // 現在のターゲットに対する最短経路を見つける
      VPII path = find_path(houses_left);

      double bv = -1e9; // 最適なターゲットを見つけるための変数
      PII target = MP(-1, -1); // 最適なターゲット

      // 現在の経路での最適な掘削ターゲットを決定する
      for (PII p : path) {
        if (!extracted[p.X][p.Y]) {
          double av = -dig_hi[p.X][p.Y];
          if (av >= bv) {
            bv = av;
            target = p;
          }
        }
      }

      // 掘削開始時のパワーを体力消費レベルに応じて設定する配列
      int SCAN_START[] = {16, 13, 20, 20, 23, 17, 15, 11};
      if (target.X == -1) {
        // 最適なターゲットが見つからなかった場合の処理
        // 現在の最短経路に基づいて、新しい経路（fpath）を構築する
        VPII fpath;
        fpath.PB(path[0]); // 最初のポイントを追加

        // pathに含まれる各ポイントに対して処理を行う
        for (PII next : path) {
          // 現在のポイントと次のポイントの間の行と列の差を計算
          int odiff_r = abs(fpath.back().X - next.X); // 行の差
          int odiff_c = abs(fpath.back().Y - next.Y); // 列の差

          // 方向転換のための累積和を計算する変数
          int sum_r = 0; // 行の方向転換の累積和
          int sum_c = 0; // 列の方向転換の累積和

          int orientation = 0; // 現在の方向

          // 経路上での方向転換を行いながら、最適な掘削ポイントを探す
          if (odiff_r && odiff_c && odiff_r + odiff_c >= 10) {
            PII p0; // 最適な掘削ポイントを一時保存する変数

            // 現在のポイントから次のポイントまでの経路を決定
            {
              PII p = fpath.back(); // 現在のポイント
              // 現在のポイントから次のポイントまでの距離が半分以上になるまで方向転換を行う
              while (abs(p.X - next.X) + abs(p.Y - next.Y) >
                     (odiff_r + odiff_c) / 2) {
                sum_r += odiff_r;
                sum_c += odiff_c;
                // 行の方向転換を行う条件を満たした場合、行を一つ進める
                if (sum_r >= 100) {
                  sum_r -= 100;
                  p.X += next.X > p.X ? 1 : -1;
                }
                // 列の方向転換を行う条件を満たした場合、列を一つ進める
                else if (sum_c >= 100) {
                  sum_c -= 100;
                  p.Y += next.Y > p.Y ? 1 : -1;
                }
              }
              // 経路上のポイント間の方向転換の処理を完了した後、次のステップを開始
              sum_r = 0;
              sum_c = 0;
              p0 = p; // 最適な掘削ポイントを保存

              // 現在の経路の次のポイントと前のポイントから新しいポイントを生成
              PII p1 = MP(
                  next.X,
                  fpath.back()
                      .Y); // 次のポイントのX座標と前のポイントのY座標を持つ新しいポイント
              PII p2 = MP(
                  fpath.back().X,
                  next.Y); // 前のポイントのX座標と次のポイントのY座標を持つ新しいポイント

              // 残りの家を更新し、新しいグラフを構築するための準備
              VPII xhouses_left = houses_left; // 現在の家のリストをコピー
              xhouses_left.erase(find(
                  ALL(xhouses_left),
                  path.back())); // 現在の経路の最後のポイントにある家をリストから削除

              // 新しいポイントを有効な掘削ポイントとしてマーク
              good[p1.X][p1.Y] = 1;

              // グラフを再構築：新しい家のリストを使用してグラフを更新
              build_graph(GRID_SIZE, houses_left);

              int val1 = 0; // 新しいグラフに基づく掘削コストの計算用変数
              // xhouses_leftに含まれる各家に対して最短経路を見つけ、それに基づいて掘削コストを計算
              for (PII &p : xhouses_left) {
                find_path(VPII{p});          // 最短経路を探索
                val1 += last_find_path_cost; // 計算されたコストを合計
              }
              good[p1.X][p1.Y] = 0; // p1を無効化

              // p2に関して同様のプロセスを実行
              good[p2.X][p2.Y] = 1;                // p2を有効化
              build_graph(GRID_SIZE, houses_left); // グラフを再構築

              int val2 = 0; // p2に基づく掘削コストの計算用変数
              for (PII &p : xhouses_left) {
                find_path(VPII{p});          // 最短経路を探索
                val2 += last_find_path_cost; // 計算されたコストを合計
              }
              good[p2.X][p2.Y] = 0; // p2を無効化

              // p0, p1, p2のいずれかがまだ掘削されていない場合
              // 繰り返し掘削を行う
              while (!extracted[p0.X][p0.Y] && !extracted[p1.X][p1.Y] &&
                     !extracted[p2.X][p2.Y]) {
                // val1とval2を比較し、より低いコストの経路を優先する
                if (val1 <= val2) {
                  // p1での掘削を試みる：掘削パワーは以前の掘削結果に基づいて調整される
                  dig(p1.X, p1.Y,
                      dig_last[p1.X][p1.Y]
                          ? min((int)(dig_last[p1.X][p1.Y] * SCAND_POW + .5),
                                40 * C)
                          : max(16, C) * SCAN_START[CLEV] / 16);
                  // p1での掘削が成功した場合、ループを抜ける
                  if (extracted[p1.X][p1.Y])
                    break;

                  // p2での掘削を試みる
                  dig(p2.X, p2.Y,
                      dig_last[p2.X][p2.Y]
                          ? min((int)(dig_last[p2.X][p2.Y] * SCAND_POW + .5),
                                40 * C)
                          : max(16, C) * SCAN_START[CLEV] / 16);
                  // p2での掘削が成功した場合、ループを抜ける
                  if (extracted[p2.X][p2.Y])
                    break;
                } else {
                  // val2がval1よりも小さい場合は、p2を優先して掘削を試みる
                  // 掘削のロジックはp1と同様
                  dig(p2.X, p2.Y,
                      dig_last[p2.X][p2.Y]
                          ? min((int)(dig_last[p2.X][p2.Y] * SCAND_POW + .5),
                                40 * C)
                          : max(16, C) * SCAN_START[CLEV] / 16);
                  // p2での掘削が成功した場合（つまり、そのセルの岩盤が破壊された場合）、ループを抜ける
                  if (extracted[p2.X][p2.Y])
                    break;

                  // p2での掘削がまだ完了していない場合、p1での掘削を試みる
                  dig(p1.X, p1.Y,
                      dig_last[p1.X][p1.Y]
                          ? min((int)(dig_last[p1.X][p1.Y] * SCAND_POW + .5),
                                40 * C)
                          : max(16, C) * SCAN_START[CLEV] / 16);
                  // p1での掘削が成功した場合、ループを抜ける
                  if (extracted[p1.X][p1.Y])
                    break;
                }
              }
              // p0での掘削を試みる掘削パワーは以前の掘削結果に基づいて調整される
              dig(p0.X, p0.Y,
                  dig_last[p0.X][p0.Y]
                      ? min((int)(dig_last[p0.X][p0.Y] * SCAND_POW + .5),
                            40 * C)
                      : max(16, C) * SCAN_START[CLEV] / 16);
              // p0での掘削が成功した場合（つまり、そのセルの岩盤が破壊された場合）、ループを抜ける
              if (extracted[p0.X][p0.Y])
                break;

              // 掘削の結果に基づいて次の掘削の方向性を決定する
              if (extracted[p0.X][p0.Y]) {
                // p0での掘削が成功した場合、orientationを0に設定
                orientation = 0;
              } else if (extracted[p1.X][p1.Y]) {
                // p1での掘削が成功した場合、orientationを1に設定
                orientation = 1;
              } else {
                // それ以外の場合（p2での掘削が成功した場合）、orientationを2に設定
                orientation = 2;
              }
            }

            // fpathの最後のポイントから次のポイント（next）まで経路を構築する
            while (fpath.back() != next) {
              PII p = fpath.back(); // 現在のポイント

              // orientationに基づいて次のポイントを決定する
              if (orientation == 0) {
                // 行と列の方向転換の累積和を計算
                while (sum_r < 100 && sum_c < 100) {
                  sum_r += odiff_r;
                  sum_c += odiff_c;
                }
                // 次のポイントをfpathに追加
                if (sum_r >= 100) {
                  fpath.PB(MP(p.X + (next.X > p.X ? 1 : -1), p.Y));
                  sum_r -= 100;
                } else {
                  fpath.PB(MP(p.X, p.Y + (next.Y > p.Y ? 1 : -1)));
                  sum_c -= 100;
                }
              } else if (orientation == 1) {
                // X軸方向のみまたはY軸方向のみの移動
                if (p.X != next.X) {
                  fpath.PB(MP(p.X + (next.X > p.X ? 1 : -1), p.Y));
                } else {
                  fpath.PB(MP(p.X, p.Y + (next.Y > p.Y ? 1 : -1)));
                }
              } else if (orientation == 2) {
                // Y軸方向のみまたはX軸方向のみの移動
                if (p.Y != next.Y) {
                  fpath.PB(MP(p.X, p.Y + (next.Y > p.Y ? 1 : -1)));
                } else {
                  fpath.PB(MP(p.X + (next.X > p.X ? 1 : -1), p.Y));
                }
              }
              // 新しいポイントを有効な掘削ポイントとしてマーク
              good[fpath.back().X][fpath.back().Y] = 1;
            }
          }
        }

        // 経路上の各ポイントで掘削を行う
        PII prev = MP(-1, -1); // 前の掘削ポイント
        for (PII &cur : fpath) {
          // 掘削に使用するパワーを決定
          int power = prev.X == -1 ? 2 * C + 30
                                   : find_best_power(dig_lo[prev.X][prev.Y],
                                                     dig_hi[prev.X][prev.Y]);
          // 前回の掘削深度を基にした調整
          int last_v = prev.X == -1 ? 0
                                    : (dig_lo[prev.X][prev.Y] * .45 +
                                       dig_hi[prev.X][prev.Y] * .55 + .5);
          int step = 0; // 現在の掘削ステップ数

          // 現在のポイントがまだ掘削されていない場合、掘削を実行
          while (!extracted[cur.X][cur.Y]) {
            step++;
            int cur_power = power; // 現在の掘削パワー

            // 前回の掘削結果に基づいて掘削パワーを調整
            const double LAST_V_MUL[] = {0.96,  0.96, 0.97, 0.985,
                                         1.025, 1.05, 1.09, 1.130};
            if (last_v && last_v > power) {
              if (step == 1) {
                cur_power = (int)(last_v * LAST_V_MUL[CLEV] + 0.5);
              } else if (step > 1) {
                cur_power = (int)(power * .45 + 0.5);
              }
            }
            // 掘削パワーの最小値を設定
            const int MIN_DIG[] = {0, 0, 0, 12, 13, 15, 19, 25};
            cur_power = max(MIN_DIG[CLEV], cur_power);
            // 掘削パワーの最大値を設定
            cur_power = min(cur_power, 5000 - dig_hi[cur.X][cur.Y]);
            // 掘削を実行
            int rv = dig(cur.X, cur.Y, cur_power);
          }

          // 次の掘削ポイントを設定
          prev = cur;
        }

        break;
      }

      // 掘削に使用するパワーを計算
      int p =
          // 前回の掘削で使用したパワーがある場合、それを基にパワーを調整
          dig_last[target.X][target.Y]
              ? min((int)(dig_last[target.X][target.Y] * SCAN_POW + .5), 40 * C)
              : max(16, C) * SCAN_START[CLEV] /
                    16; // そうでない場合は、標準の開始パワーを使用

      // 掘削パワーの最大値を5000から現在のポイントの最高掘削深度までに制限
      p = min(p, 5000 - dig_hi[target.X][target.Y]);

      // 計算されたパワーで指定されたターゲットで掘削を行う
      dig(target.X, target.Y, p);
    }
  }

  cerr << "[DATA] time = " << elapsed() * 1000 << endl;
  return 0;
}
