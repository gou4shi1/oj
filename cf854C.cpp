/************************************************************************
* File Name : cf854C.cpp
* Purpose : greedy
* Creation Date : 2017年09月08日
* Last Modified : 2017年09月09日 星期六 00时10分36秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 600000 + 10;
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

PII a[MAXN];
FLAG f;
ARRAY nxt, b;

int n, k;

int fn(int p) {
    if (p > n+k)
        return -1;

    if (!f[nxt[p]])
        return nxt[p];
    return nxt[p] = fn(nxt[p]);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        a[i].fi = -t;
        a[i].se = i;
    }

    sort(a+1, a+1+n);

    for (int i = k+1; i <= k+n; ++i)
        nxt[i] = i + 1;

    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = a[i].se <= k ? k+1 : a[i].se;
        if (f[t])
            t = fn(t);
        f[t] = true;
        b[a[i].se] = t;
        ans += (LL)(t-a[i].se) * (-a[i].fi);
    }

    printf(LLD "\n", ans);
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}

