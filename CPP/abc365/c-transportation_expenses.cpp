#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  long long M;
  cin >> N >> M;

  vector<int> incomes(N);
  int max_income = 0;
  for (int i = 0; i < N; ++i) {
    cin >> incomes[i];
    if (incomes[i] > max_income) {
      max_income = incomes[i];
    }
  }

  int left = 0, right = max_income;
  int cap = 0;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    long long sum = 0;
    for (int income : incomes) {
      sum += min(static_cast<long long>(income), static_cast<long long>(mid));
    }

    if (sum <= M) {
      cap = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  if (cap >= max_income) {
    cout << "infinite" << endl;
  } else {
    cout << cap << endl;
  }

  return 0;
}
