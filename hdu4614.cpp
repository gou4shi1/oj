/************************************************************************
* File Name : hdu4614.cpp
* Purpose : segment tree
* Creation Date : 2017年09月27日
* Last Modified : 2017年09月27日 星期三 23时33分28秒
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
typedef pair<int, pair<int, int> > PIII;
#define mp make_pair
#define fi first
#define se second

//segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

int sum[MAXN << 2], lazy[MAXN << 2], f1[MAXN << 2], l1[MAXN << 2];

void pushUp(int rt) {
    sum[rt] = sum[lr] + sum[rr];

    if (~f1[lr])
        f1[rt] = f1[lr];
    else
        f1[rt] = f1[rr];

    if (~l1[rr])
        l1[rt] = l1[rr];
    else
        l1[rt] = l1[lr];
}

void pushDown(int l, int r, int rt) {
    if (~lazy[rt]) {
        int m = (l + r) >> 1;

        lazy[lr] = lazy[rr] = lazy[rt];

        sum[lr] = lazy[rt] * (m-l+1);
        sum[rr] = lazy[rt] * (r-m);

        if (lazy[rt]) {
            f1[lr] = l;
            l1[lr] = m;
            f1[rr] = m+1;
            l1[rr] = r;
        } else
            f1[lr] = l1[lr] = f1[rr] = l1[rr] = -1;

        lazy[rt] = -1;
    }
}

void build(int l, int r, int rt) {
    if (l == r) {
        sum[rt] = 1;
        f1[rt] = l1[rt] = l;
        return;
    }
    int m = (l + r) >> 1;
    build(ls);
    build(rs);
    pushUp(rt);
}

PIII query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return mp(sum[rt], mp(f1[rt], l1[rt]));
    pushDown(l, r, rt);
    int m = (l + r) >> 1;
    PIII ret = mp(0, mp(-1, -1));
    if (L <= m)
        ret = query(L, R, ls);
    if (m < R) {
        PIII t = query(L, R, rs);
        ret.fi += t.fi;
        if (ret.se.fi == -1)
            ret.se.fi = t.se.fi;
        if (~t.se.se)
            ret.se.se = t.se.se;
    }
    return ret;
}

int update1(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        lazy[rt] = c;
        int ret = (r-l+1) - sum[rt];
        sum[rt] = c * (r-l+1);
        if (c) {
            f1[rt] = l;
            l1[rt] = r;
        } else
            f1[rt] = l1[rt] = -1;
        return ret;
    }
    pushDown(l, r, rt);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m)
        ret += update1(L, R, c, ls);
    if (m < R)
        ret += update1(L, R, c, rs);
    pushUp(rt);
    return ret;
}

PII update2(int p, int c, int l, int r, int rt) {
    if (l == r) {
        if (sum[rt]) {
            sum[rt] = 0;
            f1[rt] = l1[rt] = -1;
            return PII(l, r);
        } else
            return PII(-1, -1);
    }
    pushDown(l, r, rt);
    int m = (l + r) >> 1;
    PII ret = mp(-1, -1);
    if (p <= m) {
        PIII t = query(p, m, ls);
        if (t.fi >= c) {
            ret = update2(p, c, ls);
        } else {
            if (t.fi > 0) {
                c -= t.fi;
                ret = t.se;
                update1(p, m, 0, ls);
            }
            PII tt = update2(p, c, rs);
            if (ret.fi == -1)
                ret.fi = tt.fi;
            if (~tt.se)
                ret.se = tt.se;
        }
    } else {
        ret = update2(p, c, rs);
    }
    pushUp(rt);
    return ret;
}

void init() {
    memset(lazy, -1, sizeof(lazy));
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        build(0, n-1, 1);
        while (m--) {
            int t, a, b;
            scanf("%d%d%d", &t, &a, &b);
            if (t == 1) {
                PIII ret = query(a, n-1, 0, n-1, 1);
                if (ret.fi == 0)
                    puts("Can not put any one.");
                else {
                    PII t = update2(a, b, 0, n-1, 1);
                    printf("%d %d\n", t.fi, t.se);
                }
            } else
                printf("%d\n", update1(a, b, 1, 0, n-1, 1));
        }
        printf("\n");
    }

    return 0;
}

