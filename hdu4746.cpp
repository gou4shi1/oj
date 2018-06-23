#include <bits/stdc++.h>
using namespace std;

// const
const int N = 5E5 + 10;
const int M = 1E5;
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
#define sqr3(x) ((LL)(x)*(x)*(x))
#define sqr2(x) ((LL)(x)*(x))

bool check[N];
int prime[N], mu[N], g[N];
int f[20][N];
LL fs[20][N];

void moblus() {
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i < N; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
            g[i] = 1;
        }
        for (int j = 0; j<tot && i*prime[j]<N; ++j) {
            check[i * prime[j]] = true;
            g[i * prime[j]] = g[i] + 1;
            if (i % prime[j] == 0)
                break;
            else
                mu[i*prime[j]] = -mu[i];
        }
    }

    for (int d = 1; d < N; ++d)
        for (int k = d; k < N; k += d)
            f[g[d]][k] += mu[k/d];
    for (int p = 1; p < 20; ++p)
        for (int k = 1; k < N; ++k)
            f[p][k] += f[p-1][k];
    for (int p = 0; p < 20; ++p)
        for (int k = 1; k < N; ++k)
            fs[p][k] = fs[p][k-1] + f[p][k];
}

int main() {
    int T;
    scanf("%d", &T);
    moblus();
    while (T--) {
        int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        if (n > m) swap(n, m);
        p = min(p, 19);

        LL ans(0);
        for (int i = 1, last = 1; i <= n; i = last+1) {
            last = min(n / (n/i), m / (m/i));
            ans += (fs[p][last]-fs[p][i-1]) * (n/i) * (m/i);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
