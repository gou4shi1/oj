/************************************************************************
* File Name : cf789D.cpp
* Purpose : training
* Creation Date : 2017年04月01日
* Last Modified : 2017年04月01日 星期六 21时31分31秒
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

const int MAXN = 1000000 + 10;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

struct Edge{
    int u, v;
}edges[MAXN];

ARRAY fa, deg;
FLAG flag;

void init(int n) {
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}

int find(int u) {
    return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
    fa[find(u)] = find(v);
}

int main() {
    //freopen("in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    int loop(0);
    int root(0);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[i].u = u;
        edges[i].v = v;
        flag[u] = true;
        flag[v] = true;
        if (!root)
            root = u;
        if (u == v) {
            ++loop;
            continue;
        }
        ++deg[u];
        ++deg[v];
        unin(u, v);
    }
    for (int i = 1; i <= n; ++i)
        if (flag[i] && find(i) != find(root)) {
            puts("0");
            return 0;
        }
    if (m < 2) {
        puts("0");
        return 0;
    }
    LL ans(0);
    for (int i = 1; i <= m; ++i) {
        int u = edges[i].u, v = edges[i].v;
        if (u != v) {
            ans += deg[u]-1 + deg[v]-1 + loop;
        } else {
            ans += m - 1;
        }
    }
    printf("%I64d\n", ans / 2);
    return 0;
}

