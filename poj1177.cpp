/************************************************************************
* File Name : poj1177.cpp
* Purpose : segment tree
* Creation Date : 2017年10月04日
* Last Modified : 2017年10月04日 星期三 21时01分23秒
* Created By : admin@goushi.me
************************************************************************/
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

// const
const int MAXN = 10000 + 10;
const int MAXM = 20000 + 10;
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
    int h, l, r, s;
} seg[MAXN<<1];
int ss;

bool operator < (const Seg &a, const Seg &b) {
    return a.h < b.h;
}


// segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

int cnt[MAXM<<2], lbd[MAXM<<2], rbd[MAXM<<2], len[MAXM<<2], bd[MAXM<<2];

void pushUp(int rt, int l, int r) {
    if (cnt[rt]) {
        lbd[rt] = rbd[rt] = 1;
        bd[rt] = 2;
        len[rt] = r-l+1;
    } else if (l == r) {
        lbd[rt] = rbd[rt] = bd[rt] = len[rt] = 0;
    } else {
        lbd[rt] = lbd[lr];
        rbd[rt] = rbd[rr];
        bd[rt] = bd[lr] + bd[rr];
        len[rt] = len[lr] + len[rr];
        if (rbd[lr] && lbd[rr])
            bd[rt] -= 2;
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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    int x_min = MAXM, x_max = -MAXM;
    for (int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        seg[ss++] = {y1, x1, x2, 1};
        seg[ss++] = {y2, x1, x2, -1};
        x_min = min(x_min, x1);
        x_max = max(x_max, x2);
    }
    sort(seg, seg+ss);
    int ans = 0, last = 0;
    for (int i = 0; i < ss; ++i) {
        update(seg[i].l, seg[i].r-1, seg[i].s, x_min, x_max-1, 1);
        ans += bd[1] * (seg[i+1].h - seg[i].h);
        ans += abs(len[1] - last);
        last = len[1];
    }
    printf("%d\n", ans);
    return 0;
}

