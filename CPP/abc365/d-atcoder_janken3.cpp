#include <iostream>
#include <string>

using namespace std;

char decode(char c, char last) {
  if (c == 'R') {
    if (last != 'P')
      return 'P';
    else
      return 'R';
  }
  if (c == 'P') {
    if (last != 'S')
      return 'S';
    else
      return 'P';
  }
  // if (c == 'S')
  if (last != 'R')
    return 'R';
  else
    return 'S';
}

int main() {
  int N;
  cin >> N;
  string text;
  cin >> text;

  char last = '\0';
  int count = 0;

  for (int i = 0; i < N; ++i) {
    char code = decode(text[i], last);

    if (code != last) {
      count++;
      last = code;
    }
  }

  cout << count << endl;

  return 0;
}
