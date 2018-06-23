/************************************************************************
* File Name : hdu4010.cpp
* Purpose : link-cut-tree-template
* Creation Date : 2016年10月10日
* Last Modified : 2016年10月11日 星期二 17时59分48秒
* Created By : gou4shi1@qq.com
************************************************************************/
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

const int MAXN = 300010;

typedef int ARRAY[MAXN];

template<class T>
inline T max(T a, T b, T c) {return max(max(a, b), c);}

ARRAY val, head, fa, _max, add, rev;
int ch[MAXN][2];
bool rt[MAXN];

//edge
struct Edge {
    int to, next;
} edge[MAXN << 1];

int edge_size;

inline void addEdge(int u, int v) {
    edge[++edge_size].to = v;
    edge[edge_size].next = head[u];
    head[u] = edge_size;
}

//initialize
inline void init() {
    edge_size = 0;
    memset(head, 0, sizeof(head));
    fa[1] = 0;
    memset(add, 0, sizeof(add));
    memset(rev, 0, sizeof(rev));
    memset(rt, 1, sizeof(rt));
    for (int i = 0; i != MAXN; ++i)
        ch[i][0] = ch[i][1] = 0;
}

void dfs(int u) {
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        dfs(v);
    }
}

bool isSameRoot(int u, int v) {
    while (fa[u])
        u = fa[u];
    while (fa[v])
        v = fa[v];
    return u == v;
}

inline void updateAdd(int r, int d) {
    if (!r)
        return;
    val[r] += d;
    add[r] += d;
    _max[r] += d;
}

inline void updateRev(int r) {
    if (!r)
        return;
    swap(ch[r][0], ch[r][1]);
    rev[r] ^= 1;
}

void pushDown(int r) {
    if (add[r]) {
        updateAdd(ch[r][0], add[r]);
        updateAdd(ch[r][1], add[r]);
        add[r] = 0;
    }
    if (rev[r]) {
        updateRev(ch[r][0]);
        updateRev(ch[r][1]);
        rev[r] = 0;
    }
}

void pushDownFromRoot(int r) {
    if (!rt[r])
        pushDownFromRoot(fa[r]);
    pushDown(r);
}

inline void pushUp(int r) {
    _max[r] = max(val[r], _max[ch[r][0]], _max[ch[r][1]]);
}

inline void rotate(int x) {
    int y = fa[x];
    int kind = ch[y][1]==x;
    ch[y][kind] = ch[x][!kind];
    fa[ch[y][kind]] = y;
    fa[x] = fa[y];
    fa[y] = x;
    ch[x][!kind] = y;
    if (rt[y]) {
        rt[y] = false;
        rt[x] = true;
    } else
        ch[fa[x]][ ch[fa[x]][1]==y ] = x;
    pushUp(y);
}

void splay(int r) {
    pushDownFromRoot(r);
    while (!rt[r]) {
        int f = fa[r];
        int ff = fa[f];
        if (rt[f])
            rotate(r);
        else if ( (ch[ff][1]==f) == (ch[f][1]==r) ) {
            rotate(f);
            rotate(r);
        } else {
            rotate(r);
            rotate(r);
        }
    }
}

int access(int x) {
    int y = 0;
    for (; x; x = fa[y=x]) {
        splay(x);
        rt[ch[x][1]] = true;
        rt[y] = false;
        ch[x][1] = y;
        pushUp(x);
    }
    return y;
}

void makeRoot(int r) {
    access(r);
    splay(r);
    updateRev(r);
}

void link(int u, int v) {
    if (isSameRoot(u, v)) {
        printf("-1\n");
        return;
    }
    makeRoot(u);
    fa[u] = v;
}

void cut(int u, int v) {
    if (u == v || !isSameRoot(u, v)) {
        printf("-1\n");
        return;
    }
    makeRoot(u);
    splay(v);
    fa[ch[v][0]] = fa[v];
    rt[ch[v][0]] = true;
    fa[v] = 0;
    ch[v][0] = 0;
}

void lca(int &u, int &v) {
    access(v);
    v = 0;
    while (u) {
        splay(u);
        if (!fa[u])
            return;
        rt[ch[u][1]] = true;
        ch[u][1] = v;
        rt[ch[u][1]] = false;
        pushUp(u);
        v = u;
        u = fa[u];
    }
}

void modify_add(int u, int v, int w) {
    if (!isSameRoot(u, v)) {
        printf("-1\n");
        return;
    }
    lca(u, v);
    updateAdd(ch[u][1], w);
    updateAdd(v, w);
    val[u] += w;
    pushUp(u);
}

void query_max(int u, int v) {
    if (!isSameRoot(u, v)) {
        printf("-1\n");
        return;
    }
    lca(u, v);
    printf("%d\n", max(val[u], _max[v], _max[ch[u][1]]));
}

//main
int main() {
    //freopen("in", "r", stdin);
    int n;
    while (~scanf("%d", &n)) {
        init();
        int u, v;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &val[i]);
            _max[i] = val[i];
        }
        int q;
        scanf("%d", &q);
        dfs(1);
        int op, x, y, w;
        while (q--) {
            scanf("%d", &op);
            switch (op) {
                case 1:
                    scanf("%d%d", &x, &y);
                    link(x, y);
                    break;
                case 2:
                    scanf("%d%d", &x, &y);
                    cut(x, y);
                    break;
                case 3:
                    scanf("%d%d%d", &w, &x, &y);
                    modify_add(x, y, w);
                    break;
                case 4:
                    scanf("%d%d", &x, &y);
                    query_max(x, y);
                    break;
                default:
                    printf("-1\n");
            }
        }
        printf("\n");
    }
    return 0;
}

