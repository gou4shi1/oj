/************************************************************************
* File Name : cf808B.cpp
* Purpose : water
* Creation Date : 2017年05月15日
* Last Modified : 2017年05月15日 星期一 23时56分14秒
* Created By : admin@goushi.me
************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 200000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY a;

int main() {
    //freopen("in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    LL sum = 0;
    for (int i = 1; i < k; ++i)
        sum += a[i];
    a[0] = 0;
    double ans = 0;
    for (int i = 1; i <= n-k+1; ++i) {
        sum -= a[i - 1];
        sum += a[i + k - 1];
        ans += (double)sum / (n-k+1);
    }
    printf("%.6lf", ans);
    return 0;
}

