#include <chrono>
#include <iostream>
#include <vector>

const int iterations = 100000000;
const int num_trials = 10; // 試行回数

// 前置インクリメントの速度を計測する関数
long long measure_pre_increment() {
  auto start_time = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < iterations; ++i) {
    // Do nothing
  }
  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                               start_time)
      .count();
}

// 後置インクリメントの速度を計測する関数
long long measure_post_increment() {
  auto start_time = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < iterations; i++) {
    // Do nothing
  }
  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                               start_time)
      .count();
}

int main() {
  std::vector<long long> durations_pre_increment, durations_post_increment;

  // 各関数を複数回呼び出し、結果を保存します
  for (int trial = 0; trial < num_trials; ++trial) {
    durations_pre_increment.push_back(measure_pre_increment());
    durations_post_increment.push_back(measure_post_increment());
  }

  // 各結果と平均値を出力します
  long long total_duration_pre_increment = 0, total_duration_post_increment = 0;
  std::cout << "Pre-increment durations: ";
  for (const auto &duration : durations_pre_increment) {
    std::cout << duration << " ms ";
    total_duration_pre_increment += duration;
  }
  std::cout << std::endl
            << "Average pre-increment duration: "
            << (double)total_duration_pre_increment / num_trials << " ms"
            << std::endl;

  std::cout << "Post-increment durations: ";
  for (const auto &duration : durations_post_increment) {
    std::cout << duration << " ms ";
    total_duration_post_increment += duration;
  }
  std::cout << std::endl
            << "Average post-increment duration: "
            << (double)total_duration_post_increment / num_trials << " ms"
            << std::endl;

  return 0;
}
