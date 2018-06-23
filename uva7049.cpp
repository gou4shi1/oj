#include <bits/stdc++.h>
using namespace std;

// const
const int N = 1E5 + 10;
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

int x[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        LL xs(0);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x[i]);
            xs += x[i];
        }
        sort(x+1, x+1+n);
        int l = 1, r = n;
        for (int i = 1; i <= k; ++i) {
            double xx = (double)xs / (n-i+1);
            if (fabs(xx-x[l]) > fabs(xx-x[r]))
                xs -= x[l++];
            else
                xs -= x[r--];
            printf("(%d,%d)\n", l, r);
        }
        double xx = (double)xs / (r-l+1);
        double ans = 0;
        for (int i = l; i <= r; ++i)
            ans += (xx-x[i])*(xx-x[i]);
        printf("%.10f\n", ans);
    }

    return 0;
}
