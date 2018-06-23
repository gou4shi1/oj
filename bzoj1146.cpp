/************************************************************************
 * File Name : bzoj1146.cpp
 * Purpose : bzoj1146 : heavy-light-decomposition + SegmentTree + SplayTree + binary-search-answer
 * Creation Date : 2016年09月29日
 * Last Modified : 2016年10月06日 星期四 18时15分32秒
 * Created By : gou4shi1@qq.com
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define key_pos ch[ch[root][1]][0]

const int MAXN = 80000 + 10;
const int MAXM = 4000000 + 10;
const int MIN = 0;
const int MAX = 1E8 + 10;

typedef int ARRAY[MAXN];
typedef int ARRAY2[MAXM];

ARRAY val, head, fa, depth, size, h_son, pos, arc_pos, top;
int edge_size, pos_size, now;

struct Edge {
    int to, next;
} edge[MAXN << 1];

struct SegTree {
    int l, r;
    int root;

    inline int mid() {
        return (l+r) >> 1;
    }
} tree[MAXN << 2];

struct SplayTree {
    int ch[MAXM][2];
    ARRAY2 fa,sz,val;
    int node_size;

    void newNode(int &x, int y, int v) {
        x = ++node_size;
        sz[x] = 1;
        ch[x][0] = ch[x][1] = 0;
        fa[x] = y;
        val[x] = v;
    }

    void init(int &x) {
        newNode(x, 0, -1);
        newNode(ch[x][1], x, MAX);
        pushUp(ch[x][1]);
        pushUp(x);
    }

    void pushUp(int x) {
        if (!x)
            return;
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
    }

    int sgn(int x) {
        return x == ch[fa[x]][1];
    }

    void setCh(int y, int s, int x) {
        ch[y][s] = x;
        fa[x] = y;
    }

    void rotate(int x, int s) {
        int y = fa[x];
        int z = fa[y];
        setCh(y, !s, ch[x][s]);
        if (z)
            setCh(z, sgn(y), x);
        fa[x] = z;
        setCh(x, s, y);
        pushUp(y);
    }

    void splay(int x, int goal = 0) {
        if (!x)
            return;
        while (fa[x] != goal) {
            int y = fa[x];
            int z = fa[y];
            if (z == goal) {
                rotate(x, !sgn(x));
                break;
            } else if (ch[z][0] == y) {
                ch[y][0] == x ? rotate(y, 1) : rotate(x, 0);
                rotate(x, 1);
            } else {
                ch[y][1] == x ?  rotate(y, 0) : rotate(x, 1);
                rotate(x, 0);
            }
        }
        pushUp(x);
        if (!goal)
            tree[now].root = x;
    }

    int getKth(int x, int k) {
        while (x) {
            if (sz[ch[x][0]] + 1 == k)
                return x;
            else if (sz[ch[x][0]] + 1 > k)
                x = ch[x][0];
            else {
                k -= sz[ch[x][0]] + 1;
                x = ch[x][1];
            }
        }
        return x;
    }

    int getSE(int v) {
        int x = tree[now].root;
        int rank = 0;
        while (x) {
            if (val[x] <= v) {
                rank += sz[ch[x][0]] + 1;
                x = ch[x][1];
            } else
                x = ch[x][0];
        }
        return rank;
    }

    int getGE(int v) {
        int x = tree[now].root;
        int ans = 0;
        while (x) {
            if (val[x] >= v) {
                ans += sz[ch[x][1]] + 1;
                x = ch[x][0];
            } else
                x = ch[x][1];
        }
        return ans;
    }

    void ins(int v) {
        int k = getSE(v);
        splay(getKth(tree[now].root, k), 0);
        splay(getKth(tree[now].root, k+1), tree[now].root);

        int root = tree[now].root;
        newNode(key_pos, ch[root][1], v);
        pushUp(ch[root][1]);
        pushUp(root);
    }

    void del(int v) {
        int k = getSE(v);
        splay(getKth(tree[now].root, k-1), 0);
        splay(getKth(tree[now].root, k+1), tree[now].root);

        int root = tree[now].root;
        val[key_pos] = fa[key_pos] = 0;
        key_pos = 0;
        pushUp(ch[root][1]);
        pushUp(root);
    }
} sp;

void init() {
    memset(val, 0, sizeof(val));
    memset(head, 0, sizeof(head));
    memset(fa, 0, sizeof(fa));
    memset(depth, 0, sizeof(depth));
    memset(size, 0, sizeof(size));
    memset(h_son, 0, sizeof(h_son));
    edge_size = 0;
    pos_size = 0;
    now = 0;
}

inline void addEdge(int u, int v) {
    edge[++edge_size].to = v;
    edge[edge_size].next = head[u];
    head[u] = edge_size;
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

void segTreeBuild(int rt, int l, int r) {
    tree[rt].l = l;
    tree[rt].r = r;
    sp.init(tree[rt].root);
    if (l == r)
        return;
    segTreeBuild(rt << 1, l, tree[rt].mid());
    segTreeBuild(rt<<1 | 1, tree[rt].mid()+1, r);
}

void segTreeModify(int pos, int old, int new_val, int rt) {
    now = rt;

    if (old != -1)
        sp.del(old);
    sp.ins(new_val);

    if (tree[rt].l == tree[rt].r)
        return;
    if (pos <= tree[rt].mid())
        segTreeModify(pos, old, new_val, rt << 1);
    else
        segTreeModify(pos, old, new_val, rt<<1 | 1);
}

int segTreeQueryGE(int l, int r, int v, int rt) {
    now = rt;

    if (l <= tree[rt].l && tree[rt].r <= r)
        return sp.getGE(v) - 1;
    if (r <= tree[rt].mid())
        return segTreeQueryGE(l, r, v, rt << 1);
    if (l > tree[rt].mid())
        return segTreeQueryGE(l, r, v, rt<<1 | 1);
    return segTreeQueryGE(l, r, v, rt << 1) + segTreeQueryGE(l, r, v, rt<<1 | 1);
}

int askGE(int a, int b, int v) {
    int ans = 0;
    while (top[a] != top[b]) {
        if (depth[top[a]] < depth[top[b]])
            swap(a,b);
        ans += segTreeQueryGE(pos[top[a]], pos[a], v, 1);
        a = fa[top[a]];
    }
    if (depth[a] > depth[b])
        swap(a,b);
    ans += segTreeQueryGE(pos[a], pos[b], v, 1);
    return ans;
}

int binAns(int a, int b, int k) {
    int ans = -1;
    int l = MIN, r = MAX;
    while (l <= r) {
        int mid = (l+r) >> 1;
        int ge = askGE(a, b, mid);
        if (ge >= k) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ans;
}

int main() {
    int n, q;
    while (~scanf("%d%d", &n, &q)) {
        init();
        for (int i = 1; i <= n; ++i)
            scanf("%d", &val[i]);
        for (int i = 1; i <= n-1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u,v);
            addEdge(v,u);
        }
        HLD_DFS1(1);
        HLD_DFS2(1, 1);
        segTreeBuild(1, 1, n);
        for (int i = 1; i <= n; ++i)
            segTreeModify(pos[i], -1, val[i], 1);

        while (q--) {
            int k, a, b;
            scanf("%d%d%d", &k, &a, &b);
            if (!k) {
                segTreeModify(pos[a], val[a], b, 1);
                val[a] = b;
                continue;
            } else {
                int ans = binAns(a, b, k);
                if (~ans)
                    printf("%d\n", ans);
                else
                    puts("invalid request!");
            }
        }
    }
    return 0;
}

