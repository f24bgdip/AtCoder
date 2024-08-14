#include <cstdio>

const int MAX_VALUE = 1000000;
int hand[MAX_VALUE + 1] = {0};

int main() {
  int query_count, type, x;
  int distinct_count = 0;

  scanf("%d", &query_count);

  for (int i = 0; i < query_count; ++i) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &x);
      if (hand[x] == 0) {
        distinct_count++;
      }
      hand[x]++;
    } else if (type == 2) {
      scanf("%d", &x);
      hand[x]--;
      if (hand[x] == 0) {
        distinct_count--;
      }
    } else if (type == 3) {
      printf("%d\n", distinct_count);
    }
  }

  return 0;
}
