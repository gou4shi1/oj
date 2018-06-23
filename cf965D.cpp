/************************************************************************
* File Name : cf965D.cpp
* Purpose : greedy
* Creation Date : 2018年05月04日
* Last Modified : 2018年05月04日 星期五 23时38分59秒
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

int a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int w, l;
    scanf("%d%d", &w, &l);
    for (int i = 1; i < w; ++i) {
        scanf("%d", &a[i]);
    }

    int p = 1;
    for (int i = 1; i <= l; ++i)
        b[i] = a[i];
    for (int i = l + 1; i < w; ++i) {
        p = max(p, i - l);
        while (b[i] < a[i] && p < i) {
            int t = min(a[i] - b[i], b[p]);
            b[i] += t;
            b[p] -= t;
            if (b[p] == 0)
                ++p;
        }
    }

    int ans = 0;
    for (int i = w - l; i < w; ++i)
        ans += b[i];
    printf("%d\n", ans);

    /*
    puts("############");
    for (int i = 1; i < w; ++i)
        printf("%d ", b[i]);
    printf("\n");
    puts("############");
    */

    return 0;
}

