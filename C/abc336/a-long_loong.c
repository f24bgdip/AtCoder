#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }

int main() {
  int N;
  if (scanf("%d", &N) != 1)
    return -1;

  printf("L");
  for (int i = 0; i < N; i++) {
    printf("o");
  }
  printf("ng\n");

  return 0;
}
