/************************************************************************
* File Name : cf794B.cpp
* Purpose : water
* Creation Date : 2017年05月13日
* Last Modified : 2017年05月13日 星期六 18时43分13秒
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
    int n, h;
    scanf("%d%d", &n, &h);
    double h0 = sqrt((LL)h * h / (double)n);
    printf("%lf", h0);
    for (int i = 2; i < n; ++i)
        printf(" %lf", h0 * sqrt(i));
    return 0;
}

