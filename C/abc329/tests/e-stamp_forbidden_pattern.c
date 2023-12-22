#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const int MAX_PAIRS = 25, PAIR_LEN = 2 + 1;
const int MAX_PATTERNS = 10, PATTERN_LEN = 10 + 1;

int N, M;
char S[25000 + 1], T[5 + 1];

void generate_char_pairs(char pair[MAX_PAIRS][PAIR_LEN], int *count) {
  *count = 0;
  for (int i = 0; i < M; i++) {
    snprintf(pair[*count], PAIR_LEN, "%c%c", T[i], T[i]);
    (*count)++;
    for (int j = 0; j < M; j++) {
      if (i != j) {
        snprintf(pair[*count], PAIR_LEN, "%c%c", T[i], T[j]);
        (*count)++;
      }
    }
  }
}

void generate_write_patterns(char patterns[MAX_PATTERNS][PATTERN_LEN],
                             int *count) {
  *count = 0;
  for (int i = -M - 1; i < M; i++) {
    if (i == -M || i == 0) {
      continue;
    } else if (i < 0) {
      snprintf(patterns[*count], MAX_PATTERNS, "%.*s%s", M + i, T, T);
      (*count)++;
    } else {
      snprintf(patterns[*count], MAX_PATTERNS, "%s%.*s", T, M - i, T + i);
      (*count)++;
    }
  }
}

bool is_forbidden_pairs(const char *pair,
                        const char patterns[MAX_PATTERNS][PATTERN_LEN],
                        int count) {
  for (int i = 0; i < count; i++) {
    char *find = strstr(patterns[i], pair);
    if (find != NULL) {
      return false;
    }
  }
  return true;
}

void generate_forbidden_pairs(const char pair[MAX_PAIRS][PAIR_LEN],
                              int pair_count,
                              const char patterns[MAX_PATTERNS][PATTERN_LEN],
                              int pattern_count,
                              char forbidden_pairs[MAX_PAIRS][PAIR_LEN],
                              int *forbidden_count) {
  *forbidden_count = 0;
  for (int i = 0; i < pair_count; i++) {
    if (is_forbidden_pairs(pair[i], patterns, pattern_count)) {
      strcpy(forbidden_pairs[*forbidden_count], pair[i]);
      (*forbidden_count)++;
    }
  }
}

bool can_transform(char pairs[MAX_PAIRS][PAIR_LEN], int count) {
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

    for (int j = 0; j < count; j++) {
      if (S[i] == pairs[j][0] && S[i + 1] == pairs[j][1])
        return false;
    }
  }

  return true;
}

int main() {
  if (scanf("%d %d", &N, &M) != 2)
    return -1;

  if (scanf("%s %s", S, T) != 2)
    return -1;

  char char_pairs[MAX_PAIRS][PAIR_LEN];
  int pair_count;
  generate_char_pairs(char_pairs, &pair_count);
  // ペアの出力
  // for (int i = 0; i < pair_count; i++) {
  //   printf("%s\n", char_pairs[i]);
  // }

  char patterns[MAX_PATTERNS][PATTERN_LEN];
  int patterns_count;
  generate_write_patterns(patterns, &patterns_count);
  // 上書きパターンの出力
  // for (int i = 0; i < patterns_count; i++) {
  //   printf("%s\n", patterns[i]);
  // }

  char forbidden_pairs[MAX_PAIRS][PAIR_LEN];
  int forbidden_count;

  generate_forbidden_pairs(char_pairs, pair_count, patterns, patterns_count,
                           forbidden_pairs, &forbidden_count);
  // 禁則組み合わせの出力
  // for (int i = 0; i < forbidden_count; i++) {
  //   printf("禁則文字: %s\n", forbidden_pairs[i]);
  // }

  bool result = can_transform(forbidden_pairs, forbidden_count);
  printf("%s\n", result ? "Yes" : "No");

  return 0;
}
