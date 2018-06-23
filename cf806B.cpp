/************************************************************************
* File Name : cf806B.cpp
* Purpose : simulate
* Creation Date : 2017年05月19日
* Last Modified : 2017年05月20日 星期六 13时17分02秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 120 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;
const double EPS = 1e-6;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

int a[MAXN][10];
int solved[MAXN];

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 5; ++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] >= 0)
                ++solved[j];
        }

    for (int i = 0; i <= 61*n; ++i) {
        int sa = 0, sb = 0;
        for (int j = 1; j <= 5; ++j) {
            int tot = n + i, cur = solved[j];
            if (a[1][j] >= 0 && a[2][j] >= 0 && a[1][j] > a[2][j])
                cur += i;
            int m = 500;
            double f = (double)cur / tot, t = 0.5;
            while (m <= 3000 && f < t+EPS) {
                m += 500;
                t /= 2;
            }
            //printf("# %d #", m);
            if (a[1][j] >= 0)
                sa += m - m/250*a[1][j];
            if (a[2][j] >= 0)
                sb += m - m/250*a[2][j];
        }
        if (sa > sb) {
            printf("%d\n", i);
            return 0;
        }
    }

    puts("-1");
    return 0;
}

