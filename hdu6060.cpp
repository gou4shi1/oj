/************************************************************************
* File Name : hdu6060.cpp
* Purpose : dfs
* Creation Date : 2017年10月15日
* Last Modified : 2017年10月15日 星期日 15时30分23秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 1000000 + 10;
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
typedef int itn;

struct Edge {
    int to, nx, c;
}edge[N*2];
int es;
int head[N];

void addEdge(int u, int v, int c) {
    edge[++es].to = v;
    edge[es].nx = head[u];
    edge[es].c = c;
    head[u] = es;
}

int n, k;
LL ans;

int size[N];

void dfs(int u, int f, int c) {
    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].nx) {
        int v = edge[i].to;
        if (v == f)
            continue;
        dfs(v, u, edge[i].c);
        size[u] += size[v];
    }
    ans += (LL)c * min(k, size[u]);
}

void init() {
    es = 0;
    mst(head, 0);
    mst(size, 0);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    while (~scanf("%d%d", &n, &k)) {
        init();
        for (int i = 1; i < n; ++i) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            addEdge(u, v, c);
            addEdge(v, u, c);
        }

        ans = 0;
        dfs(1, 0, 0);
        printf(LLD "\n", ans);
    }


    return 0;
}

