/************************************************************************
* File Name : cf959B.cpp
* Purpose : dsu
* Creation Date : 2018年04月15日
* Last Modified : 2018年04月15日 星期日 22时09分38秒
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
#define lld I64d
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

int n, k, m;
int a[N];
map<string, int> _map;

// dsu
int fa[N];

void init() {
    for (int i = 0; i <= n; ++i)
        fa[i] = i;
}

int find(int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
    int fu = find(u), fv = find(v);
    a[fv] = min(a[fv], a[fu]);
    fa[fu] = fv;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    cin >> n >> k >> m;
    init();
    for (int i = 1; i <= n; ++i) {
        string w;
        cin >> w;
        _map[w] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; ++i) {
        int x, t0, t;
        cin >> x >> t0;
        while (--x) {
            cin >> t;
            unin(t0, t);
        }
    }

    LL sum = 0;
    for (int i = 1; i <= m; ++i) {
        string w;
        cin >> w;
        sum += a[find(_map[w])];
    }

    cout << sum << endl;

    return 0;
}

