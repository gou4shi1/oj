/************************************************************************
* File Name : hdu1754.cpp
* Purpose : segment tree
* Creation Date : 2017年09月25日
* Last Modified : 2017年09月25日 星期一 19时34分42秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 200000 + 10;
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

// segment tree
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1

int _max[MAXN << 2];

void pushUp(int rt) {
    _max[rt] = max(_max[rt<<1], _max[rt<<1|1]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &_max[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int p, int x, int l, int r, int rt) {
    if (l == r) {
        _max[rt] = x;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, x, lson);
    else
        update(p, x, rson);
    pushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return _max[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m)
        ret = max(ret, query(L, R, lson));
    if (m < R)
        ret = max(ret, query(L, R, rson));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        build(1, n, 1);
        for (int i = 1; i <= m; ++i) {
            char op[233];
            int a, b;
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'U')
                update(a, b, 1, n, 1);
            else
                printf("%d\n", query(a, b, 1, n, 1));
        }
    }

    return 0;
}

