/************************************************************************
* File Name : hdu4347.cpp
* Purpose : K-D Tree
* Creation Date : 2017年10月19日
* Last Modified : 2017年10月19日 星期四 15时36分57秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 50000 + 10;
const int K = 5;
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

int DIM;
int now_dim;

struct Node {
    int p[K];

    void input() {
        for (int i = 0; i < DIM; ++i)
            scanf("%d", p+i);
    }

    void output() const {
        for (int i = 0; i < DIM-1; ++i)
            printf("%d ", p[i]);
        printf("%d\n", p[DIM-1]);
    }
}a[N], tree[N*4];

bool operator < (const Node &a, const Node &b) {
    return a.p[now_dim] < b.p[now_dim];
}

inline LL dis(Node &a, Node &b) {
    LL ret = 0;
    for (int k = 0; k < DIM; ++k)
        ret += sqr((LL)a.p[k]-b.p[k]);
    return ret;
}

bool exist[N*4]; 

void build(int l, int r, int rt, int dep) {
    if (l > r)
        return;
    exist[rt] = true;

    int m = (l + r) >> 1;
    now_dim = dep % DIM;
    nth_element(a+l, a+m, a+r+1);
    tree[rt] = a[m];
    build(ls, dep+1);
    build(rs, dep+1);
}

Node target;
typedef pair<LL, Node> PLN;
set<PLN> ans;
int m;

void query(int rt, int dep) {
    if (!exist[rt])
        return;

    now_dim = dep % DIM;
    int p = rr, q = lr;
    if (target < tree[rt])
        swap(p, q);
    query(p, dep+1);
    now_dim = dep % DIM;

    LL rt_dis = dis(target, tree[rt]);
    bool flag(0);
    if (ans.size() < m) {
        ans.insert(mp(rt_dis, tree[rt]));
        flag = true;
    } else  {
        auto it = ans.rbegin();
        if (rt_dis < (*it).fi) {
            ans.erase(*it);
            ans.insert(mp(rt_dis, tree[rt]));
        }
        it = ans.rbegin();
        if (sqr((LL)tree[rt].p[now_dim] - target.p[now_dim]) <= (*it).fi)
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

    int n;
    while (scanf("%d%d", &n, &DIM) == 2) {
        init();

        for (int i = 1; i <= n; ++i)
            a[i].input();
        build(1, n, 1, 0);

        int q;
        scanf("%d", &q);
        while (q--) {
            target.input();
            scanf("%d", &m);
            ans.clear();
            query(1, 0);
            printf("the closest %d points are:\n", m);
            for (auto it = ans.begin(); it != ans.end(); ++it)
                (*it).se.output();
        }
    }

    return 0;
}

