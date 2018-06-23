/************************************************************************
* File Name : cf766C.cpp
* Purpose : training
* Creation Date : 2017年03月26日
* Last Modified : 2017年03月26日 星期日 22时06分48秒
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
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    char str[MAXN];
    int alpha[233];
    scanf("%s", str);
    for (int i = 0; i < 26; ++i)
        scanf("%d", &alpha['a' + i]);
    int max_length = 1, alpha_min;
    ARRAY dp1, dp2;
    dp1[0] = 1;
    dp2[0] = 1;
    for (int i = 1; i < n; ++i) {
        alpha_min = alpha[str[i]];
        dp1[i] = 0;
        dp2[i] = i + 1;
        for (int j = i - 1; j >= 0; --j) {
            if (alpha_min < i - j)
                break;
            max_length = max(max_length, i - j);
            dp1[i] = (dp1[i] + dp1[j]) % MOD;
            dp2[i] = min(dp2[i], dp2[j] + 1);

            alpha_min = min(alpha_min, alpha[str[j]]);
        }
        if (alpha_min < i + 1)
            continue;
        max_length = max(max_length, i + 1);
        dp1[i] = (dp1[i] + 1) % MOD;
        dp2[i] = 1;
    }
    printf("%d\n%d\n%d\n", dp1[n - 1], max_length, dp2[n - 1]);
    return 0;
}

