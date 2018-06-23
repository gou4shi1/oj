/************************************************************************
* File Name : cf744B.cpp
* Purpose : binary_search
* Creation Date : 2017年04月15日
* Last Modified : 2017年04月15日 星期六 16时28分35秒
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

const int MAXN = 1000 + 10;
const int INF = 0x3f3f3f3f;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY mm;
int n;

void solve() {
    for (int i = 0; i < 10; ++i) {
        if (!(n >> i))
            break;
        for (int j = 0; j < 2; ++j) {
            int m(0);
            for (int k = 1; k <= n; ++k)
                if ((k>>i & 1) == j)
                    ++m;
            printf("%d\n", m);

            for (int k = 1; k <= n; ++k)
                if ((k>>i & 1) == j)
                    printf("%d ", k);
            printf("\n");
            fflush(stdout);

            for (int k = 1; k <= n; ++k) {
                int a;
                scanf("%d", &a);
                if ((k>>i & 1) == j)
                    continue;
                mm[k] = min(mm[k], a);
            }
        }
    }
}

void init() {
    for (int i = 1; i <= n; ++i)
        mm[i] = INF;
}

void out() {
    printf("-1\n");
    for (int i = 1; i < n; ++i)
        printf("%d ", mm[i]);
    printf("%d\n", mm[n]);
}

int main() {
    //freopen("in", "r", stdin);
    scanf("%d", &n);
    init();
    solve();
    out();
    return 0;
}

