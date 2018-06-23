/************************************************************************
* File Name : hdu3974.cpp
* Purpose : segment tree
* Creation Date : 2017年09月28日
* Last Modified : 2017年09月28日 星期四 14时55分18秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 50000 + 10;
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

// array
typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

// edge
struct Edge {
    int to, nx;
}edge[MAXN];
ARRAY head, st, ed;
FLAG flag;
int es;

void addEdge(int u, int v) {
    edge[++es].to = v;
    edge[es].nx = head[u];
    head[u] = es;
}

int cnt;
void dfs(int rt) {
    st[rt] = ++cnt;
    for (int i = head[rt]; i; i = edge[i].nx)
        dfs(edge[i].to);
    ed[rt] = cnt;
}

//segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

int cov[MAXN << 2];

void pushUp(int rt) {
    if (cov[lr] >= 0 && cov[rr] >= 0 && cov[lr] == cov[rr])
        cov[rt] = cov[lr];
    else
        cov[rt] = -1;
}

void pushDown(int rt) {
    if (cov[rt] >= 0)
        cov[lr] = cov[rr] = cov[rt];
}

int query(int p, int l, int r, int rt) {
    if (l == r)
        return cov[rt];
    pushDown(rt);
    int m = (l + r) >> 1;
    if (p <= m)
        return query(p, ls);
    return query(p, rs);
}

void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        cov[rt] = c;
        return;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, ls);
    if (m < R)
        update(L, R, c, rs);
    pushUp(rt);
}

void init() {
    memset(cov, -1, sizeof(cov));
    memset(flag, 0, sizeof(flag));
    memset(head, 0, sizeof(head));
    es = cnt = 0;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    for (int Ti = 1; Ti <= T; ++Ti) {
        printf("Case #%d:\n", Ti);
        init();

        int n;
        scanf("%d", &n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(v, u);
            flag[u] = true;
        }
        for (int i = 1; i <= n; ++i)
            if (!flag[i])
                dfs(i);
        int m;
        scanf("%d", &m);
        while (m--) {
            char op[23];
            scanf("%s", op);
            if (op[0] == 'C') {
                int x;
                scanf("%d", &x);
                printf("%d\n", query(st[x], 1, n, 1));
            } else {
                int x, y;
                scanf("%d%d", &x, &y);
                update(st[x], ed[x], y, 1, n, 1);
            }
        }
    }

    return 0;
}

