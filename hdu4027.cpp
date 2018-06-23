/************************************************************************
* File Name : hdu4027.cpp
* Purpose : segment tree
* Creation Date : 2017年09月26日
* Last Modified : 2017年09月26日 星期二 10时24分52秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
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

LL sum[MAXN << 2];

//segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

void pushUp(int rt) {
    sum[rt] = sum[lr] + sum[rr];
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf(LLD, &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(ls);
    build(rs);
    pushUp(rt);
}

void update(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R && sum[rt] == (r-l+1))
        return;
    if (l == r) {
        sum[rt] = sqrt(sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, ls);
    if (m < R)
        update(L, R, rs);
    pushUp(rt);
}

LL query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return sum[rt];
    int m = (l + r) >> 1;
    LL ret(0);
    if (L <= m)
        ret += query(L, R, ls);
    if (m < R)
        ret += query(L, R, rs);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, T(0);
    while (scanf("%d", &n) == 1) {
        printf("Case #%d:\n", ++T);

        build(1, n, 1);
        int q;
        scanf("%d", &q);
        while (q--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (b > c)
                swap(b, c);
            if (a)
                printf(LLD "\n", query(b, c, 1, n, 1));
            else
                update(b, c, 1, n, 1);
        }
        printf("\n");
    }

    return 0;
}

