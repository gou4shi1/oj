/************************************************************************
* File Name : cf837B.cpp
* Purpose :  water
* Creation Date : 2017年08月14日
* Last Modified : 2017年08月14日 星期一 15时42分35秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100 + 10;
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

int n, m;
char s[MAXN][MAXN];

bool isSame(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; ++i)
        for (int j = y1; j <= y2; ++j)
            if (s[i][j] != s[x1][y1])
                return false;
    return true;
}

bool f[233];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);

    bool ans = false;

    if (n % 3 == 0) {
        if (isSame(0, 0, n/3 - 1, m-1) && isSame(n/3, 0, 2*n/3 - 1, m-1) && isSame(2*n/3, 0, n-1, m-1)) {
            f[s[0][0]] = f[s[n/3][0]] = f[s[2*n/3][0]] = true;
            if (f['R'] && f['G'] && f['B'])
                ans = true;
        }
    }

    memset(f, 0, sizeof(f));
    if (m % 3 == 0) {
        if (isSame(0, 0, n-1, m/3 - 1) && isSame(0, m/3, n-1, 2*m/3 - 1) && isSame(0, 2*m/3, n-1, m-1)) {
            f[s[0][0]] = f[s[0][m/3]] = f[s[0][2*m/3]] = true;
            if (f['R'] && f['G'] && f['B'])
                ans = true;
        }
    }

    puts(ans ? "YES" : "NO");

    return 0;
}

