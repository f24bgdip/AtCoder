#include <stdio.h>
#include <stdlib.h>

int cmp(const void* x, const void* y) {
	int a = *(const int*)x, b = *(const int*)y;
	return a < b ? -1 : a > b;
}

struct mofu {
	int idx, value;
};

/* value の降順 */
int cmp_mofu(const void* x, const void* y) {
	struct mofu a = *(const struct mofu*)x, b = *(const struct mofu*)y;
	return a.value > b.value ? -1 : a.value < b.value;
}

int N, M, L;
int a[114514];
struct mofu b[114514];
int c[114514], d[114514];

/* それぞれの主菜に対し、提供されない副菜 */
int ec[114514], *es[114514];

void ae(int f, int t) {
	es[f] = realloc(es[f], sizeof(*es[f]) * (ec[f] + 1));
	if (es[f] == NULL) exit(2);
	es[f][ec[f]++] = t;
}

int arimasuka(const int* array, int array_size, int target) {
	int l = 0, r = array_size - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (array[m] == target) return 1;
		else if (array[m] < target) l = m + 1;
		else r = m - 1;
	}
	return 0;
}

int main(void) {
	int i;
	int ans = 0;
	if (scanf("%d%d%d", &N, &M, &L) != 3) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &a[i]) != 1) return 1;
	}
	for (i = 0; i < M; i++) {
		if (scanf("%d", &b[i].value) != 1) return 1;
		b[i].idx = i;
	}
	for (i = 0; i < L; i++) {
		if (scanf("%d%d", &c[i], &d[i]) != 2) return 1;
		c[i]--;
		d[i]--;
	}

	/* 各主菜について、提供されない副菜を登録する */
	for (i = 0; i < L; i++) {
		ae(c[i], d[i]);
	}
	for (i = 0; i < N; i++) {
		if (ec[i] > 0) qsort(es[i], ec[i], sizeof(*es[i]), cmp);
	}

	/* 各主菜について、提供される副菜を探す */
	qsort(b, M, sizeof(*b), cmp_mofu);
	for (i = 0; i < N; i++) {
		int j;
		for (j = 0; j < M; j++) {
			if (!arimasuka(es[i], ec[i], b[j].idx)) {
				int candidate = a[i] + b[j].value;
				if (candidate > ans) ans = candidate;
				break;
			}
		}
	}

	/* 答えを出力する */
	printf("%d\n", ans);

	return 0;
}

/*

実験

a = [47718, 21994, 74148, 76721, 98917, 73766, 29598, 59035, 69293, 29127]
b = [7017, 46004, 16086, 62644, 74928, 57404, 32168, 45794, 19493, 71590]

al = sorted(list(enumerate(a)), key=lambda x: -x[1])
bl = sorted(list(enumerate(b)), key=lambda x: -x[1])

ts = []

for ai, av in al:
    for bi, bv in bl:
        ts.append((av + bv, ai, bi))

ts.sort(key=lambda x: -x[0])

print(ts)

*/

/*

最大の可能性があるのは、各主菜に残っているうち最大の副菜を組み合わせたもの
セグメント木？
普通に二分探索かなんかで管理し、各主菜で候補を探せば良い
多すぎる？
提供されないのは高々10**5種類 → 多分おｋ

*/
