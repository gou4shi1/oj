/************************************************************************
* File Name : cf825E.cpp
* Purpose : heap
* Creation Date : 2017年08月07日
* Last Modified : 2017年08月07日 星期一 22时12分39秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100000 + 10;
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

// edge
struct Edge {
    int to, next;
} edge[MAXN];

int edge_size;
ARRAY head;

void addEdge(int u, int v) {
    edge[++edge_size].next = head[u];
    edge[edge_size].to = v;
    head[u] = edge_size;
}

// heap
#define LC (k * 2)
#define RC (k * 2 + 1)
#define FA (k / 2)

PII a[MAXN];
int a_size;
ARRAY b;

void heapify_down(int k) {
    if (k >= a_size)
        return;
    int lc = LC, rc = RC, _min = k;
    if (lc <= a_size && a[lc] < a[_min])
        _min = lc;
    if (rc <= a_size && a[rc] < a[_min])
        _min = rc;
    if (_min != k) {
        swap(a[_min], a[k]);
        swap(b[-a[_min].se], b[-a[k].se]);
        heapify_down(_min);
    }
}

void heapify_up(int k) {
    if (k > a_size)
        return;
    while (k > 1 && a[k] < a[FA]) {
        swap(a[k], a[FA]);
        swap(b[-a[k].se], b[-a[FA].se]);
        k /= 2;
    }
}

void heap_build_from_array() {
    int l = a_size / 2;
    for (int i = l; i > 0; --i)
        heapify_down(i);
}

int pop() {
    int ret = -a[1].se;
    swap(a[1], a[a_size]);
    swap(b[-a[1].se], b[-a[a_size].se]);
    --a_size;
    heapify_down(1);
    return ret;
}

ARRAY ans;

// debug
void print_a() {
    for (int i = 1; i <= 100; ++i)
        printf("%d: %d %d\n", i, a[i].fi, a[i].se);
}

void print_b() {
    for (int i = 1; i <= 100; ++i)
        printf("%d: %d\n", i, b[i]);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int v, u;
        scanf("%d%d", &v, &u);
        addEdge(u, v);
        ++a[v].fi;
    }

    for (int i = 1; i <= n; ++i) {
        a[i].se = -i;
        b[i] = i;
    }
    a_size = n;

    heap_build_from_array();
    for (int i = n; i >= 1; --i) {
        int k = pop();
        ans[k] = i;
        for (int j = head[k]; j; j = edge[j].next) {
            int v = edge[j].to;
            a[b[v]].fi--;
            heapify_up(b[v]);
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}

