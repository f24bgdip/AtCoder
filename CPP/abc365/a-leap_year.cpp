#include <iostream>

int daysInYear(int year) {
  if (year % 400 == 0) {
    return 366;
  } else if (year % 100 == 0) {
    return 365;
  } else if (year % 4 == 0) {
    return 366;
  } else {
    return 365;
  }
}

int main() {
  int year;
  std::cin >> year;

  int days = daysInYear(year);
  std::cout << days << std::endl;

  return 0;
}
