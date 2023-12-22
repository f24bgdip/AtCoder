#pragma GCC optimize("O3")
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = int;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
#define pb push_back
#define int int
#define double double
#define INF (ll)2e9
// Ctrl + Shift + B コンパイル
// Ctrl + C 中断
// ./m 実行

// inputs
int t = 100;
int h = 20;
int w = 20;
int i0;
vvl wall_d(21, vl(21));
vvl wall_r(21, vl(21));
int K;

// 焼きなまし法のテンプレート
// Set a constant for the time limit (in milliseconds)
constexpr int TIME_LIMIT = 1930;

// Record the start time using the system clock
auto start_time = std::chrono::system_clock::now();

// This will be used to hold the current time during the algorithm's execution
auto now_time = std::chrono::system_clock::now();

// Calculate the progress in the algorithm based on elapsed time.
// This is typically used to adjust the "temperature" in simulated annealing.
double progress =
    std::chrono::duration_cast<std::chrono::milliseconds>(now_time - start_time)
        .count();

// Set the starting and ending temperatures for the simulated annealing.
// These values are used to control the probability of accepting worse solutions
// as the algorithm progresses.
float start_temp = 0.99;
float end_temp = 0.0;

// A function to generate random numbers using XOR shift method.
// XOR shift is a type of pseudorandom number generator, which is known for its
// speed and quality of randomness.
unsigned int randxor() {
  static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
  unsigned int t;
  t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

// 使う予定のデータ類
vvl dist(20, vl(20));
vector<tuple<int, int, int>> distij; // ijをdistでソートしたい時つかう
vl dx = {-1, 1, 0, 0};
vl dy = {0, 0, -1, 1};
string direc = "UDLR";
vector<vector<vector<P>>> adjacent_cells(20, vector<vector<P>>(20));
vector<vector<P>> closer_cells(20, vector<P>(20));
vector<vector<vector<P>>> farther_cells(20, vector<vector<P>>(20));
vvl rangesd(101, vl(101));            // sd区間
vector<vvl> rangesd_p(101, vvl(101)); // sd区間 indexes
vector<vector<set<int>>> split(20, vector<set<int>>(20));
vector<vector<vector<P>>>
    configured_range(20, vector<vector<P>>(20, vector<P>(101)));
vector<vvl> pre_find(20, vvl(20, vl(101)));
vvl density(20, vl(20));
int score = 0;

vector<P> prob;

bool outside(int i, int j) {
  if (i < 0)
    return true;
  if (j < 0)
    return true;
  if (i >= h)
    return true;
  if (j >= w)
    return true;
  return false;
}

bool wallcheck(int i, int j, int k) {
  if (direc[k] == 'U')
    return wall_d[i - 1][j];
  if (direc[k] == 'D')
    return wall_d[i][j];
  if (direc[k] == 'L')
    return wall_r[i][j - 1];
  if (direc[k] == 'R')
    return wall_r[i][j];
  return true;
}

void get_adjacent_cell() {
  rep(i, h) {
    rep(j, w) {
      rep(k, 4) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (outside(ni, nj))
          continue;
        if (wallcheck(i, j, k))
          continue;
        adjacent_cells[i][j].emplace_back(ni, nj);
      }
    }
  }
}

vvl distance() {
  vvl distance(h, vl(w, INF));
  distance[i0][0] = 0;
  queue<P> que;
  que.emplace(i0, 0);
  while (que.size()) {
    auto [i, j] = que.front();
    que.pop();
    for (auto [ni, nj] : adjacent_cells[i][j]) {
      if (distance[ni][nj] != INF)
        continue;
      distance[ni][nj] = distance[i][j] + 1;
      que.emplace(ni, nj);
    }
  }
  return distance;
}

