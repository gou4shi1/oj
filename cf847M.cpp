/************************************************************************
* File Name : cf847M.cpp
* Purpose : water
* Creation Date : 2017年09月18日
* Last Modified : 2017年09月18日 星期一 22时16分43秒
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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    int a, b, d;
    scanf("%d%d", &a, &b);
    d = b - a;
    a = b;
    bool flag = true;
    for (int i = 3; i <= n; ++i) {
        scanf("%d", &b);
        if (b - a != d)
            flag = false;
        a = b;
    }
    if (flag)
        b = a + d;
    else
        b = a;
    printf("%d\n", b);

    return 0;
}

