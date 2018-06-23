/************************************************************************
* File Name : poj3468_2.cpp
* Purpose : segment tree
* Creation Date : 2017年09月25日
* Last Modified : 2017年09月25日 星期一 20时39分15秒
* Created By : admin@goushi.me
************************************************************************/
#include <cstdio>
#include <algorithm>

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

//segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

LL sum[MAXN << 2], lazy[MAXN << 2];

void pushUp(int rt) {
    sum[rt] = sum[lr] + sum[rr];
}

void pushDown(int rt, int l) {
    if (lazy[rt]) {
        lazy[lr] += lazy[rt];
        lazy[rr] += lazy[rt];
        sum[lr] += lazy[rt] * (l - (l>>1));
        sum[rr] += lazy[rt] * (l>>1);
        lazy[rt] = 0;
    }
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

void update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        sum[rt] += (LL)x * (r-l+1);
        lazy[rt] += x;
        return;
    }
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, x, ls);
    if (m < R)
        update(L, R, x, rs);
    pushUp(rt);
}

LL query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return sum[rt];
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    LL ret = 0;
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

    int n, m;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    while (m--) {
        char op[23];
        scanf("%s", op);
        if (op[0] == 'C') {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            printf(LLD "\n", query(a, b, 1, n, 1));
        }
    }

    return 0;
}