void get_closer_cell() {
  rep(i, h) {
    rep(j, w) {
      int closest = dist[i][j];
      for (auto [ni, nj] : adjacent_cells[i][j]) {
        if (dist[ni][nj] < closest) {
          closest = dist[ni][nj];
        }
      }
      for (auto [ni, nj] : adjacent_cells[i][j]) {
        if (dist[ni][nj] == closest) {
          closer_cells[i][j] = P(ni, nj);
          farther_cells[ni][nj].emplace_back(i, j);
          break;
        }
      }
    }
  }
}

void input() {
  cin >> t >> h >> w >> i0;
  rep(i, h - 1) {
    string s;
    cin >> s;
    rep(j, w) { wall_d[i][j] = s[j] - '0'; }
  }
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w - 1) { wall_r[i][j] = s[j] - '0'; }
  }
  cin >> K;
  rep(i, K) {
    int s, d;
    cin >> s >> d;
    rangesd[s][d]++;
    rangesd_p[s][d].push_back(i);
  }
  get_adjacent_cell();
  dist = distance();
  get_closer_cell();
}

void final_answer() {
  vector<tuple<int, int, int, int>> dsij;
  rep(i, 20) {
    rep(j, 20) {
      int pre = 0;
      for (auto x : split[i][j]) {
        if (x - (pre + 1) >= 1)
          dsij.emplace_back(x, pre + 1, i, j);
        pre = x;
      }
    }
  }
  vector<tuple<int, int, int, int>> kijs;
  int sc = 0;
  for (auto [d, s, i, j] : dsij) {
    for (int sb = s; sb < d; sb++) {
      if (rangesd_p[sb][d].size()) {
        int k = rangesd_p[sb][d].back();
        rangesd_p[sb][d].pop_back();
        kijs.emplace_back(k, i, j, s);
        sc += d - sb + 1;
        break;
      }
    }
  }
  cout << kijs.size() << endl;
  for (auto [k, i, j, s] : kijs) {
    cout << k + 1 << " " << i << " " << j << " " << s << endl;
  }
  cerr << "シミュレートのスコア : " << 1000000 * score / (40000) << endl;
  cerr << "実際に得られたスコア : " << 1000000 * sc / (40000) << endl;
}

// 高速スコア計算用の関数たち
void del(int &i, int &j, int &d) {
  auto [lef, rig] = configured_range[i][j][d];
  if (lef != 0) {
    rangesd[lef][rig]++;
    score -= rig - lef + 1;
    configured_range[i][j][d] = P(0, 0);
  }
}
void add(int &i, int &j, int &d, int pre = 0) {
  if (configured_range[i][j][d].first) {
    throw runtime_error("somtheing is wrong!");
  }
  if (pre == 0) {
    auto itr = split[i][j].lower_bound(d);
    if (itr != split[i][j].begin())
      pre = *prev(itr);
  }
  for (int sb = pre + 1; sb < d; sb++) {
    if (rangesd[sb][d]) {
      rangesd[sb][d]--;
      configured_range[i][j][d] = P(sb, d);
      score += d - sb + 1;
      break;
    }
  }
}

void splitadd(int &i, int &j, int &d) {
  int nxt = *split[i][j].upper_bound(d);
  int pre = pre_find[i][j][nxt];
  pre_find[i][j][d] = pre;
  add(i, j, d, pre_find[i][j][d]);
  del(i, j, nxt);
  pre_find[i][j][nxt] = d;
  add(i, j, nxt, pre_find[i][j][nxt]);
}
void splitdelete(int &i, int &j, int &d) {
  int nxt = *split[i][j].upper_bound(d);
  del(i, j, d);
  del(i, j, nxt);
  add(i, j, nxt);
  pre_find[i][j][nxt] = pre_find[i][j][d];
  pre_find[i][j][d] = 0;
}

// 操作タイプ、dポイント、操作座標のリスト
vector<tuple<int, int, vector<P>>> history;

