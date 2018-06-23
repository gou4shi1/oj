/************************************************************************
* File Name : cf576C.cpp
* Purpose : constructive algorithms
* Creation Date : 2017年05月20日
* Last Modified : 2017年05月20日 星期六 16时28分26秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000 + 10;
const int MAXM = 1000;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

struct Point {
    int x, y, id;
}p[MAXN];

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].x /= MAXM;
        p[i].id = i;
    }

    sort(p+1, p+1 + n, [](const Point &a, const Point &b) {
            return a.x < b.x || (a.x==b.x && (a.x%2 ? a.y<b.y : a.y>b.y));
            });

    for (int i = 1; i <= n; ++i)
        printf("%d ", p[i].id);
    return 0;
}

