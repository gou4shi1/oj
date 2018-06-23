/************************************************************************
* File Name : cf811B.cpp
* Purpose : sortings
* Creation Date : 2017年05月29日
* Last Modified : 2017年05月29日 星期一 22时15分23秒
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

ARRAY p;
int main() {
    //freopen("in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    while (m--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        int _less(0), _equal(0);
        for (int i = l; i <= r; ++i)
            if (p[i] < p[x])
                ++_less;
            else if (p[i] == p[x])
                ++_equal;
        if (x < l || x > r || (l-1 + _less < x && x <= l-1 + _less+_equal))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

