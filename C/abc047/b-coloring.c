#include <stdio.h>

int main() {
  int W, H, N;
  scanf("%d %d %d", &W, &H, &N);

  int left = 0, right = W, top = H, bottom = 0;

  for (int i = 0; i < N; i++) {
    int x, y, a;
    scanf("%d %d %d", &x, &y, &a);

    switch (a) {
    case 1:
      // x < x(i)
      if (x > left)
        left = x;
      break;
    case 2:
      // x > x(i)
      if (x < right)
        right = x;
      break;
    case 3:
      // y < y(i)
      if (y > bottom)
        bottom = y;
      break;
    case 4:
      // y > y(i)
      if (y < top)
        top = y;
      break;
    }
  }

  int width = right - left;
  int height = top - bottom;
  int area = 0;

  if (width > 0 && height > 0) {
    area = width * height;
  }

  printf("%d\n", area);

  return 0;
}
