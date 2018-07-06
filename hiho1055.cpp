/************************************************************************
* File Name : hiho1055.cpp
* Purpose : tree-dp + knapsack
* Creation Date : 2018年07月06日
* Last Modified : 2018年07月06日 星期五 21时53分41秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = (int)0x80000000;
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

int n, m;
int a[N];
int dp[N][N];
vector<int> e[N];

void dfs(int u, int fa) {
    dp[u][1] = a[u];
    for (int v: e[u]) {
        if (v == fa)
            continue;

        dfs(v, u);

        for (int i = m; i >= 2; --i) {
            for (int j = 0; j < i; ++j) {
                dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j]);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 0);

    cout << dp[1][m] << endl;

    return 0;
}
