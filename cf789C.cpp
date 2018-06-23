/************************************************************************
* File Name : cf789C.cpp
* Purpose : training
* Creation Date : 2017年04月01日
* Last Modified : 2017年04月01日 星期六 15时56分53秒
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
#include <limits>

using namespace std;

const int MAXN = 100000 + 10;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY a, b, c;

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i)
        b[i] = (i % 2) ? abs(a[i] - a[i + 1]) : -1 * abs(a[i] - a[i + 1]);
    for (int i = 1; i < n; ++i)
        c[i] = (i % 2) ? -1 * abs(a[i] - a[i + 1]) : abs(a[i] - a[i + 1]);
    LL sum(b[1]), max_sum(b[1]);
    for (int i = 2; i < n; ++i) {
        if (sum < 0)
            sum = 0;
        sum += b[i];
        max_sum = max(max_sum, sum);
    }
    sum = c[2];
    max_sum = max(max_sum, sum);
    for (int i = 3; i < n; ++i) {
        if (sum < 0)
            sum = 0;
        sum += c[i];
        max_sum = max(max_sum, sum);
    }
    printf("%I64d\n", max_sum);
    return 0;
}

