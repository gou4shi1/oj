/************************************************************************
* File Name : cf837D.cpp
* Purpose : dp
* Creation Date : 2017年08月14日
* Last Modified : 2017年08月14日 星期一 17时46分23秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 200 + 10;
const int MAXM = 20000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

// array
typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

LL a[MAXN];
ARRAY t, f, _f;
int dp[2][MAXN][MAXM];
bool dq[2][MAXN][MAXM];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf(LLD, &a[i]);

    for (int i = 1; i <= n; ++i) {
        while (a[i] % 2 == 0) {
            ++t[i];
            a[i] /= 2;
        }
        while (a[i] % 5 == 0) {
            ++f[i];
            a[i] /= 5;
        }
        _f[i] = _f[i-1] + f[i];
    }

    dq[0][0][0] = true;
    int ii = 0;
    for (int i = 1; i <= n; ++i) {
        ii ^= 1;
        for (int j = 0; j < MAXN; ++j)
            memset(dp[ii][j], 0, sizeof(dp[ii][j]));
        for (int j = 0; j < MAXN; ++j)
            memset(dq[ii][j], 0, sizeof(dq[ii][j]));
        dq[ii][0][0] = true;

        for (int j = 1; j <= i; ++j) {
            for (int k = 0; k <= _f[i]; ++k) {
                if (i > j && dq[ii^1][j][k]) {
                    dp[ii][j][k] = max(dp[ii][j][k], dp[ii^1][j][k]);
                    dq[ii][j][k] = true;
                }
                if (k >= f[i] && dq[ii^1][j-1][k-f[i]]) {
                    dp[ii][j][k] = max(dp[ii][j][k], dp[ii^1][j-1][k-f[i]] + t[i]);
                    dq[ii][j][k] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= _f[n]; ++i)
        ans = max(ans, min(dp[ii][k][i], i));
    printf("%d\n", ans);

    return 0;
}

