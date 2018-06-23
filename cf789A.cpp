/************************************************************************
* File Name : cf789A.cpp
* Purpose : training
* Creation Date : 2017年04月02日
* Last Modified : 2017年04月02日 星期日 01时54分35秒
* Created By : gou4shi1@qq.com
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

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

int main() {
    //freopen("in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    int ans(0);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ans += a / k + ((a % k) ? 1 : 0);
    }
    printf("%d\n", ans / 2 + ((ans % 2) ? 1 : 0));
    return 0;
}

