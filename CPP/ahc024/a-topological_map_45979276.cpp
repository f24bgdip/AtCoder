#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int

const bitset<512> is_connected_pattern(
    "11111111110111011111101111010001110011111100110110001011000000011111111111"
    "01110110000000110100011100111111001101000000000000000111111111000000001000"
    "00000000000000000000000000000000000000000000111111111101110110000000110100"
    "01000000000000000000000000000000011111111111011101100000000000000011001111"
    "11001101100010110000000111111111110111010000000000000000110011111100110100"
    "00000000000001111111110000000010000000000000001100111100000000100010110000"
    "00011111111111011101100000001101000111001111110011011000101111011110");

// Xorshiftは、疑似乱数生成アルゴリズムです。
class Xorshift {
public:
  // コンストラクター: 乱数生成器をシード値で初期化します。
  // シード値は0でない必要があります（そうでないと全ての出力が0になるため）。
  Xorshift(uint32_t seed) : x(seed) { assert(seed); }

  // 0から指定された`end`（未満）までの範囲で乱数を生成します。
  uint32_t randrange(uint32_t end) {
    next();         // 内部状態を更新
    return x % end; // 生成された乱数を返します
  }

  // 指定された範囲`begin`から`end`（未満）までの間で乱数を生成します。
  uint32_t randrange(uint32_t begin, uint32_t end) {
    next();                           // 内部状態を更新
    return begin + x % (end - begin); // 範囲内の乱数を計算して返します
  }

  // 0から1までの間で一様分布する乱数を生成します。
  double uniform() {
    next(); // 内部状態を更新
    return static_cast<double>(x) /
           static_cast<double>(UINT32_MAX); // 正規化された乱数を返します
  }

private:
  // 乱数生成器の内部状態を更新するメソッド
  void next() {
    x ^= x << 13; // 左に13ビットシフトした値でXOR
    x ^= x >> 7;  // 右に7ビットシフトした値でXOR
    x ^= x << 17; // 左に17ビットシフトした値でXOR
  }

  uint32_t x; // 乱数生成器の内部状態
};

// IndexSetは、効率的な要素の追加、削除、確認を可能にするデータ構造です。
class IndexSet {
public:
  // コンストラクター: n要素のセットを作成します。
  IndexSet(int n) : n_(n), positions_(n, -1) {}

  // xをセットに追加します。xはセットの範囲内で未追加の要素である必要があります。
  void add(int x) {
    assert(0 <= x && x < n_);
    assert(!contains(x));
    positions_[x] = data_.size();
    data_.push_back(x);
  }

  // セットからxを削除します。xはセットに存在する要素である必要があります。
  void remove(int x) {
    assert(0 <= x && x < n_);
    assert(contains(x));
    int pos = positions_[x];
    int y = data_.back();
    data_[pos] = y;
    data_.pop_back();
    positions_[y] = pos;
    positions_[x] = -1;
  }

  // xがセットに含まれているかどうかを確認します。
  bool contains(int x) const {
    assert(0 <= x && x < n_);
    return positions_[x] != -1;
  }

  // セットからランダムな要素を選択して返します。
  int choice(Xorshift &engine) const {
    assert(!data_.empty());
    return data_[engine.randrange(data_.size())];
  }

  // セットに含まれる全要素を返します。
  vector<int> all_data() const { return data_; }

  // セットのサイズ（含まれる要素の数）を返します。
  int size() const { return data_.size(); }

  // セットを空にします。
  void clear() {
    for (int x : data_) {
      positions_[x] = -1;
    }
    data_.clear();
  }

private:
  int n_;            // セットの最大サイズ
  vector<int> data_; // セットに含まれる要素
  vector<int>
      positions_; // 各要素のセット内での位置（-1は含まれていないことを示す）
};

// Timerクラスは、時間を計測するためのユーティリティです。
class Timer {
public:
  // 計測を開始します。
  void begin() { start_time_ = chrono::system_clock::now(); }

  // 現在までの経過時間を秒単位で返します。
  double get_time() const {
    chrono::system_clock::time_point end_time = chrono::system_clock::now();
    double elapsed_time =
        chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time_)
            .count();
    elapsed_time *= 1e-9; // nanoseconds -> seconds
    return elapsed_time;
  }

  // 指定された時間制限内であるかどうかを返します。
  bool yet(double time_limit) const { return get_time() < time_limit; }

  // 時間制限に対する現在の進行度を返します。
  double progress(double time_limit) const { return get_time() / time_limit; }

