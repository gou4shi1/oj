/************************************************************************
* File Name : cf696B.cpp
* Purpose : propability
* Creation Date : 2017年04月22日
* Last Modified : 2017年04月22日 星期六 14时59分03秒
* Created By : admin@goushi.me
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
const int INF = 0x3f3f3f3f;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

struct Edge{
    int v, next;
}edge[MAXN << 1];
int edge_size;
ARRAY head;
void addEdge(int u, int v) {
    edge[++edge_size] = {v, head[u]};
    head[u] = edge_size;
}

ARRAY fa, size;
double expt[MAXN];

void dfs1(int p) {
    size[p] = 1;
    for (int i = head[p]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa[p])
            continue;
        dfs1(v);
        size[p] += size[v];
    }
}

void dfs2(int p) {
    expt[p] = expt[fa[p]] + (double)(size[fa[p]] - size[p] - 1)/2 + 1;

    for (int i = head[p]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa[p])
            continue;
        dfs2(v);
    }
}

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &fa[i]);
        addEdge(i, fa[i]);
        addEdge(fa[i], i);
    }

    dfs1(1);
    size[0] = size[1] + 1;
    dfs2(1);

    //for (int i = 1; i <= n; ++i)
        //printf("%d ", size[i]);
    //printf("\n");
    for (int i = 1; i <= n; ++i)
        printf("%lf ", expt[i]);
    printf("\n");
    return 0;
}

