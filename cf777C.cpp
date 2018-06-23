/************************************************************************
* File Name : cf777C.cpp
* Purpose : dp
* Creation Date : 2017年04月05日
* Last Modified : 2017年04月05日 星期三 23时47分46秒
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

ARRAY a, b, dp_a, dp_b, dp_max;

int main() {
    //freopen("in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[j]);
            if (a[j] >= b[j])
                dp_a[j] = dp_b[j] + 1;
            else
                dp_a[j] = 1;
            dp_max[i] = max(dp_max[i], dp_a[j]);
            b[j] = a[j];
            dp_b[j] = dp_a[j];
        }
    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        puts(dp_max[r] >= (r-l+1) ? "Yes" : "No");
    }
    return 0;
}

