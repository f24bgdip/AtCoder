#include <stdio.h>

int find(int *parent, int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent, parent[x]);
}

void unite(int *parent, int *rank, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

int main(void) {
    int N, K, L;
    scanf("%d %d %d", &N, &K, &L);
    int road_parent[N+1], road_rank[N+1], rail_parent[N+1], rail_rank[N+1];

    // Union-Findの初期化
    for (int i = 1; i <= N; i++) {
        road_parent[i] = rail_parent[i] = i;
        road_rank[i] = rail_rank[i] = 0;
    }

    // 道路による連結
    for (int i = 0; i < K; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        unite(road_parent, road_rank, p, q);
    }

    // 鉄道による連結
    for (int i = 0; i < L; i++) {
        int r, s;
        scanf("%d %d", &r, &s);
        unite(rail_parent, rail_rank, r, s);
    }

    // 道路と鉄道の連結成分をカウント
    // ...

    return 0;
}
