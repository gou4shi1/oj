/************************************************************************
* File Name : cf961D.cpp
* Purpose : computational geometry
* Creation Date : 2018年05月05日
* Last Modified : 2018年05月05日 星期六 19时35分49秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100000 + 10;
const long long INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
const int MOD = 1000000000 + 7;
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

PII p[N], pp[N];

LL xmult(PII p1, PII p2, PII p0) {
    return (LL)(p1.fi-p0.fi)*(p2.se-p0.se) - (LL)(p2.fi-p0.fi)*(p1.se-p0.se);
}

bool oneline(PII p1, PII p2, PII p3) {
    return !xmult(p1, p2, p3);
}

bool oneline(PII *p, int n) {
    for (int i = 0; i < n; ++i)
        if (!oneline(p[0], p[1], p[i]))
            return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &p[i].fi, &p[i].se);

    if (n <= 4) {
        puts("YES");
        return 0;
    }

    const int T[3][2] = {{1, 2}, {1, 3}, {2, 3}};
    for (int t = 0; t < 3; ++t) {
        PII p1 = p[T[t][0]], p2 = p[T[t][1]];
        int nn = 0;
        for (int i = 0; i < n; ++i) 
            if (!oneline(p1, p2, p[i]))
                pp[nn++] = p[i];
        if (oneline(pp, nn)) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");

    return 0;
}

