#include <bits/stdc++.h>
using namespace std;

// const
const int N = 6E4 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
const int MOD = 1E9 + 7;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define lld I64d
#endif

// vector
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))

int n, a[N], last[N];

// segment tree
#define lr rt*2
#define rr rt*2 + 1 
#define ls l, m, lr
#define rs m+1, r, rr

double m[N*4], lazy[N*4];

void pushDown(int rt) {
    if (lazy[rt]) {
        lazy[lr] += lazy[rt];
        lazy[rr] += lazy[rt];
        m[lr] += lazy[rt];
        m[rr] += lazy[rt];
        lazy[rt] = 0;
    }
}

void pushUp(int rt) {
    m[rt] = min(m[lr], m[rr]);
}

void update(int l, int r, int rt, int L, int R, double c) {
    if (L <= l && r <= R) {
        m[rt] += c;
        lazy[rt] += c;
        return ;
    }
    pushDown(rt);
    int m = (l + r) / 2;
    if (L <= m)
        update(ls, L, R, c);
    if (m < R)
        update(rs, L, R, c);
    pushUp(rt);
}

double query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R)
        return m[rt];
    int m = (l + r) / 2;
    pushDown(rt);
    double ret = INF;
    if (L <= m)
        ret = min(ret, query(ls, L, R));
    if (m < R)
        ret = min(ret, query(rs, L, R));
    return ret;
}

bool check(double x) {
    //printf("%.5f\n", x);
    mst(m, 0);
    mst(lazy, 0);
    mst(last, 0);
    for (int i = 1; i <= n; ++i) {
        update(1, n, 1, i, i, x*i);
        update(1, n, 1, last[a[i]]+1, i, 1);
        last[a[i]] = i;
        if (query(1, n, 1, 1, i) < x * (i+1))
            return true;
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);

        double l = 0, r = 1;
        while (r-l > 1E-4) {
            double m = (l + r) / 2;
            if (check(m))
                r = m;
            else
                l = m;
        }
        printf("%.5f\n", l);
    }

    return 0;
}
