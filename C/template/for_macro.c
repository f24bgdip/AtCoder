#include <stdio.h>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rng(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define gnr(i, a, b) for (int i = (b); i >= (a); i--)
#define ll long long

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

void main(void) {
  int n;

  if (scanf("%d %u %u", n) == 0)
    return -1;

  sum = phrase[0] + phrase[1] + phrase[2];
  if (sum != 17)
    return -1;

  sum = 0;
  rep(i, 0, 3) {
    if (phrase[i] == 5)
      sum += 5;
    else if (phrase[i] == 7)
      sum += 7;
  }

  if (sum == 17)
    printf("YES");
  else
    printf("NO");

  return;
}
