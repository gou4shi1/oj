#include <bits/stdc++.h>
using namespace std;

// const
const int N = 1E6 + 10;
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

bool check[N];
int prime[N], mu[N], s[N];

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

    for (int i = 1; i < N; ++i)
        s[i] = s[i-1] + mu[i];
}

LL F(int n, int m, int d) {
    if (n > m) swap(n, m);
    LL ans = 0;
    n /= d, m /= d;
    for (int i = 1, last = 1; i <= n; i = last + 1) {
        last = min(n / (n / i), m / (m / i));
        ans += (LL)(s[last] - s[i - 1]) * (n / i) * (m / i);
    } 
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    moblus();
    while (T--) {
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        printf("%lld\n", F(b, d, k)-F(b, c-1, k)-F(a-1, d, k)+F(a-1, c-1, k));
    }

    return 0;
}
