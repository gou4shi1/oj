#include <bits/stdc++.h>
using namespace std;

// const
const int N = 1E5 + 10;
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

int a[N], c[N];
LL f[N];

int main() {
    int T;
    scanf("%d", &T);
    moblus();
    while (T--) {
        mst(c, 0);
        mst(f, 0);

        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            ++c[a[i]];
        }
        for (int i = 1; i < N; ++i) {
            if (!mu[i]) continue;
            int t = 0;
            for (int j = i; j < N; j += i)
                t += c[j];
            t *= mu[i];
            for (int j = i; j < N; j += i)
                f[j] += t;
        }
        LL s(0);
        f[1] = 0;
        for (int i = 1; i <= n; ++i)
            s += f[a[i]] * (n-1-f[a[i]]);
        s = (LL)n*(n-1)*(n-2)/6 - s/2;
        printf("%lld\n", s);
    }

    return 0;
}
