/************************************************************************
* File Name : cf854B.cpp
* Purpose : water
* Creation Date : 2017年09月08日
* Last Modified : 2017年09月08日 星期五 23时01分17秒
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
#define mp makde_pair
#define fi first
#define se second

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    if (k == n || k == 0) {
        puts("0 0");
        return 0;
    }

    printf("1 ");
    int t = n / 3;
    int p = n - 3*t;
    int q = k - t;
    if (q <= 0)
        printf("%d\n", 2*k);
    else {
        if (q < p)
            printf("%d\n", 2*t + 1);
        else
            printf("%d\n", 2*t - (q-p));
    }

    return 0;
}

