/************************************************************************
* File Name : hdu6052.cpp
* Purpose : BIT?
* Creation Date : 2017年10月08日
* Last Modified : 2017年10月08日 星期日 21时11分00秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100 + 10;
const int MAXM = 10000 + 10;
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

// array
typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

int a[MAXN][MAXN];
int l[MAXN], r[MAXN];
int low[MAXM][MAXN];

void init() {
    memset(low, 0, sizeof(low));
}    

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);

        LL ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                int aa = a[i][j];
                for (int k = 0; k < MAXN; ++k)
                    l[k] = 0;
                for (int k = 0; k < MAXN; ++k)
                    r[k] = m+1;
                for (int k = 1; k < j; ++k)
                    l[low[aa][k]] = max(l[low[aa][k]], k);
                for (int k = j+1; k <= m; ++k)
                    r[low[aa][k]] = min(r[low[aa][k]], k);
                int L = 0, R = m+1;
                for (int k = i; k > low[aa][j]; --k) {
                    L = max(L, l[k]);
                    R = min(R, r[k]);
                    ans += (j-L)*(n-i+1)*(R-j);
                    //printf("%d %d:" LLD "\n", L, R, ans);
                }
                low[aa][j] = i;

            }
        LL ans2 = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                ans2 += (n-i+1) * (m-j+1);
        printf("%.9lf\n", (double)ans/ans2);
    }

    return 0;
}
