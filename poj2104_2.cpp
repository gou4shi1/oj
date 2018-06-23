/************************************************************************
* File Name : poj2104_2.cpp
* Purpose : Chairman Tree
* Creation Date : 2017年10月09日
* Last Modified : 2017年10月10日 星期二 00时43分50秒
* Created By : admin@goushi.me
************************************************************************/
#include <cstdio>
#include <algorithm>

using namespace std;

// const
const int MAXN = 100000 + 10;
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

ARRAY a, root;

// hash
int h[MAXN];
int hs;
#define _h(x) (lower_bound(h, h+hs, x)-h)

// Chairman Tree
struct Tree {
    int s, l, r;
}tree[MAXN*20];
int ts;

void newNode(int &x, int s, int l, int r) {
    x = ++ts;
    tree[x] = {s, l, r};
}

void build(int &rt, int pre_rt, int l, int r, int p) {
    newNode(rt, tree[pre_rt].s+1, tree[pre_rt].l, tree[pre_rt].r);
    if (l == r)
        return;
    int m = (l +r) >> 1;
    if (p <= m)
        build(tree[rt].l, tree[pre_rt].l, l, m, p);
    else
        build(tree[rt].r, tree[pre_rt].r, m+1, r, p);
}

int query(int S, int E, int l, int r, int k) {
    if (l == r)
        return l;
    int m = (l + r) >> 1;
    int s = tree[tree[E].l].s - tree[tree[S].l].s;
    if (k <= s)
        return query(tree[S].l, tree[E].l, l, m, k);
    return query(tree[S].r, tree[E].r, m+1, r, k-s);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        h[hs++] = a[i];
    }
    sort(h, h+hs);
    hs = unique(h, h+hs) - h;
    for (int i = 1; i <= n; ++i) 
        build(root[i], root[i-1], 0, hs-1, _h(a[i]));
    for (int i = 1; i <= m; ++i) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", h[query(root[l-1], root[r], 0, hs-1, k)]);
    }

    return 0;
}
