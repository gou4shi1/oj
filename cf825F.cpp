/************************************************************************
* File Name : cf825F.cpp
* Purpose : dp + prefix-function
* Creation Date : 2017年08月08日
* Last Modified : 2017年08月08日 星期二 23时37分59秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 8000 + 10;
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

char s[MAXN];
int pf[MAXN][MAXN], T[MAXN][MAXN];
ARRAY dp;

int getLen(int x) {
    int len = 1;
    while (x / 10) {
        ++len;
        x /= 10;
    }
    return len;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    scanf("%s", s);
    int n = strlen(s);

    for (int i = 0; i < n; ++i) {
        int k = 0;
        for (int j = i+1; j < n; ++j) {
            while (k && s[i + k] != s[j])
                k = pf[i][i + k - 1];
            if (s[i + k] == s[j])
                pf[i][j] = ++k;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j)
            T[i][j] = ((j-i+1) % (j-i+1 - pf[i][j])) ? (j-i+1) : (j-i+1 - pf[i][j]);
    }


    for (int i = 0; i < n; ++i) {
        dp[i] = getLen((i+1) / T[0][i]) + T[0][i];
        for (int j = i-1; j >= 0; --j)
            dp[i] = min(dp[i], dp[j] + getLen((i - j) / T[j+1][i]) + T[j+1][i]);
    }

    printf("%d\n", dp[n-1]);

    return 0;
}

