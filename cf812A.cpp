/************************************************************************
* File Name : cf812A.cpp
* Purpose : water
* Creation Date : 2017年06月01日
* Last Modified : 2017年06月03日 星期六 16时16分47秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

bool c[4], p[4];

int main() {
    //freopen("in", "r", stdin);
    int a[4][3] = {{3,2,1}, {0,3,2}, {1,0,3}, {2,1,0}};
    for (int i = 0; i < 4; ++i) {
        int t;
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &t);
            c[a[i][j]] |= t;
            c[i] |= t;
        }
        scanf("%d", &t);
        p[i] |= t;
    }
    bool f = 0;
    for (int i = 0; i < 4; ++i)
        f |= c[i] && p[i];
    puts(f ? "YES" : "NO");
    return 0;
}

