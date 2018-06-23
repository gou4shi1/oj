/************************************************************************
* File Name : hdu1255.cpp
* Purpose : segment tree
* Creation Date : 2017年10月04日
* Last Modified : 2017年10月04日 星期三 23时35分49秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 1000 + 10;
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

// segment
struct Seg {
    double h, l, r;
    int s;
}seg[MAXN*2];
int ss;

bool operator < (const Seg &a, const Seg &b) {
    return a.h < b.h;
}

// hash
double x[MAXN*2];
int xs;
#define _x(y) (lower_bound(x, x+xs, y)-x)

// segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

int cnt[MAXN*8];
double len1[MAXN*8], len2[MAXN*8];

void pushUp(int l, int r, int rt) {
    if (cnt[rt] >= 2) {
        len2[rt] = x[r+1] - x[l];
        len1[rt] = x[r+1] - x[l];
    } else if (cnt[rt] == 1) {
        len1[rt] = x[r+1] - x[l];
        len2[rt] = len1[lr] + len1[rr];
    } else if (l == r) {
        len1[rt] = len2[rt] = 0;
    } else {
        len1[rt] = len1[lr] + len1[rr];
        len2[rt] = len2[lr] + len2[rr];
    }
}

/*
void pushDown(int l, int r, int rt) {
    if (lazy[rt]) {
        lazy[lr] += lazy[rt];
        lazy[rr] += lazy[rt];
        cnt[lr] += lazy[rt];
        cnt[rr] += lazy[rt];
        int m = (l + r) >> 1;
        pushUp(ls);
        pushUp(rs);
        lazy[rt] = 0;
    }
}
*/

void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        cnt[rt] += c;
        pushUp(l, r, rt);
        return ;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, ls);
    if (m < R)
        update(L, R, c, rs);
    pushUp(l, r, rt);
}

void init() {
    ss = xs = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(len1, 0, sizeof(len1));
    memset(len2, 0, sizeof(len2));
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    for (int Ti = 1; Ti <= T; ++Ti) {
        init();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seg[ss++] = {y1, x1, x2, 1};
            seg[ss++] = {y2, x1, x2, -1};
            x[xs++] = x1;
            x[xs++] = x2;
        }
        sort(seg, seg+ss);
        sort(x, x+xs);
        xs = unique(x, x+xs) - x;

        double ans = 0;
        for (int i = 0; i < ss; ++i) {
            update(_x(seg[i].l), _x(seg[i].r)-1, seg[i].s, 0, xs-2, 1);
            ans += len2[1] * (seg[i+1].h - seg[i].h);
        }
        printf("%.2lf\n", ans+0.00001);
    }

    return 0;
}

