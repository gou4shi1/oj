/************************************************************************
* File Name : hdu5922.cpp
* Purpose : training
* Creation Date : 2016年10月15日
* Last Modified : 2016年10月15日 星期六 15时17分18秒
* Created By : gou4shi1@qq.com
************************************************************************/
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
typedef long long LL;

int main() {
    //freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %lld\n", kase, (LL)(2+n)*(n-1)/2);
    }
    return 0;
}

