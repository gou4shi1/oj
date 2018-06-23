/************************************************************************
* File Name : hdu3642.cpp
* Purpose : segment tree
* Creation Date : 2017年10月05日
* Last Modified : 2017年10月05日 星期四 16时32分05秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 1000 + 10;
const int MAXZ = 500 + 10;
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
    int y, l, r, s;
}seg[MAXZ*2][MAXN*2];
int ss[MAXZ*2];

bool operator < (const Seg &a, const Seg &b) {
    return a.y < b.y;
}

// hash
int x[MAXN*2];
int xs;
#define _x(y) (lower_bound(x, x+xs, y)-x)

// segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

int cnt[MAXN*16], len1[MAXN*16], len2[MAXN*16], len3[MAXN*16];

void pushUp(int rt, int l, int r) {
    if (cnt[rt] >= 3) {
        len3[rt] = len2[rt] = len1[rt] = x[r+1] - x[l];
    } else if (cnt[rt] == 2) {
        len3[rt] = len1[lr] + len1[rr];
        len2[rt] = len1[rt] = x[r+1] - x[l];
    } else if (cnt[rt] == 1) {
        len3[rt] = len2[lr] + len2[rr];
        len2[rt] = len1[lr] + len1[rr];
        len1[rt] = x[r+1] - x[l];
    } else {
        len3[rt] = len3[lr] + len3[rr];
        len2[rt] = len2[lr] + len2[rr];
        len1[rt] = len1[lr] + len1[rr];
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
    xs = 0;
    memset(ss, 0, sizeof(ss));
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T, Case(0);
    scanf("%d", &T);
    while (T--) {
        init();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int x1, y1, z1, x2, y2, z2;
            scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
            x[xs++] = x1;
            x[xs++] = x2;
            z1 += MAXZ;
            z2 += MAXZ;
            for (int j = z1; j < z2; ++j) {
                seg[j][ss[j]++] = {y1, x1, x2, 1};
                seg[j][ss[j]++] = {y2, x1, x2, -1};
            }
        }
        sort(x, x+xs);
        xs = unique(x, x+xs) - x;

        LL ans = 0;
        for (int i = 0; i < MAXZ*2; ++i) {
            sort(seg[i], seg[i]+ss[i]);

            memset(cnt, 0, sizeof(cnt));
            memset(len1, 0, sizeof(len1));
            memset(len2, 0, sizeof(len2));
            memset(len3, 0, sizeof(len3));

            for (int j = 0; j < ss[i]; ++j) {
                update(_x(seg[i][j].l), _x(seg[i][j].r)-1, seg[i][j].s, 0, xs-2, 1);
                ans += (LL)len3[1] * (seg[i][j+1].y - seg[i][j].y);
            }
        }
        printf("Case %d: " LLD "\n", ++Case, ans);
    }

    return 0;
}
