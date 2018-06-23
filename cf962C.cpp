/************************************************************************
* File Name : cf962C.cpp
* Purpose : water
* Creation Date : 2018年05月05日
* Last Modified : 2018年05月05日 星期六 12时16分39秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 233 + 10;
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

int n, l;
int a[N];

bool check(int x) {
    if (!x)
        return false;
    int y = sqrt(x);
    return y * y == x;
}

int dfs(int s, int k) {
    if (!k) {
        return check(s) ? 0 : -1;
    }

    int ret = -1;
    if (!(!s && !a[k]))
        ret = dfs(s * 10 + a[k], k - 1);
    int t = dfs(s, k - 1);
    if (t != -1) {
        if (ret == -1 || ret > 1 + t)
        ret =  1 + t;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    while (n) {
        a[++l] = n % 10;
        n /= 10;
    }
    printf("%d\n", dfs(0, l));

    return 0;
}

