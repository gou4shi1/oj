/************************************************************************
* File Name : cf837C.cpp
* Purpose : water
* Creation Date : 2017年08月14日
* Last Modified : 2017年08月14日 星期一 16时11分50秒
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

int n, a, b;

bool fit(int x1, int y1, int x2, int y2) {
    bool ret = false;
    ret |= (x1+x2 <= a && max(y1, y2) <= b) || (y1+y2 <= a && max(x1, x2) <= b) || (x1+y2 <= a && max(y1, x2) <= b) || (y1+x2 <= a && max(x1, y2) <= b);
    swap(a, b);
    ret |= (x1+x2 <= a && max(y1, y2) <= b) || (y1+y2 <= a && max(x1, x2) <= b) || (x1+y2 <= a && max(y1, x2) <= b) || (y1+x2 <= a && max(x1, y2) <= b);
    swap(a, b);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &a, &b);
    int x[233], y[233];
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (fit(x[i], y[i], x[j], y[j]))
                ans = max(ans, x[i]*y[i] + x[j]*y[j]);

    printf("%d\n", ans);

    return 0;
}

