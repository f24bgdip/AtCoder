#include <iostream>
#include <map>
#include <vector>

int main() {
  long long N, M;
  std::cin >> N >> M;

  std::map<long long, int> count_map;
  for (long long i = 0; i < N; ++i) {
    long long a;
    std::cin >> a;
    count_map[a]++;
  }

  int max_count = 0;

  for (auto it = count_map.begin(); it != count_map.end(); ++it) {
    long long x = it->first;
    int count = it->second;
    auto inner_it = it;
    ++inner_it;
    while (inner_it != count_map.end() && inner_it->first < x + M) {
      if (inner_it->first < x + M) {
        count += inner_it->second;
      }
      ++inner_it;
    }
    if (count > max_count) {
      max_count = count;
    }
  }

  std::cout << max_count << std::endl;

  return 0;
}
