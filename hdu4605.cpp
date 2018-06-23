/************************************************************************
* File Name : hdu4602.cpp
* Purpose : BIT
* Creation Date : 2017年10月06日
* Last Modified : 2017年10月06日 星期五 21时59分49秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 400000 + 10;
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

// vector
#define pb push_back

ARRAY w, ls, rs, X, Y, Z, l, r;
vector<int> vec[MAXN];
vector<int> vec2[MAXN];
int h[MAXN];
int hs;
map<int, int> _h;
FLAG notRoot;

int lowbit(int x) {
    return x&(-x);
}

int sum(int arr[], int n) {
    int ret(0);
    for (int i = n; i; i -= lowbit(i))
        ret += arr[i];
    return ret;
}

void add(int arr[], int x, int c) {
    for (int i = x; i <= hs; i += lowbit(i))
        arr[i] += c;
}

void dfs(int u) {
    int vs = vec[u].size();
    for (int i = 0; i < vs; ++i) {
        int k = vec2[u][i], x = _h[vec[u][i]];
        if ((sum(l, x)-sum(l, x-1)) || (sum(r, x)-sum(r, x-1))) {
            Z[k] = 1;
            continue;
        }
        X[k] = sum(r, x);
        Y[k] = 3 * sum(r, x);
        Y[k] += 3 * sum(l, x);
        Y[k] += sum(l, hs) - sum(l, x);
        Y[k] += sum(r, hs) - sum(r, x);
    }

    int wu = _h[w[u]];
    if (ls[u]) {
        add(l, wu, 1);
        dfs(ls[u]);
        add(l, wu, -1);
    }
    if (rs[u]) {
        add(r, wu, 1);
        dfs(rs[u]);
        add(r, wu, -1);
    }
}

void init() {
    hs = 0;
    _h.clear();
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(Z, 0, sizeof(Z));
    memset(notRoot, 0, sizeof(notRoot));
    for (int i = 0; i < MAXN; ++i)
        vec[i].clear();
    for (int i = 0; i < MAXN; ++i)
        vec2[i].clear();
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
            scanf("%d", w+i);
            h[++hs] = w[i];
        }
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            int u, a, b;
            scanf("%d%d%d", &u, &a, &b);
            notRoot[a] = notRoot[b] = true;
            ls[u] = a;
            rs[u] = b;
        }
        int root;
        for (int i = 1; i <= n; ++i)
            if (!notRoot[i]) {
                root = i;
                break;
            }
        int q;
        scanf("%d", &q);
        for (int i = 1; i <= q; ++i) {
            int v, x;
            scanf("%d%d", &v, &x);
            h[++hs] = x;
            vec[v].pb(x);
            vec2[v].pb(i);
        }

        sort(h+1, h+1+hs);
        hs = unique(h+1, h+1+hs) - (h+1);
        for (int i = 1; i <= hs; ++i)
            _h[h[i]] = i;

        dfs(root);
        for (int i = 1; i <= q; ++i) {
            if (Z[i])
                puts("0");
            else
                printf("%d %d\n", X[i], Y[i]);
        }
    }

    return 0;
}

