/************************************************************************
* File Name : hdu5877.cpp
* Purpose : treap
* Creation Date : 2016年10月14日
* Last Modified : 2016年10月14日 星期五 23时06分30秒
* Created By : gou4shi1@qq.com
************************************************************************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN =  100000 + 100;

typedef int ARRAY[MAXN];
typedef long long LL;

ARRAY a;
bool isRoot[MAXN];
int n;
LL k, ans;

//edge
struct Edge {
    int to, next;
} edge[MAXN];

int edge_size;
ARRAY head;

inline void newEdge(int u, int v) {
    edge[++edge_size].to = v;
    edge[edge_size].next = head[u];
    head[u] = edge_size;
}

//treap
struct TreapNode {
    int val, size, pri, son[2];
} tree[MAXN];

int node_size, rt;

inline void newNode(int &x, int val) {
    x = ++node_size;
    tree[x].val = val;
    tree[x].size = 1;
    tree[x].pri = rand();
    tree[x].son[0] = tree[x].son[1] = 0;
}

inline void pushUp(int x) {
    tree[x].size = tree[tree[x].son[0]].size + 1 + tree[tree[x].son[1]].size;
}


inline void rotate(int &x, int p) {
    int y = tree[x].son[!p];
    tree[x].son[!p] = tree[y].son[p];
    pushUp(x);
    tree[y].son[p] = x;
    pushUp(y);
    x = y;
}

void ins(int &x, int val) {
    if (!x) {
        newNode(x, val);
        return;
    }

    int p = a[val] < a[tree[x].val];
    ins(tree[x].son[!p], val);
    pushUp(x);
    if (tree[x].pri < tree[tree[x].son[!p]].pri)
        rotate(x, p);
}

void del(int &x, int val) {
    if (tree[x].val == val) {
        if (tree[x].son[0] && tree[x].son[1]) {
            int p = tree[tree[x].son[0]].pri > tree[tree[x].son[1]].pri;
            rotate(x, p);
            del(tree[x].son[p], val);
            pushUp(x);
        } else {
            if (!tree[x].son[0])
                x = tree[x].son[1];
            else
                x = tree[x].son[0];
        }
    } else {
        int p = a[tree[x].val] > a[val];
        del(tree[x].son[!p], val);
        pushUp(x);
    }
}

int query(int x, int val) {
    if (!x)
        return 0;
    if ((LL)a[tree[x].val]*a[val] <= k)
        return tree[tree[x].son[0]].size + 1 + query(tree[x].son[1], val);
    else
        return query(tree[x].son[0], val);
}

//initialize
inline void init() {
    edge_size = 0;
    memset(head, 0, sizeof(head));
    memset(isRoot, true, sizeof(isRoot));

    node_size = 0;
    rt = 0;

    ans = 0;
}

void dfs(int x) {
    ans += query(rt, x);

    ins(rt, x);

    for (int i = head[x]; i; i = edge[i].next)
        dfs(edge[i].to);

    del(rt, x);
}

int main() {
    //freopen("in", "r", stdin);
    srand(time(NULL));
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%lld", &n, &k);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n-1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            newEdge(u, v);
            isRoot[v] = false;
        }
        int root;
        for (int i = 1; i <= n; ++i)
            if (isRoot[i]) {
                root = i;
                break;
            }
        dfs(root);
        printf("%lld\n", ans);
    }
    return 0;
}

