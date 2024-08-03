#include <algorithm>
#include <iostream>

using namespace std;

struct Cuboid {
  int x1, y1, z1;
  int x2, y2, z2;
};

bool isOverlap1D(int min1, int max1, int min2, int max2) {
  return max(min1, min2) < min(max1, max2);
}

bool isOverlap(Cuboid c1, Cuboid c2) {
  return isOverlap1D(min(c1.x1, c1.x2), max(c1.x1, c1.x2), min(c2.x1, c2.x2),
                     max(c2.x1, c2.x2)) &&
         isOverlap1D(min(c1.y1, c1.y2), max(c1.y1, c1.y2), min(c2.y1, c2.y2),
                     max(c2.y1, c2.y2)) &&
         isOverlap1D(min(c1.z1, c1.z2), max(c1.z1, c1.z2), min(c2.z1, c2.z2),
                     max(c2.z1, c2.z2));
}

int main() {
  Cuboid c1, c2;

  cin >> c1.x1 >> c1.y1 >> c1.z1 >> c1.x2 >> c1.y2 >> c1.z2;
  cin >> c2.x1 >> c2.y1 >> c2.z1 >> c2.x2 >> c2.y2 >> c2.z2;

  if (isOverlap(c1, c2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
