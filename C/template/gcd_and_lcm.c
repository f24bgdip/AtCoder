// 最大公約数を求める
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// N個の最大公約数を求める
int ngcd(vector<int> a) {
  int res;
  res = a[0];
  for (int i = 1; i < a.size() && res != 1; i++) {
    res = gcd(a[i], res);
  }
  return res;
}

// 最小公倍数
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// N個の最小公倍数
int nlcm(vector<int> numbers) {
  int res;
  res = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    res = lcm(res, numbers[i]);
  }
  return res;
}
