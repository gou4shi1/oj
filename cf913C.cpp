/************************************************************************
* File Name : cf913C.cpp
* Purpose : dp
* Creation Date : 2018年05月04日
* Last Modified : 2018年05月04日 星期五 21时07分57秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 233 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
const int MOD = 1000000000 + 7;
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

LL a[N], c[N], c_m[N], dp[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, L;
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &c[i]);
    }

    int k = 0;
    while (L) {
        a[++k] = L % 2;
        L /= 2;
    }
    n = max(n, k) + 1;

    for (int i = 2; i <= n; ++i)
        c[i] = c[i] ? min(c[i], 2 * c[i - 1]) : 2 * c[i - 1];

    c_m[n] = c[n];
    for (int i = n - 1; i >= 1; --i)
        c_m[i] = min(c[i], c_m[i + 1]);

    for (int i = 1; i <= k; ++i) {
        if (a[i] == 0) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = min(dp[i - 1] + c[i], c_m[i + 1]);
        }
    }

    /*
    puts("#############");
    for (int i = 1; i <= k; ++i)
        printf("%lld ", dp[i]);
    printf("\n");
    puts("#############");
    */

    printf("%lld\n", dp[k]);

    return 0;
}

