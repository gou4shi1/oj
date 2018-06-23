/************************************************************************
* File Name : hdu1166.cpp
* Purpose : segment-tree
* Creation Date : 2017年09月24日
* Last Modified : 2017年09月24日 星期日 22时37分43秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 50000 + 10;
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

//segment tree
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

int sum[MAXN << 2];

void pushUp(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int p, int a, int l, int r, int rt) {
    if (l == r) {
        sum[rt] += a;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, a, lson);
    else
        update(p, a, rson);
    pushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return sum[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m)
        ret += query(L, R, lson);
    if (m < R)
        ret += query(L, R, rson);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    for (int Ti = 1; Ti <= T; ++Ti) {
        printf("Case %d:\n", Ti);
        int n;
        scanf("%d", &n);
        build(1, n, 1);
        char op[233];
        while (scanf("%s", op) == 1) {
            if (op[0] == 'E')
                break;
            int a, b;
            scanf("%d%d", &a, &b);
            if (op[0] == 'Q')
                printf("%d\n", query(a, b, 1, n, 1));
            else if (op[0] == 'A')
                update(a, b, 1, n, 1);
            else
                update(a, -b, 1, n, 1);
        }
    }

    return 0;
}

