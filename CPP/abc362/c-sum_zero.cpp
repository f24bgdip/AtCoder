#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<long long> L(N), R(N);
  long long sumL = 0, sumR = 0;
  long long adjustValue = 0;

  for (int i = 0; i < N; ++i) {
    cin >> L[i] >> R[i];
    sumL += L[i];
    sumR += R[i];

    if (L[i] > 0) {
      adjustValue += L[i];
    } else if (R[i] < 0) {
      adjustValue += R[i];
    }
  }

  // sumL <= 0 <= sumR でない場合は条件を満たす整数列は存在しない
  if (!(sumL <= 0 && 0 <= sumR)) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  cout << adjustValue << endl;

  // XをL[i]とすると合計が0になるように調整
  vector<int> X(N);
  int currentSum = 0;
  for (int i = 0; i < N; ++i) {
    if (currentSum + L[i] <= 0 && currentSum + R[i] >= 0) {
      X[i] = R[i];
      currentSum += R[i];
    } else {
      X[i] = L[i];
      currentSum += L[i];
    }
    cout << X[i] << " ";
  }
  cout << endl;

  return 0;
}
