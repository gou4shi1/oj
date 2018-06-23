/************************************************************************
* File Name : stadord.cpp
* Purpose : standord procedure for Titan
* Creation Date : 2018年04月07日
* Last Modified : 2018年04月08日 星期日 18时37分32秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 200000 + 10;
const int INF = 0x3f3f3f3f;
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

struct Point {
    int x, p;
}a[N];
bool operator < (const Point &lhs, const Point &rhs) {
    return lhs.x < rhs.x;
}

int nxt[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int d, V, n;
    scanf("%d%d%d", &d, &V, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].p);
    sort(a+1, a+1+n);

    deque<int> q;
    for (int i = n; i >= 1; --i) {
        while (!q.empty() && a[q.front()].p >= a[i].p)
            q.pop_front();
        if (!q.empty())
            nxt[i] = q.front();
        q.push_front(i);
    }

    int v = V;
    LL c = 0;
    for (int i = 1; i <= n; ++i) {
        v -= a[i].x - a[i - 1].x;
        if (v < 0) {
            printf("-1\n");
            return 0;
        }
        
        int _V = min(V, d - a[i].x);
        if (!nxt[i]) {
            c += (LL)(_V - v) * a[i].p;
            v += _V - v;
        } else if (a[nxt[i]].x - a[i].x <= v) {
            // go straght ahead
        } else if (a[nxt[i]].x - a[i].x <= _V) {
            c += (LL)(a[nxt[i]].x - a[i].x - v) * a[i].p;
            v += a[nxt[i]].x - a[i].x - v;
        } else {
            c += (LL)(_V - v) * a[i].p;
            v += _V - v;
        }
    }

    if (d - a[n].x > v) {
        printf("-1\n");
    } else {
        printf("%lld\n", c);
    }

    return 0;
}