void separate() {
  auto [si, sj] = prob[randxor() % prob.size()];
  int d = randxor() % 99 + 1; // 2~99
  queue<P> que;
  que.emplace(si, sj);
  vector<P> log;
  while (que.size()) {
    auto [i, j] = que.front();
    que.pop();
    if (split[i][j].count(d))
      break;
    split[i][j].insert(d);
    splitadd(i, j, d);
    log.emplace_back(i, j);
    if (i == i0 && j == 0)
      break;
    que.emplace(closer_cells[i][j]);
  }
  history.emplace_back(1, d, log);
}

// Function to perform a separate reverse random walk
void separate_reverse_randomwalk() {
  // Choose a random starting position (si, sj) on a 20x20 grid
  int si = randxor() % 20;
  int sj = randxor() % 20;

  // Repeat 20 times: if the current cell has only one split, choose a new
  // random cell
  rep(_, 20) {
    if (split[si][sj].size() == 1) {
      si = randxor() % 20;
      sj = randxor() % 20;
    } else
      break;
  }

  // If after the above loop, the cell still has only one split, exit the
  // function
  if (split[si][sj].size() == 1)
    return;

  vl dlist;
  // Collect all split identifiers in the current cell into dlist
  for (auto x : split[si][sj])
    dlist.push_back(x);

  int d = 100;

  // Try to find a split identifier from dlist other than 100, for 20 iterations
  rep(_, 20) {
    if (d == 100)
      d = dlist[randxor() % dlist.size()];
    else
      break;
  }

  // If d is still 100 after the loop, exit the function
  if (d == 100)
    return; // 2~99

  queue<P> que;
  que.emplace(si, sj);
  vector<P> log;

  // Perform a random walk from the starting cell
  while (que.size()) {
    auto [i, j] = que.front();
    que.pop();

    // If the current cell doesn't have the split 'd', add it and log the cell
    if (!split[i][j].count(d)) {
      split[i][j].insert(d);
      splitadd(i, j, d);
      log.emplace_back(i, j);
    }

    // If there are farther cells available, choose one randomly and enqueue it
    if (farther_cells[i][j].size()) {
      auto [ni, nj] =
          farther_cells[i][j][randxor() % farther_cells[i][j].size()];
      que.emplace(ni, nj);
    }
  }

  // Log the history of this operation
  history.emplace_back(1, d, log);
}

// Function to perform a combination operation on a grid
void combine() {
  // Randomly choose a starting position on the grid
  int si = randxor() % 20;
  int sj = randxor() % 20;

  // Iterate 20 times to find a cell with more than one split; if not found,
  // reselect
  rep(_, 20) {
    if (split[si][sj].size() == 1) {
      si = randxor() % 20;
      sj = randxor() % 20;
    } else
      break;
  }

  // If still only one split in the selected cell, exit the function
  if (split[si][sj].size() == 1)
    return;

  vl dlist;

  // Gather all split identifiers in the current cell into dlist
  for (auto x : split[si][sj])
    dlist.push_back(x);

  int d = 100;

  // Try to find a non-100 split identifier from dlist, else exit function
  rep(_, 20) {
    if (d == 100)
      d = dlist[randxor() % dlist.size()];
    else
      break;
  }
  if (d == 100)
    return;

  queue<P> que;
  que.emplace(si, sj);
  vector<P> log;

  // Perform a breadth-first search starting from the selected cell
  while (que.size()) {
    auto [i, j] = que.front();
    que.pop();

    // If the current cell contains the split 'd', remove it and log the cell
    if (!split[i][j].count(d))
      continue;
    split[i][j].erase(d);
    splitdelete(i, j, d);
    log.emplace_back(i, j);

    // Enqueue all 'farther cells' connected to the current cell for processing
    for (auto [ni, nj] : farther_cells[i][j]) {
      que.emplace(ni, nj);
    }
  }

  // Log the history of this combination operation
  history.emplace_back(2, d, log);
}

void ToNeighbor() {
  // 近傍への遷移を行う
  // 操作をstackに保存する
  int rand = randxor() % 100;
  if (rand < 35)
    separate(); // 1. separate 分断
  else if (rand < 70)
    combine(); // 2. combine 結合
  else if (rand < 100)
    separate_reverse_randomwalk();
}