private:
  // 計測開始時点の時刻を保持します。
  chrono::system_clock::time_point start_time_;
};

constexpr double time_limit = 1.98;
constexpr int n = 50;
constexpr int m = 100;
constexpr array<int, 4> dx = {0, -1, 0, 1};
constexpr array<int, 4> dy = {1, 0, -1, 0};
constexpr array<int, 4> di4 = {1, -(n + 2), -1, n + 2};
constexpr array<int, 9> di9 = {-(n + 2) - 1, -(n + 2), -(n + 2) + 1, -1, 0, 1,
                               (n + 2) - 1,  n + 2,    (n + 2) + 1};

// 与えられた座標がグリッド内にあるかどうかを判断します。
bool in_grid(int x, int y) {
  // xとyがグリッドの範囲内にあるかをチェックします。
  return 0 <= x && x < n + 2 && 0 <= y && y < n + 2;
}

// グリッドの各セルの隣接セルのリストを作成します。
vector<vector<int>> make_edges() {
  // 各セルの隣接セルを保持するベクター
  vector<vector<int>> edges((n + 2) * (n + 2));
  for (int x = 0; x < n + 2; ++x) {
    for (int y = 0; y < n + 2; ++y) {
      for (int d = 0; d < 4; ++d) { // 各方向に対して
        int xd = x + dx[d];         // 隣接セルのx座標
        int yd = y + dy[d];         // 隣接セルのy座標
        if (in_grid(xd, yd)) {
          // 隣接セルがグリッド内にある場合
          // 隣接リストに追加
          edges[(n + 2) * x + y].push_back((n + 2) * xd + yd);
        }
      }
    }
  }
  return edges;
}

// グローバル変数として隣接リストを保持します。
const vector<vector<int>> edges = make_edges();

// Input構造体は、グリッドの初期状態を入力または読み込むために使用されます。
struct Input {
  vector<int> c; // グリッドの色情報を保持するベクター

  // 標準入力からグリッドの状態を読み込みます。
  void input() {
    int _n, _m;
    cin >> _n >> _m;
    assert(_n == n && _m == m);

    c.resize((n + 2) * (n + 2), 0); // サイズを設定し、全て0で初期化
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= n; ++y) {
        cin >> c[(n + 2) * x + y]; // グリッドの各セルの色を読み込み
      }
    }
  }

  // ファイルからグリッドの状態を読み込みます。
  void input(const string &filename) {
    ifstream in(filename);
    assert(in);

    int _n, _m;
    in >> _n >> _m;
    assert(_n == n && _m == m);

    c.resize((n + 2) * (n + 2), 0); // サイズを設定し、全て0で初期化
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= n; ++y) {
        in >> c[(n + 2) * x + y]; // グリッドの各セルの色を読み込み
      }
    }
  }
};

constexpr int compression_period = 1000000;
constexpr int annealing_period = (1 << 12);
constexpr int hill_climbing_turns = 0.2 * annealing_period;

// Stateクラスは、グリッドの状態を表し、それを更新するためのメソッドを持っています。
class State {
public:
  // コンストラクタ: 初期状態と乱数生成器のシードを設定
  State(uint32_t seed, const vector<int> grid)
      : engine(seed + 1), grid(grid), used((n + 2) * (n + 2)), directions(di4) {
    init();
  }

