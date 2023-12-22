#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // 乱数生成器の初期化

  for (int i = 0; i < 10; i++) { // 10個のテストケースを生成
    for (int j = 0; j < 4; j++) { // 各テストケースについて4点を生成
      int x = rand() % 100; // X座標（0から99の範囲でランダム）
      int y = rand() % 100; // Y座標（0から99の範囲でランダム）
      printf("%d %d\n", x, y);
    }
    printf("\n");
  }
  return 0;
}
