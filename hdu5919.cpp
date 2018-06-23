/************************************************************************
* File Name : hdu5919.cpp
* Purpose : chairmanTree + binarySearchAnswer
* Creation Date : 2016年10月12日
* Last Modified : 2016年10月14日 星期五 14时48分52秒
* Created By : gou4shi1@qq.com
************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 200000 + 10;

typedef int ARRAY[MAXN];

ARRAY a, root, _L, _R;

int n;

//ChairmanTree
struct ChairmanTreeNode {
    int s, l, r;
} tree[MAXN * 50];

int node_size;

inline void newNode(int &x, int sum, int L, int R) {
    x = ++node_size;
    tree[x].s = sum;
    tree[x].l = L;
    tree[x].r = R;
}

void update(int &rt, int pre_rt, int pos, int l, int r, int v) {
    newNode(rt, tree[pre_rt].s + v, tree[pre_rt].l, tree[pre_rt].r);
    if  (l == r)
        return;
    int m = (l + r) >> 1;
    if (pos <= m)
        update(tree[rt].l, tree[pre_rt].l, pos, l, m, v);
    else
        update(tree[rt].r, tree[pre_rt].r, pos, m+1, r, v);
}

int query(int rt, int pos) {
    int ret = 0;
    int l = 1, r = n;
    while (pos < r) {
        int m = (l+r) >> 1;
        if (pos <= m) {
            r = m;
            rt = tree[rt].l;
        } else {
            ret += tree[tree[rt].l].s;
            rt = tree[rt].r;
            l = m + 1;
        }
    }
    return ret + tree[rt].s;
}

inline void init() {
        node_size = 0;
        tree[0].s = 0;
        tree[0].l = 0;
        tree[0].r = 0;
        root[n+1] = 0;
}

//main
int main() {
    //freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d:", kase);

        int m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d%d", &_L[i], &_R[i]);

        map<int, int>mp;
        init();
        for (int i = n; i >= 1; --i) {
            if (!mp.count(a[i]))
                update(root[i], root[i+1], i, 1, n, 1);
            else {
                int temp;
                update(temp, root[i+1], mp[a[i]], 1, n, -1);
                update(root[i], temp, i, 1, n, 1);
            }
            mp[a[i]] = i;
        }

        int _ans = 0;
        for (int i = 1; i <= m; ++i) {
            int L, R;
            L = min( (_L[i]+_ans)%n + 1, (_R[i]+_ans)%n + 1 );
            R = max( (_L[i]+_ans)%n + 1, (_R[i]+_ans)%n + 1 );
            int num = query(root[L], R), k;
            if (num & 1)
                k = (num>>1) + 1;
            else
                k = num >> 1;
            int l = L, r = R, mid;
            while (l < r) {
                mid = (l+r) >> 1;
                if (query(root[L], mid) >= k)
                    r = mid;
                else
                    l = mid + 1;
            }
            _ans = l;
            printf(" %d", _ans);
        }
        printf("\n");
    }
    return 0;
}

