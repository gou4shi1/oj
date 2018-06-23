/************************************************************************
* File Name : spoj_cot.cpp
* Purpose : LHC + Chairman Tree
* Creation Date : 2017年10月10日
* Last Modified : 2017年10月12日 星期四 02时35分21秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100000 + 10;
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

int a[N];

// hash
int h[N];
int hs;
#define _h(x) (lower_bound(h+1, h+1+hs, x)-h)

// edge
struct Edge {
    int to, nx;
}edge[N*2];
int es;
int head[N];

void addEdge(int u, int v) {
    edge[++es].to = v;
    edge[es].nx = head[u];
    head[u] = es;
}

// Chairman Tree
struct Tree {
    int s, l, r;
}tree[N*25];
int ts;

int root[N];

void newNode(int &x, int s, int l, int r) {
    x = ++ts;
    tree[x] = {s, l, r};
}

void build(int &rt, int pre_rt, int l, int r, int p) {
    newNode(rt, tree[pre_rt].s+1, tree[pre_rt].l, tree[pre_rt].r);
    if (l == r)
        return;
    int m = (l + r) >> 1;
    if (p <= m)
        build(tree[rt].l, tree[pre_rt].l, l, m, p);
    else
        build(tree[rt].r, tree[pre_rt].r, m+1, r, p);
}

int query(int u, int v, int lca, int lca_f, int l, int r, int k) {
    if (l == r)
        return l;
    int m = (l + r) >> 1;
    int s = tree[tree[u].l].s + tree[tree[v].l].s - tree[tree[lca].l].s - tree[tree[lca_f].l].s;
    if (k <= s)
        return query(tree[u].l, tree[v].l, tree[lca].l, tree[lca_f].l, l, m, k);
    return query(tree[u].r, tree[v].r, tree[lca].r, tree[lca_f].r, m+1, r, k-s);
}

// LHC
int size[N], fa[N], dep[N], hson[N], top[N];

void dfs1(int u) {
    build(root[u], root[fa[u]], 1, hs, _h(a[u]));

    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].nx) {
        int v = edge[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        size[u] += size[v];
        if (size[v] > size[hson[u]])
            hson[u] = v;
    }
}

void dfs2(int u, int u_top) {
    top[u] = u_top;
    if (!hson[u])
        return;
    dfs2(hson[u], u_top);
    for (int i = head[u]; i; i = edge[i].nx) {
        int v = edge[i].to;
        if (v != fa[u] && v != hson[u])
            dfs2(v, v);
    }
}

int lca(int u, int v) {
    for (; top[u] != top[v]; (dep[top[u]]>dep[top[v]]) ? (u=fa[top[u]]) : (v=fa[top[v]])) ;
    return dep[u]<dep[v] ? u : v;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        h[++hs] = a[i];
    }
    sort(h+1, h+1+hs);
    hs = unique(h+1, h+1+hs) - (h+1);

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs1(1);
    dfs2(1, 1);

    for (int i = 1; i <= m; ++i) {
        int u, v, k;
        scanf("%d%d%d", &u, &v, &k);
        int l = lca(u, v);
        printf("%d\n", h[query(root[u], root[v], root[l], root[fa[l]], 1, hs, k)]);
    }

    return 0;
}

