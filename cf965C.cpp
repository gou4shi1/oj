/************************************************************************
* File Name : cf965C.cpp
* Purpose : math
* Creation Date : 2018年05月04日
* Last Modified : 2018年05月05日 星期六 00时18分55秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100000 + 10;
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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    LL n, k, M, D;
    scanf("%lld%lld%lld%lld", &n, &k, &M, &D);

    D = min(D, n / k + 1);
    LL ans = 0;
    for (int d = 1; d <= D; ++d) {
        LL x = min(M, n / ((d - 1) * k + 1));
        ans = max(ans, d * x);
    }
    printf("%lld\n", ans);

    return 0;
}

