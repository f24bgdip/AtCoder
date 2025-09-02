#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<bool> isAdded(N, false);

  for (int i = 0; i < M; ++i) {
    int index;
    char gender;
    cin >> index >> gender;

    index -= 1;
    if (gender == 'M') {
      if (!isAdded[index]) {
        cout << "Yes" << endl;
        isAdded[index] = true;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