  // グリッドの状態を更新するメソッド
  bool update(int turn) {
    // decide position
    // グリッド上の位置をランダムに選択
    const int pos1 = used.choice(engine);
    assert(can_paint(pos1));

    // 選択した位置の現在の色と新しい色を決定
    const int old_color1 = grid[pos1];
    const int new_color1 =
        is_connected(pos1, old_color1) ? choose_color(pos1) : old_color1;
    grid[pos1] = new_color1;

    // 新しい色に基づいて隣接するセルを決定
    int d2 = di4[engine.randrange(4)];
    if (new_color1 != old_color1) {
      for (int d : di4) {
        if (adjacents[(m + 1) * new_color1 + grid[pos1 + d]] == 0) {
          d2 = d;
          break;
        }
      }
    }
    const int pos2 = pos1 + d2;
    if (!can_paint(pos2)) {
      grid[pos1] = old_color1;
      return false;
    }
    const int old_color2 = grid[pos2];
    const int new_color2 =
        is_connected(pos2, old_color2) ? choose_color(pos2) : old_color2;
    grid[pos2] = new_color2;

    // 新しい色が古い色と同じでない場合、シミュレーテッドアニーリングを適用
    if (new_color1 == old_color1 && new_color2 == old_color2) {
      grid[pos1] = old_color1;
      grid[pos2] = old_color2;
      return false;
    } else if (new_color1 == old_color1) {
      return update_one_square(turn, pos2, old_color2, new_color2);
    } else if (new_color2 == old_color2) {
      return update_one_square(turn, pos1, old_color1, new_color1);
    }
    // simulated annealing
    // 利得を計算し、利得が負の場合には変更を元に戻す
    const int profit = (new_color1 == 0) + (new_color2 == 0) -
                       (old_color1 == 0) - (old_color2 == 0);
    if (profit < 0 && turn % annealing_period < hill_climbing_turns) {
      grid[pos1] = old_color1;
      grid[pos2] = old_color2;
      return false;
    }
    // グリッドの隣接するセルの色を更新し、その結果を検証する
    if (!increment_adjacents(pos1, -1)) {
      // pos1の色を変更した後、隣接するセルとの矛盾が生じた場合、変更を元に戻す
      decrement_adjacents(pos1, -1);
      grid[pos1] = old_color1;
      grid[pos2] = old_color2;
      return false;
    }
    if (!increment_adjacents(pos2, pos1)) {
      // pos2の色を変更した後、隣接するセルとの矛盾が生じた場合、変更を元に戻す
      decrement_adjacents(pos1, -1);
      decrement_adjacents(pos2, pos1);
      grid[pos1] = old_color1;
      grid[pos2] = old_color2;
      return false;
    }

    grid[pos1] = old_color1;
    grid[pos2] = old_color2;

    // 隣接情報の減少処理を行い、それが無効である場合は変更を元に戻す
    if (!decrement_adjacents(pos1, -1)) {
      increment_adjacents(pos1, -1);
      grid[pos1] = new_color1;
      grid[pos2] = new_color2;
      decrement_adjacents(pos1, -1);
      decrement_adjacents(pos2, pos1);
      grid[pos1] = old_color1;
      grid[pos2] = old_color2;
      return false;
    }
    if (!decrement_adjacents(pos2, pos1)) {
      increment_adjacents(pos1, -1);
      increment_adjacents(pos2, pos1);
      grid[pos1] = new_color1;
      grid[pos2] = new_color2;
      decrement_adjacents(pos1, -1);
      decrement_adjacents(pos2, pos1);
      grid[pos1] = old_color1;
      grid[pos2] = old_color2;
      return false;
    }
    // update other menbers
    // 他のメンバ変数を更新する
    // pos1とpos2の位置に新しい色を設定
    grid[pos1] = new_color1;
    grid[pos2] = new_color2;

    // pos1のセルに関する更新
    if (old_color1 == 0 && new_color1 > 0) {
      // もし以前の色が0（未使用）で、新しい色が0より大きい（使用されている）場合、
      // この位置を「使用されているセルのリスト」に追加
      used.add(pos1);
    } else if (old_color1 > 0 && new_color1 == 0) {
      // 逆に、以前の色が0より大きく、新しい色が0（未使用）の場合、
      // この位置を「使用されているセルのリスト」から削除
      used.remove(pos1);
    }

    // pos2のセルに関する更新（pos1と同様の処理）
    if (old_color2 == 0 && new_color2 > 0) {
      used.add(pos2);
    } else if (old_color2 > 0 && new_color2 == 0) {
      used.remove(pos2);
    }

    // 利得を計算し、全体のスコアに加算
    zeros += profit;
    return true;
  }

  // グリッドの現在の状態を標準出力に表示するメソッド
  void print() const {
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= n; ++y) {
        // グリッドの各セルの値を出力（行の最後では改行を挿入）
        cout << grid[(n + 2) * x + y] << (y == n ? "\n" : " ");
      }
    }
  }

  // 現在のスコアを計算するメソッド
  int score() const {
    // ゼロ（未使用）のセルの数に1を加えたものがスコア
    return zeros + 1;
  }

  // Stateオブジェクトの初期化を行うメソッド
