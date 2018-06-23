#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

// const
const int N = 1E7 + 10;
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
#define sqr2(x) ((LL)(x)*(x))

bool check[N];
int prime[N], mu[N], f[N], tot;
LL fs[N];

void moblus() {
    mu[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
            f[i] = 1;
        }
        for (int j = 0; j<tot && i*prime[j]<N; ++j) {
            check[i*prime[j]] = true;
            if (i % prime[j] == 0) {
                f[i*prime[j]] = mu[i];
                break;
            } else {
                mu[i*prime[j]] = -mu[i];
                f[i*prime[j]] = mu[i] - f[i];
            }
        }
    }
    for (int i = 1; i < N; ++i)
        fs[i] = fs[i-1] + f[i];
}

int main() {
    moblus();

    int n;
    scanf("%d", &n);

    LL ans = 0;
    for (int i = 1, last = 1; i <= n; i = last+1) {
        last = n / (n/i);
        ans += (LL)(fs[last]-fs[i-1]) * sqr2(n/i);
    }
    printf("%lld\n", ans);

    return 0;
}
