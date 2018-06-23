/************************************************************************
* File Name : spoj_cot2.cpp
* Purpose : MoDui on Tree
* Creation Date : 2017年10月10日
* Last Modified : 2017年10月16日 星期一 23时01分16秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 40000 + 10;
const int M = 100000 + 10;
const int MLOG = 20;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

// vector
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))

int n, m, a[N], ans[M];

// hash
int h[N], _h[N], hs;

// edge
struct Edge {
    int to, nx;
}edge[N*2];
int es, head[N];

void addEdge(int u, int v) {
    edge[++es].to = v;
    edge[es].nx = head[u];
    head[u] = es;
}

// lca
int fa[MLOG][N], dep[N];

void dfs_lca(int u) {
    for (int i = head[u]; i; i = edge[i].nx) {
        int v = edge[i].to;
        if (v == fa[0][u])
            continue;
        fa[0][v] = u;
        dep[v] = dep[u] + 1;
        dfs_lca(v);
    }
}

void init_lca() {
    dfs_lca(1);
    for (int k = 0; k+1 < MLOG; ++k)
        for (int u = 1; u <= n; ++u)
            fa[k+1][u] = fa[k][fa[k][u]];
}

int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    for (int k = 0; k < MLOG; ++k)
        if ((dep[u]-dep[v]) & (1<<k))
            u = fa[k][u];
    if (u == v)
        return u;
    for (int k = MLOG-1; k >= 0; --k)
        if (fa[k][u] != fa[k][v])
            u = fa[k][u], v = fa[k][v];
    return fa[0][u];
}

// block
int block[N], bcnt, block_size;
int stk[N], top;

int dfs_block(int u) {
    int size = 0;
    for (int i = head[u]; i; i = edge[i].nx) {
        int v = edge[i].to;
        if (v == fa[0][u])
            continue;
        size += dfs_block(v);
        if (size >= block_size) {
            ++bcnt;
            while (size--)
                block[stk[top--]] = bcnt;
        }
    }

    stk[++top] = u;
    return ++size;
}

void init_block() {
    block_size = max(1, (int)sqrt(n));
    dfs_block(1);
    while (top)
        block[stk[top--]] = bcnt - 1;
}

// MoDui
bool vis[N];
int cnt[N], diff;

struct Query {
    int u, v, id;
    bool operator < (const Query &rhs) {
        if (block[u] != block[rhs.u])
            return block[u] < block[rhs.u];
        return block[v] < block[rhs.v];
    }
}q[M];

void xorNode(int u) {
    if (vis[u]) {
        vis[u] = false;
        diff -= (--cnt[h[u]] == 0);
    } else {
        vis[u] = true;
        diff += (++cnt[h[u]] == 1);
    }
}

void xorPathWithoutLca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    while (dep[u] != dep[v])
        xorNode(u), u = fa[0][u];
    while (u != v) {
        xorNode(u), u = fa[0][u];
        xorNode(v), v = fa[0][v];
    }
}

void move(int u, int v, int uu, int vv) {
    xorPathWithoutLca(u, uu);
    xorPathWithoutLca(v, vv);
    xorNode(lca(u, v));
    xorNode(lca(uu, vv));
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        _h[++hs] = a[i];
    }

    sort(_h+1, _h+1+hs);
    hs = unique(_h+1, _h+1+hs) - (_h+1);
    for (int i = 1; i <= n; ++i)
        h[i] = lower_bound(_h+1, _h+1+hs, a[i]) - _h;
    
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    init_lca();
    init_block();

    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &q[i].u, &q[i].v);
        if (block[q[i].u] > block[q[i].v])
            swap(q[i].u, q[i].v);
        q[i].id = i;
    }

    sort(q+1, q+1+m);
    int u = 1, v = 1;
    xorNode(1);
    for (int i = 1; i <= m; ++i) {
        move(u, v, q[i].u, q[i].v);
        ans[q[i].id] = diff;
        u = q[i].u, v = q[i].v;
    }

    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);

    return 0;
}

