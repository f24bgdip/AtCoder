#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int A, B;
    cin >> A >> B;

    // 範囲内の全ての数のGCDを計算
    int g = gcd(B - A, A);

    // gの約数を全て調べ、最大のものを答えとする
    int answer = 1;
    for (int d = 1; d * d <= g; ++d) {
        if (g % d == 0) {
            // d が g の約数
            answer = max(answer, d);
            // g / d も g の約数
            if (d != g / d) {
                answer = max(answer, g / d);
            }
        }
    }

    cout << answer << endl;
    return 0;
}
