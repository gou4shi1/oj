/************************************************************************
* File Name : cf794A.cpp
* Purpose : water
* Creation Date : 2017年05月13日
* Last Modified : 2017年05月13日 星期六 18时38分41秒
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

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

int main() {
    //freopen("in", "r", stdin);
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int d;
        scanf("%d", &d);
        if (b < d && d < c)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}

