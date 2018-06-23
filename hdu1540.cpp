/************************************************************************
* File Name : hdu1540.cpp
* Purpose : segment tree
* Creation Date : 2017年09月26日
* Last Modified : 2017年09月27日 星期三 02时14分41秒
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

int lc[MAXN << 2], rc[MAXN << 2], mc[MAXN << 2];

// segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

void pushUp(int rt, int l) {
    lc[rt] = lc[lr];
    rc[rt] = rc[rr];
    if (lc[rt] == (l-(l>>1)))
        lc[rt] += lc[rr];
    if (rc[rt] == (l>>1))
        rc[rt] += rc[lr];
    mc[rt] = max(mc[lr], mc[rr]);
    mc[rt] = max(mc[rt], rc[lr]+lc[rr]);
}

void build(int l, int r, int rt) {
    lc[rt] = rc[rt] = mc[rt] = 0;
    if (l == r) {
        lc[rt] = rc[rt] = mc[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(ls);
    build(rs);
    pushUp(rt, r-l+1);
}

void update(int p, int c, int l, int r, int rt) {
    if (l == r) {
        lc[rt] = rc[rt] = mc[rt] = c;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, c, ls);
    else
        update(p, c, rs);
    pushUp(rt, r-l+1);
}

PII query(int p, int l, int r, int rt) {
    if (l == r)
        return PII(mc[rt], mc[rt]);
    int m = (l + r) >> 1;
    PII ret;
    if (p <= m) {
        ret = query(p, ls);
        if (ret.se == (m-p+1))
            ret.se += lc[rr];
    } else {
        ret = query(p, rs);
        if (ret.fi == (p-m))
            ret.fi += rc[lr];
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        build(1, n, 1);
        stack<int> la;
        for (int i = 1; i <= m; ++i) {
            char op[23];
            scanf("%s", op);
            if (op[0] == 'D') {
                int x;
                scanf("%d", &x);
                update(x, 0, 1, n, 1);
                la.push(x);
            } else if (op[0] == 'Q') {
                int x;
                scanf("%d", &x);
                PII ret = query(x, 1, n, 1);
                int ans = ret.fi + ret.se;
                if (ans)
                    --ans;
                printf("%d\n", ans);
            } else {
                update(la.top(), 1, 1, n, 1);
                la.pop();
            }
        }
    }

    return 0;
}

