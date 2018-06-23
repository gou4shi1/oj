/************************************************************************
* File Name : bzoj1146_2.cpp
* Purpose : bzoj1146 : heavy-light-decomposition + binaryIndexedTree + chairmenTree
* Creation Date : 2016年10月01日
* Last Modified : 2016年10月12日 星期三 23时12分46秒
* Created By : gou4shi1@qq.com
6***********************************************************************/
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

const int MAXN = 80000 + 10;

typedef int ARRAY[MAXN];
typedef int ARRAY2[MAXN << 1];

ARRAY val, num,  head, fa, depth, size, h_son, pos, arc_pos, top;
ARRAY2 HASH, root, L, R;
int edge_size, pos_size, node_size, num_size, L_size, R_size, seg_size, n;

struct Edge {
    int to, next;
} edge[MAXN << 1];

inline void addEdge(int u, int v) {
    edge[++edge_size].to = v;
    edge[edge_size].next = head[u];
    head[u] = edge_size;
}

inline int read() {
    char c = getchar();
    for (; !isdigit(c); c = getchar());
    int ret = 0;
    for (; isdigit(c); c = getchar())
        ret = ret * 10 + c - '0';
    return ret;
}

struct Query {
    int k, a, b;

    void init() {
        k = read();
        a = read();
        b = read();
    }
} q[MAXN];

struct ChairTreeNode {
    int s, l, r;
} tree[MAXN * 100];

void newNode(int &x, int sum, int L, int R) {
    x = ++node_size;
    tree[x].s = sum;
    tree[x].l = L;
    tree[x].r = R;
}

void init() {
    memset(head, 0, sizeof(head));

    memset(h_son, 0, sizeof(h_son));
    fa[1] = 0;
    depth[1] = 0;
    size[0] = 0;

    memset(root, 0, sizeof(root));
    tree[0].s = tree[0].l = tree[0].r = 0;

    edge_size = 0;
    pos_size = 0;
    node_size = 0;
    num_size = 0;
}

void HLD_DFS1(int u) {
    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        depth[v] = depth[u] + 1;
        HLD_DFS1(v);
        size[u] += size[v];
        if (size[v] > size[h_son[u]])
            h_son[u] = v;
    }
}

void HLD_DFS2(int u, int u_top) {
    pos[u] = ++pos_size;
    arc_pos[pos[u]] = u;
    top[u] = u_top;
    if (!h_son[u])
        return;
    HLD_DFS2(h_son[u], u_top);
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa[u] || v == h_son[u])
            continue;
        HLD_DFS2(v, v);
    }
}

void chairTreeBuild(int &rt, int pre_rt, int pos, int l, int r) {
    newNode(rt, tree[pre_rt].s + 1, tree[pre_rt].l, tree[pre_rt].r);
    if (l == r)
        return;
    int m = (l + r) >> 1;
    if (pos <= m)
        chairTreeBuild(tree[rt].l, tree[pre_rt].l, pos, l, m);
    else
        chairTreeBuild(tree[rt].r, tree[pre_rt].r, pos, m+1, r);
}

void chairTreeModify(int &rt, int val, int pos, int l, int r) {
    if (!rt)
        newNode(rt, 0, 0, 0);
    tree[rt].s += val;
    if (l == r)
        return;
    int m = (l+r) >> 1;
    if (pos <= m)
        chairTreeModify(tree[rt].l, val, pos, l, m);
    else
        chairTreeModify(tree[rt].r, val, pos, m+1, r);
}

int chairTreeQueryKth(int l, int r, int k) {
    if (l == r)
        return l;
    int m = (l+r) >> 1, cnt = 0;
    for (int i = 0; i != R_size; ++i)
        cnt += tree[tree[R[i]].l].s;
    for (int i = 0; i != L_size; ++i)
        cnt -= tree[tree[L[i]].l].s;
    if (k <= cnt) {
        for (int i = 0; i != R_size; ++i)
            R[i] = tree[R[i]].l;
        for (int i = 0; i != L_size; ++i)
            L[i] = tree[L[i]].l;
        return chairTreeQueryKth(l, m, k);
    } else {
        for (int i = 0; i != R_size; ++i)
            R[i] = tree[R[i]].r;
        for (int i = 0; i != L_size; ++i)
            L[i] = tree[L[i]].r;
        return chairTreeQueryKth(m+1, r, k-cnt);
    }
}

inline int lowBit(int x) {
    return x & (-x);
}

void BIT_query(int l, int r) {
    seg_size += r - l + 1;
    R[R_size++] = root[r+n];
    for (int rr = r; rr; rr -= lowBit(rr))
        R[R_size++] = root[rr];
    L[L_size++] = root[l-1 == 0 ? 0 : l-1 + n];
    for (int ll = l-1; ll; ll -= lowBit(ll))
        L[L_size++] = root[ll];
}

void BIT_modify(int pos, int sgn, int val) {
    for (int i = pos; i <= n; i += lowBit(i))
        chairTreeModify(root[i], sgn, val, 1, num_size);
}

int ask(int a, int b, int k) {
    L_size = R_size = seg_size = 0;
    for (; top[a] != top[b]; a = fa[top[a]]) {
        if (depth[top[a]] < depth[top[b]])
            swap(a, b);
        BIT_query(pos[top[a]], pos[a]);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    BIT_query(pos[a], pos[b]);
    if (seg_size < k)
        return -1;
    return HASH[chairTreeQueryKth(1, num_size, seg_size-k+1)];
}

int main() {
    int Q;
    while (~scanf("%d%d", &n, &Q)) {
        init();

        for (int i = 1; i <= n; ++i) {
            val[i] = read();
            HASH[++num_size] = val[i];
        }
        for (int i = 1; i <= n-1; ++i) {
            int u = read(), v = read();
            addEdge(u,v);
            addEdge(v,u);
        }
        for (int i = 1; i <= Q; ++i) {
            q[i].init();
            if (!q[i].k)
                HASH[++num_size] = q[i].b;
        }
        --num_size;
        sort(HASH+1, HASH+1 + num_size);
        num_size = unique(HASH+1, HASH+1 + num_size) - (HASH+1);
        for (int i  = 1; i <= n; ++i)
            num[i] = lower_bound(HASH+1, HASH+1 + num_size, val[i]) - HASH;

        HLD_DFS1(1);
        HLD_DFS2(1, 1);

        for (int i = 1; i <= n; ++i)
            chairTreeBuild(root[i+n], root[i+n - 1], num[arc_pos[i]], 1, num_size);

        for (int i = 1; i <= Q; ++i) {
            if (!q[i].k) {
                BIT_modify(pos[q[i].a], -1, num[q[i].a]);
                num[q[i].a] = lower_bound(HASH+1, HASH+1+num_size, q[i].b) - HASH;
                BIT_modify(pos[q[i].a], 1, num[q[i].a]);
            } else {
                int ans = ask(q[i].a, q[i].b, q[i].k);
                if (~ans)
                    printf("%d\n", ans);
                else
                    puts("invalid request!");
            }
        }
    }
    return 0;
}

