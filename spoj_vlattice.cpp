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
#define sqr3(x) ((LL)(x)*(x)*(x))
#define sqr2(x) ((LL)(x)*(x))

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

int main() {
    int T;
    scanf("%d", &T);
    moblus();
    while (T--) {
        int n;
        scanf("%d", &n);

        LL ans3(0), ans2(0);
        for (int i = 1, last = 1; i <= n; i = last+1) {
            last = n / (n/i);
            ans3 += (LL)(s[last]-s[i-1]) * sqr3(n/i);
            ans2 += (LL)(s[last]-s[i-1]) * sqr2(n/i);
        }

        printf("%lld\n", ans3 + 3*ans2 + 3);
    }

    return 0;
}
