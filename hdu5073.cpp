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

int a[N];
LL s[N], a2[N], s2[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a+1, a+1+n);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i-1]+a[i];
            a2[i] = (LL)a[i]*a[i];
            s2[i] = s2[i-1]+a2[i];
        }
        if (n == k) {
            puts("0");
            continue;
        }
        double ans = 1e100;
        for (int i = 1; i <= k+1; ++i) {
            double v = (double)(s[i+n-k-1]-s[i-1]) / (n-k);
            ans = min(ans, (s2[i+n-k-1]-s2[i-1]) - v*2*(s[i+n-k-1]-s[i-1]) + v*v*(n-k));
        }
        printf("%.10f\n", ans);
    }

    return 0;
}
