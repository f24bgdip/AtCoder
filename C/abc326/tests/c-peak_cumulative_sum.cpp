#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> cum_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        cum_sum[i + 1] = cum_sum[i] + A[i];
    }

    int max_value = cum_sum[N];  // 累積和の最大値を取得

    // y座標の最大値から0までデクリメントしながらループ
    for (int y = max_value; y >= 0; --y) {
        for (int x = 0; x <= N; ++x) {
            // 現在のx座標の累積和がy座標以上で、1つ前のx座標の累積和がy座標未満の場合、*をプリント
            if (cum_sum[x] >= y && (x == 0 || cum_sum[x - 1] < y)) {
                std::cout << "* ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
