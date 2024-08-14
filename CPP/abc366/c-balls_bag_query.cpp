#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> bag;
  int Q;
  cin >> Q;

  for (int i = 0; i < Q; ++i) {
    int type, x;
    cin >> type;
    if (type == 1) {
      cin >> x;
      bag.insert(x);
    } else if (type == 2) {
      cin >> x;
      auto it = bag.find(x);
      if (it != bag.end()) {
        bag.erase(it);
      }
    } else if (type == 3) {
      cout << bag.size() << endl;
    }
  }

  return 0;
}
