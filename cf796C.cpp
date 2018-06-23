/************************************************************************
* File Name : cf796C.cpp
* Purpose : tree
* Creation Date : 2017年04月15日
* Last Modified : 2017年04月15日 星期六 22时56分57秒
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

const int MAXN = 300000 + 10;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY a;

struct Edge{
    int v, next;
}edge[MAXN << 1];
ARRAY head;
int edge_size;
void addEdge(int u, int v) {
    edge[++edge_size] = (Edge){v, head[u]};
    head[u] = edge_size;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    int maxu(1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > a[maxu])
            maxu= i;
    }
    int maxun(0); 
    for (int i = 1; i <= n; ++i)
        if (a[i] == a[maxu])
            ++maxun;

    int lmaxu(0), lmaxun(0);
    for (int i = 1; i <= n; ++i)
        if (a[i] != a[maxu]) {
            lmaxu = i;
            break;
        }
    if (lmaxu) {
        for (int i = 1; i <= n; ++i)
            if (a[maxu] > a[i] && a[i] > a[lmaxu])
                lmaxu = i;
        for (int i = 1; i <= n; ++i)
            if (a[i] == a[lmaxu])
            ++lmaxun;
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    int maxv(0), maxw(0), maxwv(0), maxvn(0);
    for (int i = head[maxu]; i; i = edge[i].next) {
        int v = edge[i].v;

        if (!maxv || a[v] > a[maxv]) {
            maxvn = 0;
            maxv = v;
        }
        if (a[v] == a[maxv])
            ++maxvn;

        for (int j = head[v]; j; j = edge[j].next) {
            int w = edge[j].v;
            if (w == maxu)
                continue;

            if (!maxw || a[w] > a[maxw]) {
                maxw = w;
                maxwv = v;
            }
        }
    }

    int ans;
    if (n == 1) {
        ans = a[1];
    } else if (n == 2) {
        if (a[1] == a[2])
            ans = a[1] + 1;
        else
            ans = max(a[1], a[2]);
    } else if (maxw && a[maxu] == a[maxw]) {
        for (int i = head[maxwv]; i; i = edge[i].next)
            if (a[edge[i].v] == a[maxu])
                --maxun;
        if (a[maxwv] == a[maxu])
            --maxun;
        if (maxun)
            ans = a[maxu] + 2;
        else
            ans = a[maxu] + 1;
    } else {
        if (a[maxv] == a[maxu])
            maxun -= maxvn;
        --maxun;
        if (maxun)
            ans = a[maxu] + 2;
        else {
            ans = max(a[maxu], a[maxv] + 1);
            if (lmaxu) {
                for (int i = head[maxu]; i; i = edge[i].next)
                    if (a[edge[i].v] == a[lmaxu])
                        --lmaxun;
                if (lmaxun)
                    ans = max(ans, a[lmaxu] + 2);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}

