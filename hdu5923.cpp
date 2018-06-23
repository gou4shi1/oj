/************************************************************************
* File Name : hdu5923.cpp
* Purpose : training
* Creation Date : 2016年10月15日
* Last Modified : 2016年10月15日 星期六 23时36分22秒
* Created By : gou4shi1@qq.com
************************************************************************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 500 + 10;
const int MAXM = 10000 + 10;

typedef int ARRAY[MAXN];

vector<int> son[MAXM];

ARRAY f[MAXM];

struct Edge {
    int u, v;
} edge[MAXM];

inline void init() {
    for (int i = 0; i != MAXM; ++i)
        son[i].clear();

    for (int i = 0; i != MAXN; ++i)
        f[0][i] = i;
}

inline int find(int *fa, int x) {
    return fa[x]==x ? x : fa[x] = find(fa, fa[x]);
}

inline void unin(int *fa, int x, int y) {
   fa[find(fa, x)] = find(fa, y);
}

void dfs(int x, int fa) {
    memcpy(f[x], f[fa], sizeof(f[x]));
    unin(f[x], edge[x].u, edge[x].v);

    for (vector<int>::iterator it = son[x].begin(); it != son[x].end(); ++it)
        dfs(*it, x);
}

int main() {
    //freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d:\n", kase);

        init();

        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 2; i <= m; ++i) {
            int x;
            scanf("%d", &x);
            son[x].push_back(i);
        }
        for (int i = 1; i <= m; ++i)
            scanf("%d%d", &edge[i].u, &edge[i].v);

        dfs(1, 0);

        int q;
        scanf("%d", &q);
        while (q--) {
            int k;
            scanf("%d", &k);
            ARRAY ff;
            memcpy(ff, f[0], sizeof(ff));
            while (k--) {
                int x;
                scanf("%d", &x);
                for (int i = 1; i <= n; ++i)
                    unin(ff, i, find(f[x], i));
            }
            int ans = 0;
            for (int i = 1; i <= n; ++i)
                if (find(ff, i) == i)
                    ++ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}

