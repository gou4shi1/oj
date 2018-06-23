/************************************************************************
* File Name : cf854A.cpp
* Purpose : water
* Creation Date : 2017年09月08日
* Last Modified : 2017年09月08日 星期五 19时32分21秒
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
    int a = n / 2;
    int b = n - a;
    while (a > 1 && __gcd(a,b) > 1) {
        --a;
        ++b;
    }
    printf("%d %d", a, b);

    return 0;
}

