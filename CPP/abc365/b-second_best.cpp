#include <algorithm>
#include <iostream>
#include <vector>

// 降順
bool compare(const std::pair<int, int> &a, const std::pair<int, int> &b) {
  return a.first > b.first;
}

int findSubjects(const std::vector<int> &nums, int n) {
  if (nums.size() < 2) {
    return -1;
  }

  std::vector<std::pair<int, int>> profile;
  for (size_t i = 0; i < nums.size(); ++i) {
    profile.push_back(std::make_pair(nums[i], i + 1));
  }

  std::sort(profile.begin(), profile.end(), compare);

  return profile[n - 1].second;
}

int main() {
  // 成績表から科目コードを取り出すイメージで。
  int N;
  std::cin >> N;

  std::vector<int> Scores(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> Scores[i];
  }

  int subjectsNumber = findSubjects(Scores, 2);

  if (subjectsNumber != -1) {
    std::cout << subjectsNumber << std::endl;
  }

  return 0;
}
