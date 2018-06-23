/************************************************************************
* File Name : cf578C.cpp
* Purpose : math
* Creation Date : 2017年05月30日
* Last Modified : 2017年06月01日 星期四 00时04分08秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY a;
int n;

double calc(double x, int f) {
    double sum(0), _max(0);
    for (int i = 0; i < n; ++i) {
        sum += (a[i]-x) * f;
        if (sum < 0)
            sum = 0;
        _max = max(_max, sum);
    }
    return _max;
}

int main() {
    //freopen("in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    double l = *min_element(a, a+n);
    double r = *max_element(a, a+n);
    for (int t = 0; t < 100; ++t) {
        double m = (l + r) / 2;
        double p1 = calc(m, 1), p2 = calc(m, -1);
        if (p1 > p2)
            l = m;
        else
            r = m;
    }

    double p1 = calc(l, 1), p2 = calc(l, -1);
    printf("%.8lf\n", max(p1, p2));
    return 0;
}

