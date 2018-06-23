/************************************************************************
* File Name : cf766B.cpp
* Purpose : training
* Creation Date : 2017年03月26日
* Last Modified : 2017年03月26日 星期日 13时17分36秒
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

ARRAY a;

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    bool result = false;
    for (int i = 2; i != n; ++i)
        if (a[i] < a[i - 1] + a[i - 2]) {
            result = true;
            break;
        }
    puts(result ? "YES" : "NO");
    return 0;
}
