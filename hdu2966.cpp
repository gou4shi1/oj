/************************************************************************
* File Name : hdu2966.cpp
* Purpose : K-D Tree
* Creation Date : 2017年10月19日
* Last Modified : 2017年10月19日 星期四 14时42分32秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100000 + 10;
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
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))
#define sqr(x) ((x)*(x))

// K-D Tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m-1, lr
#define rs m+1, r, rr

int now_dim;

struct Node {
    int p[2];
}a[N], b[N], tree[N*4];

bool operator < (const Node &a, const Node &b) {
    return a.p[now_dim] < b.p[now_dim];
}

inline LL dis(Node &a, Node &b) {
    return sqr((LL)a.p[0]-b.p[0]) + sqr((LL)a.p[1]-b.p[1]);
}

bool exist[N*4]; 

void build(int l, int r, int rt, int dep) {
    if (l > r)
        return;
    exist[rt] = true;

    int m = (l + r) >> 1;
    now_dim = dep % 2;
    nth_element(a+l, a+m, a+r+1);
    tree[rt] = a[m];
    build(ls, dep+1);
    build(rs, dep+1);
}

Node target;
LL ans_dis;

void query(int rt, int dep) {
    if (!exist[rt])
        return;

    now_dim = dep % 2;
    int p = rr, q = lr;
    if (target < tree[rt])
        swap(p, q);
    query(p, dep+1);
    now_dim = dep % 2;

    LL rt_dis = dis(target, tree[rt]);
    bool flag(0);
    if (ans_dis == -1) {
        if (rt_dis)
            ans_dis = rt_dis;
        flag = true;
    } else  {
        if (rt_dis && rt_dis < ans_dis)
            ans_dis = rt_dis;
        if (sqr((LL)tree[rt].p[now_dim] - target.p[now_dim]) <= ans_dis)
            flag = true;
    }
    if (flag)
        query(q, dep+1);
}

void init() {
    mst(exist, 0);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        init();

        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i].p[0], &a[i].p[1]);
            b[i] = a[i];
        }
        build(1, n, 1, 0);

        for (int i = 1; i <= n; ++i) {
            target = b[i];
            ans_dis = -1;
            query(1, 0);
            printf(LLD "\n", ans_dis);
        }
    }

    return 0;
}

