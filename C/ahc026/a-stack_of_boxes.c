#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOX_HEIGHT 40

const int MAX_NUMBER = 200;
const int MAX_MOUNTAIN = 10;
const int TOTAL_MAX_OPERATIONS = 5000;
const int MAX_OPERATION_SEQUENCE = 10;
const int MAX_ENERGY_CONSUMPTION = 60;
const int INF = 1 << 29;

typedef struct {
  int energy[MAX_BOX_HEIGHT]; // 消費体力の目安
  int boxes[MAX_BOX_HEIGHT];  // 箱の番号が格納されている配列
  int top_box_num;            // 一番上にある箱の番号
  int top_box_height;         // 一番上にある箱までの高さ
  int max_box_num;
  int max_box_height;
  int min_box_num;          // 最小の箱の番号
  int min_box_height;       // 最小の箱の高さ
  float mean;               // 箱の番号の平均値
  float variance;           // 箱の番号の分散
  float standard_deviation; // 箱の番号の標準偏差
} Mountain;

typedef struct {
  int move_box_num;         // 移動する箱の番号
  int destination_mountain; // 移動先の山のインデックス
} Operation;

typedef struct {
  int box_num;
  int box_index;
} Box;

typedef struct {
  int energy;
}

int compare_min_box_num(const void *a, const void *b) {
  Mountain *mt_a = *(Mountain **)a;
  Mountain *mt_b = *(Mountain **)b;

  // 山が空の場合(INF)は、比較対象の最後に配置
  if (mt_a->top_box_num == INF)
    return 1;
  if (mt_b->top_box_num == INF)
    return -1;

  // min_box_numの昇順にソート
  return (mt_a->min_box_num - mt_b->min_box_num);
}

void calculate_statistics(const int *values, int n, float *mean,
                          float *variance, float *standard_deviation) {
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += values[i];
  }
  *mean = (float)sum / n;

  float var_sum = 0;
  for (int i = 0; i < n; ++i) {
    var_sum += pow(values[i] - *mean, 2);
  }
  *variance = var_sum / n;
  *standard_deviation = sqrt(*variance);
}

void calculate_energy(mountains, int v, int o) {
  // 消費体力の計算
  for (int k = 0; k < ; ++k)
    for (int i = 0; i < mountains[v][o][k].top_box_height - 1; ++i) {
      for (int j = 1; j < mountains[v][o][k].top_box_height; ++j) {
        if (mountains[v][o][k].boxes[i] > mountains[v][o][k].boxes[j])
      }
    }
}

int main() {
  Mountain mountains[MAX_NUMBER][MAX_OPERATION_SEQUENCE][MAX_MOUNTAIN];
  Mountain *mountains_pointers[MAX_MOUNTAIN];
  Operation operations[MAX_NUMBER][MAX_OPERATION_SEQUENCE + 1];

  memset(mountains, (int)0, size(mountains));
  memset(operations, (int)0, size(operations));

  // Scan
  int height = MAX_NUMBER / MAX_MOUNTAIN;
  for (int i = 0; i < MAX_MOUNTAIN; ++i) {
    for (int j = 0; j < height; ++j) {
      if (scanf("%d", &mountains[i][j][k].boxes[j]) != 1)
        return -1;
    }
  }

  // 動的計画法の最小個数部分和問題用の配列
  min_energy_dp[MAX_NUMBER][MAX_ENERGY_CONSUMPTION];
  for (int i = 0; i < MAX_NUMBER; ++i)
    for (int j = 0; j < MAX_ENERGY_CONSUMPTION; ++j)
      min_energy_dp[i][j] = INF;

  min_energy_dp[0][0] = 0;

  // 運び出す箱
  for (int i = 0; i < MAX_NUMBER; ++i) {
    // 操作
    for (int j = 0; i < MAX_OPERATION_SEQUENCE; ++j) {
      // 山情報の初期化
      for (int k = 0; k < MAX_MOUNTAIN; ++k) {
        int cnt = 0;
        int max = 0;
        int max_height = 0;
        int min = INF;
        int min_height = 0;
        for (int l = 0; l < height; ++l) {
          if (mountains[i][j][k].boxes[l] != INF &&
              mountains[i][j][k].boxes[l] > 0) {
            cnt++;
            if (max < mountains[i][j][k].boxes[l]) {
              max = mountains[i][j][k].boxes[l];
              max_height = cnt;
            }
            if (min > mountains[i][j][k].boxes[l]) {
              min = mountains[i][j][k].boxes[l];
              min_height = cnt;
            }
          } else if (mountains[i][j][k].boxes[l] == 0)
            break;
        }
        if (cnt > 0) {
          // 箱が積まれている
          mountains[i][j][k].top_box_num = mountains[i][j][k].boxes[cnt];
          mountains[i][j][k].top_box_height = cnt;
          mountains[i][j][k].min_box_num = min;
          mountains[i][j][k].min_box_heigh = min_cnt;

          calculate_statistics(
              mountains[i][j][k].boxes[0], mountains[i][j][k].top_box_height,
              &mountains[i][j][k].mean, &mountains[i][j][k].variance,
              &mountains[i][j][k].standard_deviation);
        } else {
          // 箱が積まれていない
          mountains[i][j][k].top_box_num = INF;
          mountains[i][j][k].min_box_num = INF;
        }
        calculate_energy(mountains, i, j);
        *mountains_pointers[k] = &mountains[k];
      }

      // 山をそこに含まれる箱の最小の番号で昇順に並び替え
      qsort(mountains_pointers, MAX_MOUNTAIN, sizeof(Mountain *),
            compare_min_box_num);

      // 操作2
      // 運び出しの対象の箱の番号は最も小さい番号でもある
      // 昇順にソートしてあるので、最初の山が移動元である
      // 最小の箱が一番上にあれば、運び出す
      if (mountains[i][j][0].min_box_heigh ==
          mountains[i][j][0].top_box_height) {
        // 操作2の出力を生成
        operations[i][MAX_OPERATION_SEQUENCE].move_box_num =
            mountains[i][j][0].min_box_num;
        operations[i][MAX_OPERATION_SEQUENCE].destination_mountain = 0;
        // 次の箱の運び出しに移行する
        continue;
      }

      // 操作1
      // 1. 配列生成
      // DPで使用する配列を消費体力≒移動パターンから生成する
      int a[MAX_OPERATION_SEQUENCE];
      int a_cnt = 0;

      // 課題. 箱が先か、山が先か

      // 1.1. 移動する箱を決める
      // 対象の箱の上に積まれている箱から順に条件に合うものを選ぶ
      for (int h = mountains[i][j][0].min_box_height;
           h < mountains[i][j][0].top_box_height; ++h)
        v = mountains[i][j][0].boxes[h - 1];

      // 1.2. 移動先の山を決める
      // アプローチ1: 以降に運び出す箱への悪影響を減らす
      // 最も遠い値を持つ山から順に移動先の候補とする
      for (int k = MAX_MOUNTAIN - 1; k >= 1; --k) {

        // アプローチ2: 箱が昇順に並ぶことを意識する
        if (mountains[i][j][k].top_box_num > v) {
          // 条件に合うので、消費体力を計算して、配列に格納する
          // 消費体力計算
          int box_count = mountains[i][j][0].top_box_height - h + 1;
          int energy_required = box_count + 1;
          // 配列に格納
          a[a_cnt++] = energy_required;

          // 山の状態変更
          // 山の情報の更新

        } else {
          // 条件に合わないので、移動先の山を変更する
          continue;
        }
      }
    }
  }

  return 0;
}
