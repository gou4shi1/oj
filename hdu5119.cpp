/************************************************************************
* File Name : hdu5119.cpp
* Purpose : dp
* Creation Date : 2017年10月14日
* Last Modified : 2017年10月14日 星期六 17时16分27秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 40 + 10;
const int M = 2000000 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

// vector
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))
typedef int itn;

int a[N];
LL dp[2][M];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    for (int Ti = 1; Ti <= T; ++Ti) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        mst(dp, 0);
        dp[0][0] = 1;
        int cur = 0;
        for (int i = 1; i <= n; ++i) {
            cur ^= 1;
            for (int j = 0; j < M; ++j) {
                if ((j^a[i]) < M)
                        dp[cur][j] = dp[cur^1][j] + dp[cur^1][j^a[i]];
            }
        }
        LL ans(0);
        for (int i = m; i < M; ++i)
            ans += dp[cur][i];
        printf("Case #%d: " LLD "\n", Ti, ans);
    }

    return 0;
}

