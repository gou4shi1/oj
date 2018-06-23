/************************************************************************
* File Name : hdu5115.cpp
* Purpose : ???
* Creation Date : 2017年10月14日
* Last Modified : 2017年10月14日 星期六 15时23分45秒
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

#define maxsize 200
int f[maxsize + 2][maxsize + 2];
int attack[maxsize + 2], buff[maxsize + 2];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int test;
    scanf("%d", &test);
    int i, j, k, l, t;
    for (t = 1; t <= test; ++t) {
        int n;
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) 
            scanf("%d", &attack[i]);
        for (i = 1; i <= n; ++i)
            scanf("%d", &buff[i]);
        for (l = 1; l <= n; ++l) {
            for (i = 1; i <= n - l + 1; ++i) {
                j = i + l - 1;
                int minat = INF;
                for (k = i; k <= j; ++k) {
                    int sum_at = f[i][k - 1] + f[k + 1][j] + attack[k] + buff[i - 1] + buff[j + 1];
                    if (sum_at < minat) minat = sum_at;
                }
                f[i][j] = minat;
            } 
        }
        printf("Case #%d: %d\n", t, f[1][n]);
    }
    return 0;
}

