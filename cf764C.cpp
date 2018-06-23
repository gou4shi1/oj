/************************************************************************
* File Name : cf764C.cpp
* Purpose : training
* Creation Date : 2017年04月02日
* Last Modified : 2017年04月02日 星期日 12时54分40秒
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

//edge
struct Edge{
    int v, next;
}edges[MAXN << 1];
ARRAY head;
int edge_size, n;

void addEdge(int u, int v) {
    edges[++edge_size].v = v;
    edges[edge_size].next = head[u];
    head[u] = edge_size;
}

ARRAY colors;

bool isSame(int p, int fa) {
    for (int i = head[p]; i; i = edges[i].next) {
        int v = edges[i].v;
        if (v == fa)
            continue;
        if (colors[v] != colors[p] || !isSame(v, p))
            return false;
    }
    return true;
}

bool isRoot(int r) {
    for (int i = head[r]; i; i = edges[i].next)
        if (!isSame(edges[i].v, r))
            return false;
    return true;
}

int main() {
    //freopen("in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &colors[i]);

    for (int i = 1; i <= n; ++i)
        for (int j = head[i]; j; j = edges[j].next) {
            int v = edges[j].v;
            if (colors[i] == colors[v])
                continue;
            if (isRoot(i))
                printf("YES\n%d\n", i);
            else if (isRoot(v))
                printf("YES\n%d\n", v);
            else
                puts("NO");
            return 0;
        }
    printf("YES\n%d\n", 1);
    return 0;
}

