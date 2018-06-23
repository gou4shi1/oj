/************************************************************************
* File Name : cf812B.cpp
* Purpose : water
* Creation Date : 2017年06月01日
* Last Modified : 2017年06月01日 星期四 23时23分23秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

int main() {
    //freopen("in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int dpll = 0, dprr = 0, flag = 1;
    for (int i = 0; i < n; ++i) {
        //printf("# %d %d\n", dpll, dprr);
        char a[233];
        scanf("%s", a);
        int l = 0, r = 0;
        for (int j = 1; j <= m; ++j) {
            if (a[j] == '0')
                continue;
            if (!l)
                l = j;
            r = j;
        }

        if (flag) {
            if (l) {
                dpll = r;
                dprr = m - l + 1;
                flag = 0;
            }
            continue;
        }

        int dpl, dpr;
        if (!l) {
            dpl = min(1 + dpll, m + 2 + dprr);
            dpr = min(1 + dprr, m + 2 + dpll);
        } else {
            dpl = min(r*2 + 1 + dpll, m + 2 + dprr);
            dpr = min((m-l+1)*2 + 1 + dprr, m + 2 + dpll);
        }

        dpll = dpl;
        dprr = dpr;
    }
    printf("%d\n", dpll);
    return 0;
}

