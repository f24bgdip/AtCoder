#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main(void) {
  int N;
  scanf("%d", &N);

  int len = 2 * N;
  char *S = (char *)malloc((size_t)len + 1);
  if (scanf("%s", S) != 1) {
    free(S);
    return -1;
  }

  ll cnt = 1;
  ll odd_case_sum = 0;
  ll even_case_sum = 0;
  for (int i = 0; i < len; ++i) {
    // printf("i=%d, S[i]=%c, cnt=%lld\n", i, S[i], cnt);
    if ((char)S[i] == 'A') {
      ll odd = cnt * 2 - 1;
      ll diff = abs((odd - 1) - i);
      // printf("odd = %lld, diff = %lld\n", odd, diff);
      odd_case_sum += diff;

      ll even = cnt * 2;
      diff = abs((cnt * 2 - 1) - i);
      // printf("even = %lld, diff = %lld\n", even, diff);
      even_case_sum += diff;

      cnt++;
    }
  }

  // printf("odd_case=%lld, even_case=%lld\n", odd_case_sum, even_case_sum);
  ll ans = odd_case_sum > even_case_sum ? even_case_sum : odd_case_sum;

  printf("%lld\n", ans);

  free(S);

  return 0;
}
