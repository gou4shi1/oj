#include <bits/stdc++.h>
using namespace std;

// const
const int N = 1E4 + 10;
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
#define squ(x) ((LL)(x)*(x))

int t[N], x[N], y[N];

double dis(double x1, double y1, double x2, double y2) {
    return sqrt((double)squ(x1-x2)+squ(y1-y2));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d", &t[i], &x[i], &y[i]);
        double ans(0);
        for (int i = 2; i <= n; ++i)
            ans = max(ans, dis(x[i], y[i], x[i-1], y[i-1]) / (t[i]-t[i-1]));
        printf("%.10f\n", ans);
    }

    return 0;
}
