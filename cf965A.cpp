/************************************************************************
* File Name : cf965A.cpp
* Purpose : water
* Creation Date : 2018年05月05日
* Last Modified : 2018年05月05日 星期六 00时25分08秒
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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int k, n, s, p;
    scanf("%d%d%d%d", &k, &n, &s, &p);
    int t = ceil(1.0 * n / s);
    printf("%d\n", (int)ceil(1.0 * k * t / p));

    return 0;
}

