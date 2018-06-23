/************************************************************************
* File Name : hdu5122.cpp
* Purpose : water
* Creation Date : 2017年10月14日
* Last Modified : 2017年10月14日 星期六 13时39分09秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 1000000 + 10;
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
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))
typedef int itn;

int a[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T, Ti(0);
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        int m = a[n], ans = 0;
        for (int i = n; i >= 1; --i) {
            if (m < a[i])
                ++ans;
            m = min(m, a[i]);
        }
        printf("Case #%d: %d\n", ++Ti, ans);
    }

    return 0;
}

