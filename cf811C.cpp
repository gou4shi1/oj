/************************************************************************
* File Name : cf811C.cpp
* Purpose : dp
* Creation Date : 2017年05月29日
* la Modified : 2017年05月29日 星期一 23时19分16秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY a, fi, la, dp, dp2;

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);

        if (!fi[a[i]])
            fi[a[i]] = i;
        la[a[i]] = i;
    }

    for (int i = n; i >= 1; --i) {
        int x = 0, r = 0;
        for (int j = i; j <= n; ++j) {
            if (i > fi[a[j]])
                break;
            if (j == la[a[j]])
                x ^= a[j];
            r = max(r, la[a[j]]);
            if (j < r)
                continue;
            dp[i] = max(dp[i], x + dp2[j+1]);
        }
        dp2[i] = max(dp2[i+1], dp[i]);
    }

    //for (int i = 1; i <= n; ++i)
        //printf("%d ", dp[i]);
    //printf("\n\n");
    printf("%d\n", dp2[1]);
    return 0;
}

