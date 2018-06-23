/************************************************************************
* File Name : cf812C.cpp
* Purpose : binary search
* Creation Date : 2017年06月01日
* Last Modified : 2017年06月01日 星期四 23时53分23秒
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

ARRAY a;
LL b[MAXN];
int n, S;

int check(int m) {
    for (int i = 1; i <= n; ++i)
        b[i] = a[i] + m * 1LL * i;
    sort(b+1, b+1 + n);
    LL sum = 0;
    for (int i = 1; i <= m; ++i) {
        sum += b[i];
        if (sum > S)
            return 0;
    }
    return sum;
}

int main() {
    //freopen("in", "r", stdin);
    scanf("%d%d", &n, &S);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m) > 0)
            l = m;
        else
            r = m - 1;
    }

    int rr = check(r);
    if (rr > 0)
        printf("%d %d\n", r, rr);
    else
        printf("%d %d\n", l, check(l));
    return 0;
}

