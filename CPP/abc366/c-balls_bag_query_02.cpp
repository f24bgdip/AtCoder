#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<int, int> hand;
  int query_count, type, x;
  int distinct_count = 0;

  cin >> query_count;

  for (int i = 0; i < query_count; ++i) {
    cin >> type;
    if (type == 1) {
      cin >> x;
      if (hand[x] == 0) {
        distinct_count++;
      }
      hand[x]++;
    } else if (type == 2) {
      cin >> x;
      hand[x]--;
      if (hand[x] == 0) {
        distinct_count--;
      }
    } else if (type == 3) {
      cout << distinct_count << endl;
    }
  }

  return 0;
}
