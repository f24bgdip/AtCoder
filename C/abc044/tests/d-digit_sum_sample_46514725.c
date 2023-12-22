#include <stdio.h>
#include <math.h>

long long n, s;

// 基数bと数値nを受け取り、nをb進数に変換した後の各桁の和を計算する関数
long long f(long long b, long long n){   // 計算量はO(log_b(n))
    long long sum = 0;
    while (n > 0) {
        sum += n % b;  // nをbで割った余り（現在の桁の値）をsumに加える
        n /= b;       // nをbで割って次の桁に進む
    }
    return sum;
}

int main(void) {
    int i, max;
    scanf("%lld%lld", &n, &s);

    // 特殊ケースの処理: nがsと等しい場合、答えはn + 1
    if (n == s) {
        printf("%lld\n", n + 1);
        return 0;
    }

    // 基数bの最大値をsqrt(n)と制限
    max = (int)sqrt(n);
    
    // 基数bを2からmaxまで増加させていく
    for (i = 2; i <= max; i++) {
        if (s == f(i, n))  // 各桁の和がsと等しい場合、答えを見つけた
            break;
    }
    
    if (i <= max)  // 答えを見つけた場合
        printf("%d\n", i);
    else {  // 答えを見つけられなかった場合、逆順に検査を行う
        for (i = max; i > 1; i--) {
            if ((n - s) / i + 1 > 1 && (n - s) % i == 0 && s == f((n - s) / i + 1, n))
                break;
        }
        
        if (i > 1)  // 答えを見つけた場合
            printf("%lld\n", (n - s) / i + 1);
        else if ((n - s) / i + 1 > 1 && s == f((n - s) / i + 1, n))  // 最後のチェック
            printf("%lld\n", (n - s) / i + 1);
        else  // 答えが見つからなかった場合
            puts("-1");
    }
    
    return 0;
}
