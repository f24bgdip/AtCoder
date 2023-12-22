void extractBox(mountains, boxToExtract) {
  // 各山を調べ、取り出したい箱が見つかるまでループ
  for (int i = 0; i < mountains.length; i++) {
    for (int j = 0; j < mountains[i].length; j++) {
      // 取り出したい箱を見つけたら
      if (mountains[i][j] == boxToExtract) {
        // 箱を取り出す前に、その上にある箱を別の山に移動する
        moveBoxesOnTop(mountains, i, j);
        // 箱を取り出す
        mountains[i].remove(j);
        return;
      }
    }
  }
}

// 山の上にある箱を別の山に移動する関数
void moveBoxesOnTop(mountains, mountainIndex, boxIndex) {
  // 上にある箱のリストを取得
  int[] boxesToMove = mountains[mountainIndex].slice(0, boxIndex);
  // 移動先の山を決定（ここでは簡略化のためにランダムに選ぶ）
  int moveToMountain = (mountainIndex + 1) % mountains.length;
  // 箱を移動
  foreach (box in boxesToMove) {
    mountains[moveToMountain].add(box);
  }
  // 元の山から箱を削除
  mountains[mountainIndex] = mountains[mountainIndex].slice(boxIndex + 1);
}

// 安全な山の確保
void safeMountain() {
  int safestMountainIndex = -1; // 最も安全な山のインデックスを保存
  int highestSafetyDegree = -1; // 最も高い安全度を保存

  for (int i = 0; i < 10; ++i) {
    if (mountains[i].count == 0) {
      safestMountainIndex = i;
      break;
    }
    if (mountains[i].minNumber > 10) {
      safestMountainIndex = i;
      break;
    }
    if (mountains[i].minNumber > highestSafetyDegree) { // 最も高い安全度を更新
      highestSafetyDegree = mountains[i].minNumber;
      safestMountainIndex = i;
    }
  }

  if (safestMountainIndex != -1) {
    printf("The safest mountain is %d with safety degree of %d\n",
           safestMountainIndex, highestSafetyDegree);
  } else {
    printf("No safest mountain found.\n");
  }

  return;
}

