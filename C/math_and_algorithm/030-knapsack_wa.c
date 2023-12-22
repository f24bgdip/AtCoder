#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int weight;
  int value;
} Item;

int main() {
  int N, W;
  if (scanf("%d %d", &N, &W) != 2)
    return -1;

  int w[N], v[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d %d", &w[i], &v[i]) != 2)
      return -1;
  }

  Item dp[N + 1];
  dp[0].weight = 0;
  dp[0].value = 0;
  dp[1].weight = w[0];
  dp[1].value = v[0];

  for (int i = 2; i < N + 1; i++) {
    Item items[2];
    items[0].weight = dp[i - 1].weight + w[i - 1];
    items[0].value = dp[i - 1].value + v[i - 1];
    items[1].weight = dp[i - 2].weight + w[i - 1];
    items[1].value = dp[i - 2].value + v[i - 1];

    int candidate = -1;
    if (W > items[0].weight && items[0].value > items[1].value) {
      candidate = 0;
    } else if (W > items[1].weight && items[0].value < items[1].value) {
      candidate = 1;
    }

    Item item;
    if (dp[i - 1].value > dp[i - 2].value) {
      item.value = dp[i - 1].value;
      item.weight = dp[i - 1].weight;
    } else {
      item.value = dp[i - 2].value;
      item.weight = dp[i - 2].weight;
    }

    if (candidate != -1) {
        // 価値の高い方
    } else {
        // 価値の高い方
    }
  }

  printf("%d\n", dp[N].value);
  return 0;
}