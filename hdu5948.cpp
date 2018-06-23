/************************************************************************
* File Name : hdu5948.cpp
* Purpose : water
* Creation Date : 2017年10月07日
* Last Modified : 2017年10月07日 星期六 13时40分54秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100000 + 10;
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

    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n",max(a+a+b, a+b+b));
    }

    return 0;
}

