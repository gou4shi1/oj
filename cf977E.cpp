/************************************************************************
* File Name : cf977E.cpp
* Purpose : graph
* Creation Date : 2018年05月06日
* Last Modified : 2018年05月07日 星期一 00时35分57秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 400000 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define lld I64d
#endif

// vector
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))

struct Edge {
    int to, nxt;
} edge[N];
int head[N], d[N], es;

void addEdge(int u, int v) {
    ++es;
    edge[es] = { v, head[u] };
    head[u] = es;
}

bool f[N];
int be, ans;

void travel(int u) {
    if (f[u])
        return;
    f[u] = true;
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        travel(v);
    }
}

void check(int u, int fa) {
    if (u == be) {
        ++ans;
    }
    if (f[u])
        return;
    f[u] = true;

    if (d[u] != 2)
        return;

    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != fa) {
            check(v, u);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        ++d[u];
        ++d[v];
        addEdge(u, v);
        addEdge(v, u);
    }

    for (int u = 1; u <= n; ++u) {
        if (!f[u]) {
            if (d[u] != 2) {
                travel(u);
            } else {
                be = u;
                f[u] = true;
                check(edge[head[u]].to, u);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}

