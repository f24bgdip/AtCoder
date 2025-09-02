#include <iostream>
using namespace std;

int main() {
  char Sab, Sac, Sbc;
  cin >> Sab >> Sac >> Sbc;

  if (Sab == '<' && Sac == '<' && Sbc == '<') {
    cout << "B" << endl;
  } else if (Sab == '<' && Sac == '<' && Sbc == '>') {
    cout << "C" << endl;
  } else if (Sab == '<' && Sac == '>' && Sbc == '<') {
    cout << "A" << endl;
  } else if (Sab == '<' && Sac == '>' && Sbc == '>') {
    cout << "A" << endl;
  } else if (Sab == '>' && Sac == '<' && Sbc == '<') {
    cout << "A" << endl;
  } else if (Sab == '>' && Sac == '<' && Sbc == '>') {
    cout << "B" << endl;
  } else if (Sab == '>' && Sac == '>' && Sbc == '<') {
    cout << "C" << endl;
  } else if (Sab == '>' && Sac == '>' && Sbc == '>') {
    cout << "B" << endl;
  }

  return 0;
}
