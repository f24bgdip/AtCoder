#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;

  std::vector<int> Q(N);
  for (auto &q : Q)
    cin >> q;

  std::vector<int> A(N), B(N);
  for (auto &x : A)
    cin >> x;
  for (auto &x : B)
    cin >> x;

  int ltotal = 0, rtotal = (int)1e8;
  while (ltotal < rtotal) {
    int mtotal = (ltotal + rtotal + 1) / 2;

    bool possible = true;
    int la = 0, ra = mtotal;
    for (int k = 0; k < N; ++k) {
      int q = Q[k];
      int ca = A[k];
      int cb = B[k];

      if (ca == 0) {
        if (cb == 0)
          continue;

        la = std::max(la, mtotal - q / cb);
      } else if (cb == 0) {
        ra = std::min(ra, q / ca);
      } else if (ca > cb) {
        if (q / cb < mtotal) {
          possible = false;
          break;
        } else if (q / ca >= mtotal)
          continue;
        else {
          ra = std::min(ra, (q - cb * mtotal) / (ca - cb));
        }
      } else if (ca < cb) {
        if (q / ca < mtotal) {
          possible = false;
          break;
        } else if (q / cb >= mtotal)
          continue;
        else {
          la = std::max(la, mtotal - (q - ca * mtotal) / (cb - ca));
        }
      } else {
        if (q / ca < mtotal) {
          possible = false;
          break;
        } else {
          continue;
        }
      }
    }

    if (!possible || la > ra) {
      rtotal = mtotal - 1;
    } else {
      ltotal = mtotal;
    }
  }

  cout << ltotal << '\n';
}