private:
  void init() {
    // 隣接するセル間の関係を表すadjacentsベクターを初期化
    adjacents = vector<int>((m + 1) * (m + 1), 0);
    for (int i = 0; i < (n + 2) * (n + 2); ++i) {
      for (int j : edges[i]) {
        // グリッド上の各セルとその隣接セルの間の関係をカウント
        ++adjacents[(m + 1) * grid[i] + grid[j]];
      }
    }
    // 各色の自己ループ（自分自身との関係）をカウント
    for (int color = 0; color <= m; ++color) {
      ++adjacents[(m + 1) * color + color];
    }

    // 使用されているセルの集合を初期化
    used.clear();
    for (int i = 0; i < (n + 2) * (n + 2); ++i) {
      if (grid[i]) {
        // 使用されているセルを追加
        used.add(i);
      }
    }

    // ゼロ（未使用）のセルの数をカウント
    zeros = 0;
    for (int x = 1; x <= n; ++x) {
      for (int y = 1; y <= n; ++y) {
        if (grid[(n + 2) * x + y] == 0) {
          ++zeros;
        }
      }
    }
  }

  // 指定された位置がペイント可能かどうかを判断するメソッド
  bool can_paint(int i) const {
    // グリッドの座標を計算
    int x = i % (n + 2);
    int y = i / (n + 2);
    // 座標がグリッドの範囲内にあるかどうかをチェック
    return 1 <= x && x <= n && 1 <= y && y <= n;
  }

  // 指定された位置に塗るべき色を選択するメソッド
  int choose_color(int i) {
    // 方向のリストをシャッフルして、ランダムな方向を選択
    swap(directions[0], directions[engine.randrange(4)]);
    // 選択した方向の中で、異なる色を持つ隣接セルを探す
    for (int d : directions) {
      if (grid[i] != grid[i + d]) {
        return grid[i + d];
      }
    }
    // 隣接するセルが同じ色しかない場合は、現在の色を返す
    return grid[i];
  }

  // 指定された位置と色が接続されているかどうかを判断するメソッド
  bool is_connected(int i, int color) const {
    // 3x3のグリッドでのパターンを表すビットセット
    bitset<9> pattern(0);
    // 3x3グリッド内で指定された色を持つセルを探す
    for (int d = 0; d < 9; ++d) {
      if (grid[i + di9[d]] == color) {
        pattern[d] = true;
      }
    }
    // 中心セルは常に空いているものとする
    pattern[4] = false;
    // パターンが接続されたパターンに該当するかどうかをチェック
    return is_connected_pattern[pattern.to_ulong()];
  }

  // 指定された位置の隣接するセルの色の関係を増加させるメソッド
  bool increment_adjacents(int i, int ignore_position) {
    // 現在のセルの色を取得
    int color = grid[i];
    bool ok = true;
    // 4方向に隣接するセルをチェック
    for (int d : di4) {
      if (i + d == ignore_position) {
        continue; // 指定された位置を無視
      }
      int c = grid[i + d];
      // 現在の色と隣接するセルの色の組み合わせが存在しなければfalseをセット
      if (adjacents[(m + 1) * color + c] == 0) {
        ok = false;
      }
      // 隣接するセルの色の組み合わせを増加
      ++adjacents[(m + 1) * color + c];
      ++adjacents[(m + 1) * c + color];
    }
    return ok;
  }

  // 指定された位置の隣接するセルの色の関係を減少させるメソッド
  bool decrement_adjacents(int i, int ignore_position) {
    // 現在のセルの色を取得
    int color = grid[i];
    bool ok = true;
    // 4方向に隣接するセルをチェック
    for (int d : di4) {
      if (i + d == ignore_position) {
        continue; // 指定された位置を無視
      }
      int c = grid[i + d];
      // 隣接するセルの色の組み合わせを減少
      --adjacents[(m + 1) * color + c];
      --adjacents[(m + 1) * c + color];
      // 隣接するセルの色の組み合わせが0になった場合はfalseをセット
      if (adjacents[(m + 1) * color + c] == 0) {
        ok = false;
      }
    }
    return ok;
  }

  // グリッド内の一つのセルを更新するメソッド
  bool update_one_square(int turn, int pos, int old_color, int new_color) {
    // シミュレーテッドアニーリングを使用して決定を行う
    const int profit =
        (new_color == 0) -
        (old_color == 0); // 利益を計算（新しい色が0なら+1、古い色が0なら-1）
    // もし利益が負であり、かつ現在のターンがアニーリング期間内のヒルクライミングターン内であれば更新をスキップ
    if (profit < 0 && turn % annealing_period < hill_climbing_turns) {
      grid[pos] = old_color;
      return false;
    }

    // 隣接するセルとの関係を更新する
    // 更新に失敗した場合は、以前の状態に戻す
    if (!increment_adjacents(pos, -1)) {
      decrement_adjacents(pos, -1);
      grid[pos] = old_color;
      return false;
    }
    // 元の色に戻して隣接関係を減少させる
    grid[pos] = old_color;
    if (!decrement_adjacents(pos, -1)) {
      // もし減少が失敗した場合は、再度隣接関係を増加させて、新しい色に設定し直す
      increment_adjacents(pos, -1);
      grid[pos] = new_color;
      decrement_adjacents(pos, -1);
      grid[pos] = old_color;
      return false;
    }

    // その他のメンバ変数を更新
    grid[pos] = new_color;

    // もし古い色が0で新しい色が0より大きい場合、使用済みセットに位置を追加
    if (old_color == 0 && new_color > 0) {
      used.add(pos);
    } else if (old_color > 0 && new_color == 0) {
      // もし古い色が0より大きく新しい色が0の場合、使用済みセットから位置を削除
      used.remove(pos);
    }
    zeros += profit; // 利益を加算
    return true;
  }

  // 以下はStateクラスのメンバ変数
  Xorshift engine;          // 乱数生成器
  vector<int> grid;         // グリッド
  vector<int> adjacents;    // 隣接情報
  IndexSet used;            // 使用済みセット
  int zeros;                // ゼロの数
  array<int, 4> directions; // 方向配列
};

