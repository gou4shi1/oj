#include <bits/stdc++.h>
using namespace std;

// const
const int N = 3E5 + 10;
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

LL pow_m(LL a, LL n) {
    LL ret = 1, tmp = a % MOD;
    while (n) {
        if (n & 1)
            ret = ret * tmp % MOD;
        tmp = tmp * tmp % MOD;
        n >>= 1;
    }
    return ret;
}

LL fac[N], inv_fac[N];

LL _inv(LL a) {
    return pow_m(a, MOD-2);
}

LL C(LL n, LL m) {
    if (!m) return 1;
    return fac[n]*inv_fac[m]%MOD*inv_fac[n-m]%MOD; 
}

bool check[N];
int prime[N], mu[N];

void moblus() {
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i < N; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j<tot && i*prime[j]<N; ++j) {
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
            else
                mu[i*prime[j]] = -mu[i];
        }
    }
}

void init() {
    moblus();

    fac[0] = 1;
    inv_fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i-1] * i % MOD;
        inv_fac[i] = _inv(fac[i]);
    }

}

int a[N], c[N], g[N];

int main() {
    init();
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        mst(c, 0);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            c[a[i]]++;
        }
        
        mst(g, 0);
        for (int i = 1; i <= m; ++i)
            for (int j = i; j <= m; j += i)
                g[i] += c[j];

        for (int d = 1; d <= m; ++d) {
            LL ans = 0;
            for (int i = d; i <= m; i += d) {
                if (mu[i/d] == 0 || g[i] < (n-k))
                    continue;
                LL t = mu[i/d];
                t = t * C(g[i], n-k) % MOD;
                t = t * pow_m(m/i-1, g[i]-n+k) % MOD;
                t = t * pow_m(m/i, n-g[i]) % MOD;
                ans = (ans + t + MOD) % MOD;
            }
            printf("%lld", ans);
            if (d < m) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
