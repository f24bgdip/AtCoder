#include <math.h>
#include <stdio.h>

int main(void) {
  int ax, ay, ar;
  if (scanf("%d %d %d", &ax, &ay, &ar) != 3)
    return -1;

  int bx, by, br;
  if (scanf("%d %d %d", &bx, &by, &br) != 3)
    return -1;

  double dx = (double)bx - ax;
  double dy = (double)by - ay;
  double distance = sqrt(pow(dx, 2) + pow(dy, 2));

  printf("%.9lf\n", distance);

  int case_num;
  if (distance < fabs(ar - br)) {
    // One circle within the other, no touch
    case_num = 1;
  } else if (distance == fabs(ar - br)) {
    // One circle within the other, touching
    case_num = 2;
  } else if (distance < ar + br) {
    // Circles intersect
    case_num = 3;
  } else if (distance == ar + br) {
    // Circles touch but do not intersect
    case_num = 4;
  } else {
    // Circles do not touch
    case_num = 5;
  }

  printf("%d\n", case_num);
  return 0;
}
