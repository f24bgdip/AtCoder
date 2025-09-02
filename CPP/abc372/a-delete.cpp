#include <iostream>
#include <string>

using namespace std;

int main() {
  string a;
  cin >> a;

  string b;
  for (char c : a) {
    if (c != '.') {
      b += c;
    }
  }

  cout << b << endl;

  return 0;
}
