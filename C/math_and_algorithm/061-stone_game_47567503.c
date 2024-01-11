//
//  p061.c
//  problem_answer
//
//  Created by ORUDA Hakusui on 2023/11/14.
//

#include <stdio.h>

int main(int argc, const char *argv[]) {
  if (0) {
    for (int n = 1; n< 1000; n++) {
      long long a = 1;
      while (a < n) {
        a = a * 2 + 1;
      }

      if (a == n)
        printf("Second\n");
      else
        printf("First\n");
    }
  } else {
    long long n;
    scanf("%lld", &n);

    long long a = 1;
    while (a < n) {
      a = a * 2 + 1;
    }

    if (a == n)
      printf("Second\n");
    else
      printf("First\n");
  }
  return 0;
}
