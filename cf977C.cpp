/************************************************************************
* File Name : cf977C.cpp
* Purpose : water
* Creation Date : 2018年05月06日
* Last Modified : 2018年05月06日 星期日 23时26分59秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 200000 + 10;
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

int a[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);

    if (k == 0) {
        int x = a[0] - 1;
        if (x < 1) {
            puts("-1");
        } else {
            printf("%d\n", x);
        }
        return 0;
    }

    if (k == n) {
        int x = a[n - 1];
        printf("%d\n", x);
        return 0;
    }

    if (a[k] == a[k - 1]) {
        puts("-1");
        return 0;
    }

    int x = a[k] - 1;
    if (x < 1)
        puts("-1");
    else 
        printf("%d\n", x);

    return 0;
}

