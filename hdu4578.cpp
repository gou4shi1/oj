/************************************************************************
* File Name : hdu4578.cpp
* Purpose : segment tree
* Creation Date : 2017年09月28日
* Last Modified : 2017年10月04日 星期三 17时20分19秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
const int MOD = 10007;
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
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

LL sum[4][MAXN << 2], lazy1[MAXN << 2], lazy2[MAXN << 2], lazy3[MAXN << 2];

void pushUp(int rt) {
    sum[1][rt] = (sum[1][lr] + sum[1][rr]) % MOD;
    sum[2][rt] = (sum[2][lr] + sum[2][rr]) % MOD;
    sum[3][rt] = (sum[3][lr] + sum[3][rr]) % MOD;
}

void pushDown(int rt, int l) {
    LL sum1, sum2;
    if (lazy3[rt] > 0) {
        lazy3[lr] = lazy3[rr] = lazy3[rt];
        lazy2[lr] = lazy2[rr] = 1;
        lazy1[lr] = lazy1[rr] = 0;
        sum[1][lr] = lazy3[rt] * (l-(l>>1));
        sum[2][lr] = (lazy3[rt]*lazy3[rt])%MOD * (l-(l>>1));
        sum[3][lr] = (lazy3[rt]*lazy3[rt]*lazy3[rt])%MOD * (l-(l>>1));
        sum[1][lr] %= MOD;
        sum[2][lr] %= MOD;
        sum[3][lr] %= MOD;
        sum[1][rr] = lazy3[rt] * (l>>1);
        sum[2][rr] = (lazy3[rt]*lazy3[rt])%MOD * (l>>1);
        sum[3][rr] = (lazy3[rt]*lazy3[rt]*lazy3[rt])%MOD * (l>>1);
        sum[1][rr] %= MOD;
        sum[2][rr] %= MOD;
        sum[3][rr] %= MOD;
        lazy3[rt] = 0;
    }
    if (lazy2[rt] > 1) {
        lazy2[lr] = lazy2[lr] * lazy2[rt] % MOD;
        lazy2[rr] = lazy2[rr] * lazy2[rt] % MOD;
        lazy1[lr] = lazy1[lr] * lazy2[rt] % MOD;
        lazy1[rr] = lazy1[rr] * lazy2[rt] % MOD;
        sum[1][lr] *= lazy2[rt];
        sum[2][lr] *= (lazy2[rt]*lazy2[rt])%MOD;
        sum[3][lr] *= (lazy2[rt]*lazy2[rt]*lazy2[rt])%MOD;
        sum[1][lr] %= MOD;
        sum[2][lr] %= MOD;
        sum[3][lr] %= MOD;
        sum[1][rr] *= lazy2[rt];
        sum[2][rr] *= (lazy2[rt]*lazy2[rt])%MOD;
        sum[3][rr] *= (lazy2[rt]*lazy2[rt]*lazy2[rt])%MOD;
        sum[1][rr] %= MOD;
        sum[2][rr] %= MOD;
        sum[3][rr] %= MOD;
        lazy2[rt] = 1;
    }
    if (lazy1[rt]) {
        lazy1[lr] = (lazy1[lr] + lazy1[rt]) % MOD;
        lazy1[rr] = (lazy1[rr] + lazy1[rt]) % MOD;
        sum1 = sum[1][lr];
        sum2 = sum[2][lr];
        sum[1][lr] += lazy1[rt] * (l-(l>>1));
        sum[2][lr] += (lazy1[rt]*lazy1[rt])%MOD * (l-(l>>1)) + sum1* 2 * lazy1[rt];
        sum[3][lr] += (lazy1[rt]*lazy1[rt]*lazy1[rt])%MOD * (l-(l>>1)) + sum2* 3 * lazy1[rt] + sum1 * 3 * (lazy1[rt]*lazy1[rt])%MOD;
        sum[1][lr] %= MOD;
        sum[2][lr] %= MOD;
        sum[3][lr] %= MOD;
        sum1 = sum[1][rr];
        sum2 = sum[2][rr];
        sum[1][rr] += lazy1[rt] * (l>>1);
        sum[2][rr] += (lazy1[rt]*lazy1[rt])%MOD * (l>>1) + sum1 * 2 * lazy1[rt];
        sum[3][rr] += (lazy1[rt]*lazy1[rt]*lazy1[rt])%MOD * (l>>1) + sum2 * 3 * lazy1[rt] + sum1 * 3 * (lazy1[rt]*lazy1[rt])%MOD;
        sum[1][rr] %= MOD;
        sum[2][rr] %= MOD;
        sum[3][rr] %= MOD;
        lazy1[rt] = 0;
    }
}

void update1(int L, int R, LL c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        LL sum1 = sum[1][rt], sum2 = sum[2][rt];
        sum[1][rt] += c * (r-l+1);
        sum[2][rt] += (c*c)%MOD * (r-l+1) + sum1 * 2 * c;
        sum[3][rt] += (c*c*c)%MOD * (r-l+1) + sum2 * 3 * c + sum1 * 3 * c * c;
        sum[1][rt] %= MOD;
        sum[2][rt] %= MOD;
        sum[3][rt] %= MOD;
        lazy1[rt] = (lazy1[rt] + c) % MOD;
        return ;
    }
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m)
        update1(L, R, c, ls);
    if (m < R)
        update1(L, R, c, rs);
    pushUp(rt);
}

void update2(int L, int R, LL c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        sum[1][rt] *= c;
        sum[2][rt] *= (c*c)%MOD;
        sum[3][rt] *= (c*c*c)%MOD;
        sum[1][rt] %= MOD;
        sum[2][rt] %= MOD;
        sum[3][rt] %= MOD;
        lazy2[rt] = (lazy2[rt] * c) % MOD;
        lazy1[rt] = (lazy1[rt] * c) % MOD;
        return ;
    }
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m)
        update2(L, R, c, ls);
    if (m < R)
        update2(L, R, c, rs);
    pushUp(rt);
}

void update3(int L, int R, LL c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        sum[1][rt] = c * (r-l+1);
        sum[2][rt] = (c*c)%MOD * (r-l+1);
        sum[3][rt] = (c*c*c)%MOD * (r-l+1);
        sum[1][rt] %= MOD;
        sum[2][rt] %= MOD;
        sum[3][rt] %= MOD;
        lazy3[rt] = c;
        lazy1[rt] = 0;
        lazy2[rt] = 1;
        return ;
    }
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m)
        update3(L, R, c, ls);
    if (m < R)
        update3(L, R, c, rs);
    pushUp(rt);
}

int query(int L, int R, int p, int l, int r, int rt) {
    if (L <= l && r <= R)
        return sum[p][rt];
    pushDown(rt, r-l+1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m)
        ret += query(L, R, p, ls);
    if (m < R)
        ret += query(L, R, p, rs);
    return ret % MOD;
}

void init() {
    memset(sum, 0, sizeof(sum));
    memset(lazy1, 0, sizeof(lazy1));
    for (int i = 0; i < MAXN<<2; ++i)
        lazy2[i] = 1;
    memset(lazy3, 0, sizeof(lazy3));
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    while (~scanf("%d%d", &n, &m) && n) {
        init();
        while (m--) {
            int t, x, y, c;
            scanf("%d%d%d%d", &t, &x, &y, &c);
            c %= MOD;
            if (t == 1)
                update1(x, y, c, 1, n, 1);
            else if (t == 2)
                update2(x, y, c, 1, n, 1);
            else if (t == 3)
                update3(x, y, c, 1, n, 1);
            else
                printf("%d\n", query(x, y, c, 1, n, 1));
        }
    }

    return 0;
}

