/************************************************************************
* File Name : cf765D.cpp
* Purpose : training
* Creation Date : 2017年03月31日
* Last Modified : 2017年03月31日 星期五 23时48分06秒
* Created By : gou4shi1@qq.com
************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 100000 + 10;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY f, _f, g, h;
FLAG ff, gg;

int main() {
    //freopen("in", "r", stdin);
    int n, m(0);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
        if (!_f[f[i]]) {
            _f[f[i]] = i;
            g[i] = ++m;
            h[m] = f[i];
            gg[f[i]] = true;
        } else {
            g[i] = g[_f[f[i]]];
        }
        if (i == f[i])
            gg[f[i]] = false;
    }
    for (int i = 1; i <= n; ++i)
        if (gg[i]) {
            puts("-1");
            return 0;
        }
    printf("%d\n", m);
    for (int i = 1; i < n; ++i)
        printf("%d ", g[i]);
    printf("%d\n", g[n]);
    for (int i = 1; i < m; ++i)
        printf("%d ", h[i]);
    printf("%d\n", h[m]);
    return 0;
}

