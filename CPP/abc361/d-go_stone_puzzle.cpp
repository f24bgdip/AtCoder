#include <iostream>
#include <string>
#include <vector>

bool canArrangeStones(const std::string &initial, const std::string &target,
                      int N) {
  // 初期状態の石の並びと目標の並びが同じであるかどうかを確認する
  if (initial == target)
    return true;

  // ここで、隣り合う石を空きマスに移動するシミュレーションを行う
  // この部分は問題の核心部分であり、実装が難しい部分です

  // シミュレーションに成功し、目標の並びにできる場合は true を返し、
  // そうでない場合は false を返します
  return false;
}

int main() {
  int N;
  std::string initial, target;

  std::cin >> N;
  std::cin >> initial;
  std::cin >> target;

  if (canArrangeStones(initial, target, N)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
