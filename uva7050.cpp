#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100;
const int M = 50;
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

int f[M + 2][M + 2];
int a[N + 2];
int dis[2][N + 1];
int Cal(int b, int e, int l, int m)
{
    int i, j, k;
    int ans = _INF;
    for (i = 1; i <= m; ++i) {
        dis[0][i] = f[i][e];
    }
    for (k = 1; k < l - 1; ++k) {
        int c1 = k & 1;
        int c0 = (k + 1) & 1;
        for (i = 1; i <= m; ++i) {
            int mx = _INF;
            for (j = 1; j <= m; ++j) {
                if (f[i][j] + dis[c0][j] > mx) mx = f[i][j] + dis[c0][j];
            }
            dis[c1][i] = mx;
        }
    }

    for (k = (k + 1) & 1, j = 1; j <= m; ++j) 
        if (f[b][j] + dis[k][j] > ans) 
            ans = f[b][j] + dis[k][j];
    //printf("%d\n", ans);
    return ans;
}

int main() {
    int i, j;
    int T;
    scanf("%d", &T);
    while (T--) {
        mst(f, 0);
        mst(a, 0);
        int ans = 0;
        int n, m;
        scanf("%d %d", &n, &m);
        for (i = 1; i <= m; ++i) 
            for (j = 1; j <= m; ++j) 
                scanf("%d", &f[i][j]);
        for (i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int b = 0;
        for (i = 1; i <= n + 1; ++i) {
            if(a[i] != -1) {
                if (i - b == 1) {
                    b = i;
                    ans += f[a[i - 1]][a[i]];
                }
                else {
                    ans += Cal(a[b], a[i], i - b, m);
                    b = i;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
