/************************************************************************
* File Name : cf825C.cpp
* Purpose : greedy
* Creation Date : 2017年08月07日
* Last Modified : 2017年08月07日 星期一 15时53分20秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 1000 + 10;
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

ARRAY a;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int ans = 0;
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (2 * k < a[i]) {
            while (2 * k < a[i]) {
                k *= 2;
                ++ans;
            }
        }
        if (k < a[i])
            k = a[i];
    }
    printf("%d\n", ans);

    return 0;
}

