/************************************************************************
* File Name : cf825G.cpp
* Purpose : dfs
* Creation Date : 2017年08月09日
* Last Modified : 2017年08月09日 星期三 21时17分52秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 1000000 + 10;
const int INF = 0x3f3f3f3f;
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

struct Edge {
    int to, next;
} edge[MAXN*2];

int edge_size;
ARRAY head, fa, _m;
FLAG flag;

void addEdge(int x, int y) {
    edge[++edge_size].next = head[x];
    edge[edge_size].to = y;
    head[x] = edge_size;
}

void setFa(int f) {
    for (int i = head[f]; i; i = edge[i].next) {
        int s = edge[i].to;
        if (s == fa[f])
            continue;
        fa[s] = f;
        setFa(s);
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        addEdge(x, y);
        addEdge(y, x);
    }
    
    int rt;
    scanf("%*d%d", &rt);
    rt = rt % n + 1;
    fa[rt] = 0;
    setFa(rt);
    flag[rt] = true;
    int global_min = rt;

    int last = 0;
    for (int i = 1; i < q; ++i) {
        int t, x;
        scanf("%d%d", &t, &x);
        x = (x + last) % n + 1;
        if (t == 1) {
            while (x && !flag[x]) {
                global_min = min(global_min, x);
                flag[x] = true;
                x = fa[x];
            }
        } else {
            if (flag[x]) {
                last = global_min;
            } else {
                int m = x, xx = x;
                while (x && !flag[x]) {
                    if (_m[x]) {
                        m = min(m, _m[x]);
                        break;
                    }
                    m = min(m, x);
                    x = fa[x];
                }
                _m[xx] = m;
                last = min(global_min, m);
            }
            printf("%d\n", last);
        }
    }

    return 0;
}

