#include <iostream>

using namespace std;

int main() {
  int a, b;

  cin >> a >> b;

  if (a == 1 && b == 0) {
    cout << "Yes" << endl;
  } else if (a == 0 && b == 1) {
    cout << "No" << endl;
  } else {
    cout << "Invalid" << endl;
  }

  return 0;
}
