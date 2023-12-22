#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200001
// #define MAX_N 9
#define QUEUE_SIZE 500

bool is_queuefull(int head, int tail) {
  return (((tail - head + QUEUE_SIZE) % QUEUE_SIZE) + 1) == QUEUE_SIZE;
}

int main() {
  int N, Q;
  if (scanf("%d %d", &N, &Q) != 2)
    return -1;

  int A[N], freq[MAX_N] = {0};
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    if (A[i] < MAX_N) {
      freq[A[i]]++;
    }
  }

  int mex = 0;
  int mex_q[QUEUE_SIZE];
  int head = 0, tail = 0;

  while (!is_queuefull(head, tail)) {
    if (freq[mex] == 0) {
      int i = tail % QUEUE_SIZE;
      mex_q[i] = mex;
      tail = (tail + 1) % QUEUE_SIZE;
    }
    mex++;
  }

  mex = mex_q[head];
  head = (head + 1) % QUEUE_SIZE;

  for (int q = 0; q < Q; q++) {
    int i, x;
    scanf("%d %d", &i, &x);

    i--;

    // 更新前A[i]
    if (A[i] < MAX_N) {
      freq[A[i]]--;
      // 空いたとき
      if (freq[A[i]] == 0 && mex > A[i]) {
        mex = A[i];
        head = 0;
        tail = 0;
      }
    }
    // 更新
    A[i] = x;

    // 更新後A[i]
    if (A[i] < MAX_N) {
      freq[A[i]]++;
      // 埋まったとき
      if (freq[A[i]] == 1 && mex == A[i]) {
        head = 0;
        tail = 0;
        if (head == tail) {
          while (!is_queuefull(head, tail)) {
            if (!freq[mex]) {
              mex_q[tail] = mex;
              tail = (tail + 1) % QUEUE_SIZE;
            }
            mex++;
          }
        }
        mex = mex_q[head];
        head = (head + 1) % QUEUE_SIZE;
      }
    }
    printf("%d\n", mex);
  }
  return 0;
}
