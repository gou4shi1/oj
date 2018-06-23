/************************************************************************
* File Name : hdu1542.cpp
* Purpose : segment tree
* Creation Date : 2017年10月04日
* Last Modified : 2017年10月04日 星期三 21时44分52秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100 + 10;
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
}seg[MAXN<<1];
int ss;

bool operator < (const Seg &a, const Seg &b) {
    return a.h < b.h;
}

// hase
double x[MAXN<<1];
int xs;
#define _x(y) (lower_bound(x, x+xs, y)-x)

// segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

int cnt[MAXN << 3];
double len[MAXN << 3];

void pushUp(int rt, int l, int r) {
    if (cnt[rt]) {
        len[rt] = x[r+1] - x[l];
    } else if (l == r) {
        len[rt] = 0;
    } else {
        len[rt] = len[lr] + len[rr];
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        cnt[rt] += c;
        pushUp(rt, l, r);
        return ;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, ls);
    if (m < R)
        update(L, R, c, rs);
    pushUp(rt, l, r);
}

void init() {
    xs = ss = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(len, 0, sizeof(len));
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, Ci(0);
    while (~scanf("%d", &n) && n) {
        init();
        for (int i = 1; i <= n; ++i) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seg[ss++] = {y1, x1, x2, -1};
            seg[ss++] = {y2, x1, x2, 1};
            x[xs++] = x1;
            x[xs++] = x2;
        }
        sort(seg, seg+ss);
        sort(x, x+xs);
        xs = unique(x, x+xs) - x;

        double ans = 0;
        for (int i = 0; i < ss; ++i) {
            update(_x(seg[i].l), _x(seg[i].r)-1, seg[i].s, 0, xs-2, 1);
            ans += len[1] * (seg[i+1].h - seg[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++Ci, ans);
    }

    return 0;
}

