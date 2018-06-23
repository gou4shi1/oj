/************************************************************************
* File Name : cf913D.cpp
* Purpose : binary answer
* Creation Date : 2018年05月04日
* Last Modified : 2018年05月04日 星期五 17时41分20秒
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

int n, T;

struct Problem {
    int id, a, t;
} p[N], pp[N];

void printP() {
    for (int i = 1; i <= n; ++i) {
        printf("%d: %d %d\n", p[i].id, p[i].a, p[i].t);
    }
}

bool check(int s, bool flag = 0) {
    int i = 1;
    while (i <= n && p[i].a < s)
        ++i;
    if (p[i].a < s)
        return false;
    int nn = n - i + 1;
    if (nn < s)
        return false;
    for (int j = 1; j <= nn; ++j)
        pp[j] = p[i + j - 1];

    sort(pp + 1, pp + 1 + nn, [] (const Problem &lhs, const Problem &rhs) {
            return lhs.t < rhs.t;
            });
    int tt = 0;
    for (int j = 1; j <= nn && j <= s; ++j) {
        tt += pp[j].t;
        if (flag)
            printf("%d ", pp[j].id);
    }

    return tt <= T;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; ++i) {
        p[i].id = i;
        scanf("%d%d", &p[i].a, &p[i].t);
    }

    sort(p + 1, p + 1 + n, [] (const Problem &lhs, const Problem &rhs) {
            return lhs.a < rhs.a;
            });
    //printP();
    
    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m - 1;
    }
    int s = 0;
    if (check(r))
        s = r;
    else
        s = l;
    printf("%d\n%d\n", s, s);
    check(s, true);

    return 0;
}

