/************************************************************************
* File Name : cf847G.cpp
* Purpose : water
* Creation Date : 2017年09月18日
* Last Modified : 2017年09月18日 星期一 21时57分01秒
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

int a[10];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d%*c", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 7; ++j) {
            char t;
            scanf("%c", &t);
            a[j] += t-'0';
        }
        scanf("%*c");
    }
    int m = 0;
    for (int i = 0; i < 7; ++i)
        m = max(m, a[i]);

    printf("%d\n", m);

    return 0;
}

