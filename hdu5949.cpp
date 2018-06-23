/************************************************************************
* File Name : hdu5949.cpp
* Purpose : training
* Creation Date : 2016年11月10日
* Last Modified : 2016年11月10日 星期四 19时05分27秒
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
typedef int FLAG[MAXN];
typedef long long LL;

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        char str[MAXN];
        scanf("%s", str);
        int ans = 0;
        for (int i = 0; i != strlen(str); ++i) {
            if (str[i] == 'H')
                ans += 1;
            if (str[i] == 'O')
                ans += 16;
            if (str[i] == 'C')
                ans += 12;
        }
        printf("%d\n", ans);
    }
    return 0;
}

