/************************************************************************
* File Name : poj3264.cpp
* Purpose : segment tree
* Creation Date : 2017年09月26日
* Last Modified : 2017年09月26日 星期二 01时55分32秒
* Created By : admin@goushi.me
************************************************************************/
#include <cstdio>
#include <algorithm>
#include <utility>

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

int _max[MAXN << 2], _min[MAXN << 2];

// segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

void pushUp(int rt) {
    _max[rt] = max(_max[lr], _max[rr]);
    _min[rt] = min(_min[lr], _min[rr]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &_max[rt]);
        _min[rt] = _max[rt];
        return;
    }
    int m = (l + r) >> 1;
    build(ls);
    build(rs);
    pushUp(rt);
}

PII query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return PII(_max[rt], _min[rt]);
    int m = (l + r) >> 1;
    PII ret(_INF, INF);
    if (L <= m) {
        PII t = query(L, R, ls);
        ret.fi = max(ret.fi, t.fi);
        ret.se = min(ret.se, t.se);
    }
    if (m < R) {
        PII t = query(L, R, rs);
        ret.fi = max(ret.fi, t.fi);
        ret.se = min(ret.se, t.se);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        build(1, n, 1);
        while (q--) {
            int a, b;
            scanf("%d%d", &a, &b);
            PII t = query(a, b, 1, n, 1);
            printf("%d\n", t.fi-t.se);
        }
    }

    return 0;
}