void Rollback() {
  // ToNeighbor関数での操作を取り消す
  // 最後に行われた操作はstackから取り出す
  if (history.size() == 0) {
    throw runtime_error("履歴が空です");
  }
  auto [type, d, log] = history.back();
  if (type == 1) {
    for (auto [i, j] : log) {
      split[i][j].erase(d);
      splitdelete(i, j, d);
    }
  }
  if (type == 2) {
    for (auto [i, j] : log) {
      split[i][j].insert(d);
      splitadd(i, j, d);
    }
  }
  history.pop_back();
}

// Function implementing the simulated annealing algorithm
void Annealing() {
  int loop = 0; // Count of the total iterations
  int move = 0; // Count of the number of accepted changes

  // Initialize the split structure with a value of 100 in each cell
  rep(i, 20) {
    rep(j, 20) {
      int xx = 100;
      split[i][j].insert(xx);
      add(i, j, xx);
    }
  }

  int best_score = 0; // Track the best score obtained during the annealing

  // Main loop of the annealing process
  while (true) {
    // Check the elapsed time every 300 iterations
    if (loop % 300 == 0) {
      now_time = std::chrono::system_clock::now();
      progress = std::chrono::duration_cast<std::chrono::milliseconds>(
                     now_time - start_time)
                     .count();
      // Break the loop if the time limit is exceeded
      if (progress > TIME_LIMIT)
        break;
    }
    loop++;
    double old_score = score; // Store the current score

    ToNeighbor(); // Make a change to the current solution (transition to a
                  // neighbor state)
    double new_score = score; // Calculate the new score after the change

    double co = 64000; // A coefficient affecting the probability of accepting
                       // worse solutions
    double score_ratio =
        new_score / old_score; // Ratio of new score to old score
    double temp = start_temp + (end_temp - start_temp) * progress /
                                   TIME_LIMIT; // Current temperature
    double prob =
        exp(((double)-1 + score_ratio) * co *
            pow(0.1, temp)); // Probability of accepting the new solution

    // Accept the new solution if it's better or with a certain probability if
    // it's worse
    if (score_ratio >= 1 ||
        prob >= ((randxor() % (1 << 30)) / (double)(1 << 30))) {
      // Accept the transition
      move++;
      best_score = max(best_score, score);
    } else {
      Rollback(); // Revert to the previous state if the new solution is not
                  // accepted
    }
  }

  // Output statistics about the annealing process
  cerr << "Number of loops   : " << loop << endl;
  cerr << "Number of moves   : " << move << endl;
  cerr << "Elapsed ms        : " << progress << endl;
  cerr << "Best intermediate score: " << 1000000 * best_score / 40000 << endl;
  final_answer(); // Finalize and output the best solution found
}

// Function to calculate probabilities for positions in a grid
void get_prob() {
  // Iterate over all grid cells (20x20 grid assumed)
  rep(i, 20) {
    rep(j, 20) {
      queue<P> que;      // Initialize a queue for breadth-first traversal
      que.emplace(i, j); // Start from the current cell

      // Process each cell in the queue
      while (que.size()) {
        auto [ni, nj] = que.front(); // Get the current cell
        que.pop();
        density[ni][nj]++; // Increment the density for this cell

        // Skip if this is the entrance cell
        if (ni == i0 && nj == 0)
          continue;

        // Enqueue the cell closer to the entrance (as per closer_cells mapping)
        que.emplace(closer_cells[ni][nj]);
      }
    }
  }

  // Create a weighted list of probabilities based on the calculated densities
  rep(i, 20) {
    rep(j, 20) {
      // Add the cell to the probability list inversely proportional to its
      // density
      rep(_, 800 / density[i][j]) prob.emplace_back(i, j);
    }
  }
}

signed main() {
  input();
  get_prob();
  Annealing();
}
