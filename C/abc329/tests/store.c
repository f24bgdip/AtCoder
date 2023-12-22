char char_combo[MAX_COMBOS][COMBO_LEN];
int combo_count;
generate_char_combinations(char_combo, &combo_count);
// 組み合わせの出力
for (int i = 0; i < combo_count; i++) {
  printf("%s\n", char_combo[i]);
}

// 禁則文字の特定
for (int i = 0; i < combo_count; i++) {
  if (is_forbidden_pairs(char_combo[i], patterns, patterns_count)) {
    printf("禁則文字2: %s\n", char_combo[i]);
  }
}
