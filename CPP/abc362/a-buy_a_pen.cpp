#include <iostream>
#include <string>

int main() {
  int R, G, B;
  std::string C;

  std::cin >> R >> G >> B;
  std::cin >> C;

  int minCost = 0;
  switch (C[0]) {
  case 'R':
    minCost = std::min(G, B);
	break;
  case 'G':
    minCost = std::min(R, B);
	break;
  case 'B':
    minCost = std::min(R, G);
	break;
  }

  std::cout << minCost << std::endl;

  return 0;
}
