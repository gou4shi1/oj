/************************************************************************
* File Name : cf837G.cpp
* Purpose : chairmanTree
* Creation Date : 2017年08月16日
* Last Modified : 2017年08月17日 星期四 00时59分20秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 75000 + 10;
const int MAXX = 200000;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

// array
typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

// chairmanTree

struct Node {
    LL s;
    int l, r;
} tree[MAXN * 5 * 21];

int node_size;

void newNode(int &x, LL S, int L, int R) {
    x = ++node_size;
    tree[x] = {S, L, R};
}

void build(int &rt, int pre_rt, int pos, LL val, int l, int r) {
    newNode(rt, tree[pre_rt].s + val, tree[pre_rt].l, tree[pre_rt].r);
    if (l == r)
        return;
    int m = (l + r) >> 1;
    if (pos <= m)
        build(tree[rt].l, tree[pre_rt].l, pos, val, l, m);
    else
        build(tree[rt].r, tree[pre_rt].r, pos, val, m+1, r);
}

LL query(int s, int e, int l, int r, int k) {
    if (l == r)
        return tree[e].s - tree[s].s;
    int m = (l + r) >> 1;
    if (k <= m)
        return query(tree[s].l, tree[e].l, l, m, k);
    else
        return tree[tree[e].l].s - tree[tree[s].l].s + query(tree[s].r, tree[e].r, m+1, r, k);
} 

int rt1[MAXN * 2], rt2[MAXN * 3];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x1, x2, y1, a, b, y2;
        scanf("%d%d%d%d%d%d", &x1, &x2, &y1, &a, &b, &y2);

        build(rt1[i*2 - 1], rt1[(i-1) * 2], x1+1, a, 0, MAXX+1);
        build(rt1[i*2], rt1[i*2 - 1], x2+1, -a, 0, MAXX+1);

        build(rt2[i*3 - 2], rt2[(i-1) * 3], 0, y1, 0, MAXX+1);
        build(rt2[i*3 - 1], rt2[i*3 - 2], x1+1, b-y1, 0, MAXX+1);
        build(rt2[i*3], rt2[i*3 - 1], x2+1, y2-b, 0, MAXX+1);
    }

    int m;
    scanf("%d", &m);
    LL last = 0;
    for (int i = 1; i <= m; ++i) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        x = (x + last) % MOD;
        if (x > MAXX)
            x = MAXX + 1;

        LL a = query(rt1[(l-1) * 2], rt1[r*2], 0, MAXX+1, x);
        LL b = query(rt2[(l-1) * 3], rt2[r*3], 0, MAXX+1, x);
        last = a*x + b;
        printf(LLD "\n", last);
    }

    return 0;
}