constexpr int num_states = 2;
constexpr double patience_time = 0.5 * time_limit;

// 最適化問題を解くためのSolver構造体
struct Solver {
  Timer timer;       // タイマーを用いて実行時間を管理
  const Input input; // 入力データ
  State best;        // 現在の最良の状態を保持

  // コンストラクタ：入力データを受け取り、タイマーを開始
  Solver(const Input &input) : input(input), best(0, input.c) { timer.begin(); }

  // 問題を解くメインのメソッド
  void solve() {
    int turn = 0; // 現在のターン数
    // 設定された状態の数だけループ
    for (int i = 0; i < num_states; ++i) {
      // 各状態に割り当てられるローカルな時間制限を計算
      double local_time_limit = patience_time * (i + 1) / num_states;
      State state(i, input.c); // 新しい状態を初期化
      // ローカル時間制限内で状態を更新し続ける
      while (timer.yet(local_time_limit)) {
        state.update(turn); // 状態を更新
        // 現在の状態がこれまでの最良の状態より良い場合、最良の状態を更新
        if (state.score() > best.score()) {
          best = state;
        }
        turn++; // ターン数を増加
      }
    }
    // 全体の時間制限まで最良の状態を用いて更新を続ける
    State state = best;
    while (timer.yet(time_limit)) {
      state.update(turn);
      if (state.score() > best.score()) {
        best = state;
      }
      turn++;
    }
  }

  // 最良の状態を出力するメソッド
  void print() const { best.print(); }

  // 現在の最良のスコアを返すメソッド
  ll score() const { return best.score(); }
};

// 複数のテストケースについて解を評価する関数
void multi_test(int cases) {
  cerr << "cases: " << cases << endl; // テストケースの総数をログに出力

  double sum_scores = 0;  // スコアの合計
  double sum_time = 0.0;  // 実行時間の合計
  double max_time = 0.0;  // 最長の実行時間
  int max_time_seed = -1; // 最長実行時間のシード

  // 各テストケースに対してループ
  for (int seed = 0; seed < cases; ++seed) {
    // 入力ファイルの名前を生成
    string filename = "in/";
    filename += '0' + seed / 1000;
    filename += '0' + (seed / 100) % 10;
    filename += '0' + (seed / 10) % 10;
    filename += '0' + seed % 10;
    filename += ".txt";

    // 入力ファイルから問題を読み込み
    Input input;
    input.input(filename);

    // Solverオブジェクトを生成し、問題を解く
    Solver solver(input);
    solver.solve();

    // 解が見つかった後の経過時間を計測
    double elapsed_time = solver.timer.get_time();

    // 結果をログに出力
    cerr << filename << " " << solver.score() << " " << elapsed_time << " sec"
         << endl;
    sum_scores += solver.score(); // スコアを合計に加算

    // 最長実行時間を更新
    sum_time += elapsed_time;
    if (elapsed_time > max_time) {
      max_time = elapsed_time;
      max_time_seed = seed;
    }
  }
  cerr << "Average Score: " << sum_scores / max(1, cases) << endl;
  cerr << "Max Time: " << max_time << " sec (seed = " << max_time_seed << ")"
       << endl;
  cerr << "Average Time: " << sum_time / max(1, cases) << " sec" << endl;
}

int main() {
  Input input;
  input.input();

  Solver solver(input);
  solver.solve();
  solver.print();

#ifndef ONLINE_JUDGE
  cerr << "Score = " << solver.score() << ", " << solver.timer.get_time()
       << " sec" << endl;

  int cases = 100;
  multi_test(cases);
#endif

  return 0;
}
