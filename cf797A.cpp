/************************************************************************
* File Name : cf797A.cpp
* Purpose : training
* Creation Date : 2017年04月16日
* Last Modified : 2017年04月16日 星期日 00时43分56秒
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

ARRAY f;
int m;
bool flag;

void solve(int n, int k) {
    if (n < 2) {
        flag = true;
        return;
    }
    if (k == 1) {
        f[m++] = n;
        return;
    }

    for (int i = 2; i <= n; ++i)
        if (n % i == 0) {
            f[m++] = i;
            solve(n / i, k - 1);
            return;
        }
}

int main() {
    //freopen("in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    solve(n, k);
    if (flag) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < k; ++i)
        printf("%d ", f[i]);
    printf("\n");
    return 0;
}

