/************************************************************************
* File Name : cf811A.cpp
* Purpose : math
* Creation Date : 2017年05月29日
* Last Modified : 2017年05月29日 星期一 21时36分14秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

int main() {
    //freopen("in", "r", stdin);
    int a, b;
    scanf("%d%d", &a, &b);
    int t = 1;
    while (true) {
        if (a >= t*t && b < t*t + t) {
            puts("Valera");
            return 0;
        }
        if (a < t*t && b >= t*t - t) {
            puts("Vladik");
            return 0;
        }
        ++t;
    }
    return 0;
}

