#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isForbiddenPattern(char c1, char c2, const char *T, int M) {
    for (int i = 1; i < M - 1; i++) {
        if ((c1 == T[i] && c2 == T[i]) || (c1 == T[i] && c2 == T[i + 1]) || 
            (c1 == T[i + 1] && c2 == T[i])) {
            return true;
        }
    }
    return false;
}

bool can_transform(int N, int M, char *S, char *T) {
  if (S[0] != T[0] || S[N - 1] != T[M - 1]) {
    return false;
  }

  bool valid_chars[26] = {false};
  for (int i = 0; i < M; i++) {
    valid_chars[T[i] - 'A'] = true;
  }

  for (int i = 0; i < N; i++) {
    if (!valid_chars[S[i] - 'A'])
      return false;

    for (int j = 1; j < M - 1; j++) {
      if (S[i] == T[j] && S[i + 1] == T[j])
        return false;
    }
  }

  return true;
}

int main() {
  int N, M;
  if (scanf("%d %d", &N, &M) != 2)
    return -1;

  char S[N + 1], T[M + 1];
  if (scanf("%s %s", S, T) != 2)
    return -1;

  bool result = can_transform(N, M, S, T);
  printf("%s\n", result ? "Yes" : "No");

  return 0;
}
