/************************************************************************
* File Name : cf797B.cpp
* Purpose : training
* Creation Date : 2017年04月15日
* Last Modified : 2017年04月15日 星期六 23时35分56秒
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
const int INF = 0x3f3f3f3f;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY a;

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    int sum(0), b(0), c(0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > 0)
            sum +=a[i];
        if (a[i] > 0 && (a[i] % 2))
            if (!b || a[i] < b)
                b = a[i];
        if (a[i] < 0 && (-1 * a[i] % 2))
            if (!c || -1 * a[i] < c)
                c = -1 * a[i];
    }
    if (!(sum % 2)) {
        if (!b)
            sum -= c;
        else if (!c)
            sum -= b;
        else
            sum -= min(b, c);
    }
    printf("%d\n", sum);
    return 0;
}


