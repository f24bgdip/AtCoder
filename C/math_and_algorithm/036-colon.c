#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double AC, BC;
  int H, M;
  if (scanf("%lf %lf %d %d", &AC, &BC, &H, &M) != 4)
    return -1;

  double degree_hour, degree_minute, degree;
  degree_hour = (30.0 * H) + (0.5 * M);
  degree_minute = 6.0 * M;
  degree = fabs(degree_hour - degree_minute);
  // printf("%lf\n", degree);

  if (degree > 180) {
    degree = 360 - degree;
  }
  double radian = degree * (M_PI / 180.0);
  double AB = sqrt(pow(AC, 2) + pow(BC, 2) - 2 * AC * BC * cos(radian));

  printf("%.9lf\n", AB);

  return 0;
}
