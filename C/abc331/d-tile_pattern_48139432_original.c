#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_uint32_t(FILE *__restrict stream, uint32_t *__restrict nr) {
  uint8_t ch;
  *nr = 0;
  while ((ch = fgetc(stream)) && ('0' <= ch && ch <= '9')) {
    *nr *= 10;
    *nr += ch - '0';
  }
  if (ch == '\r') {
    fgetc(stream);
  }
}

void reads(FILE *__restrict file, char *__restrict s, uint32_t *__restrict sl) {
  uint32_t t;
  if (sl == NULL) {
    sl = &t;
  }
  *sl = 0;
  while ((s[*sl] = fgetc(file)) && (('a' <= s[*sl] && s[*sl] <= 'z') ||
                                    ('A' <= s[*sl] && s[*sl] <= 'Z'))) {
    ++*sl;
  }
  if (s[*sl] == '\r') {
    fgetc(file);
  }
  s[*sl] = '\0';
}

uint32_t n, m;
char a[1001][1001];
uint64_t b[1001][1001];

uint64_t sum(int32_t y, int32_t x) {
  if (y < 0 || x < 0) {
    return 0;
  }
  ++y;
  ++x;
  uint32_t ya = y / n;
  uint32_t ym = y % n;
  uint32_t xa = x / n;
  uint32_t xm = x % n;
  uint64_t s = 0;
  s += b[n][n] * ya * xa;
  s += b[ym][n] * xa;
  s += b[n][xm] * ya;
  s += b[ym][xm];
  // fprintf(stdout, "Sub %u %u has %lu\n", x, y, s);
  return s;
}

void check(uint32_t y1, uint32_t x1, uint32_t y2, uint32_t x2) {
  fprintf(stdout, "%lu\n",
          sum(y2, x2) + sum(y1 - 1, x1 - 1) - sum(y2, x1 - 1) -
              sum(y1 - 1, x2));
}

int main(void) {
  {
    FILE *__restrict in;
#ifdef ONLINE_JUDGE
    in = stdin;
#else
    in = fopen("in", "r");
#endif

    read_uint32_t(in, &n);
    read_uint32_t(in, &m);
    {
      int32_t i, j;
      for (i = 1; i <= n; ++i) {
        reads(in, a[i] + 1, NULL);
      }
      for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
          b[i][j] =
              b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (a[i][j] == 'B');
        }
      }
      uint32_t x, y, z, w;
      for (i = 0; i < m; ++i) {
        read_uint32_t(in, &x);
        read_uint32_t(in, &y);
        read_uint32_t(in, &z);
        read_uint32_t(in, &w);
        check(x, y, z, w);
      }
    }

    fclose(in);
  }

  return 0;
}
