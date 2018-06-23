/************************************************************************
* File Name : hdu5112.cpp
* Purpose : water
* Creation Date : 2017年10月14日
* Last Modified : 2017年10月14日 星期六 14时08分57秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100000 + 10;
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

// vector
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))
typedef int itn;

#define maxsize 10000
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int i, j, k, t;
    PII g[maxsize + 1];
    int test;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        int n;
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &g[i].fi, &g[i].se);
        }
        sort(g, g + n);
        double maxv = 0; 
        for (i = 1; i < n; ++i) {
            double dif = (double) (abs(g[i - 1].se - g[i].se));
            double v = dif / (double)(g[i].fi - g[i - 1].fi);
            if (v > maxv) maxv = v;
        }
        printf("Case #%d: ", t);
        printf("%.2lf\n", maxv);
    }


    return 0;
}

