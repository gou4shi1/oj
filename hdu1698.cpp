/************************************************************************
* File Name : hdu1698.cpp
* Purpose : segment tree
* Creation Date : 2017年09月26日
* Last Modified : 2017年09月26日 星期二 01时28分59秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;
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

int sum[MAXN << 2], lazy[MAXN << 2];

#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

void pushUp(int rt) {
    sum[rt] = sum[lr] + sum[rr];
}

void pushDown(int rt, int l) {
    if (lazy[rt]) {
        lazy[lr] = lazy[rr] = lazy[rt];
        sum[lr] = lazy[rt] * (l - (l>>1));
        sum[rr] = lazy[rt] * (l >> 1);
        lazy[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    if (l == r) {
        sum[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(ls);
    build(rs);
    pushUp(rt);
}

void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        sum[rt] = c * (r-l+1);
        lazy[rt] = c;
        return;
    }
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, ls);
    if (m < R)
        update(L, R, c, rs);
    pushUp(rt);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    for (int Ti = 1; Ti <= T; ++Ti) {
        memset(lazy, 0, sizeof(lazy));
        printf("Case %d: The total value of the hook is ", Ti);
        int n, m;
        scanf("%d%d", &n, &m);
        build(1, n, 1);
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        }
        printf("%d.\n", sum[1]);
    }

    return 0;
}

