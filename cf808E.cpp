/************************************************************************
* File Name : cf808E.cpp
* Purpose : dp
* Creation Date : 2017年05月16日
* Last Modified : 2017年05月16日 星期二 23时54分18秒
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

ARRAY w1, w2, w3;
int w1_size, w2_size, w3_size;

struct Node {
    LL c;
    int w1, w2;
}dp[MAXN * 3];

LL a[MAXN];

int main() {
    //freopen("in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int w, c;
        scanf("%d%d", &w, &c);
        if (w == 1)
            w1[++w1_size] = c;
        if (w == 2)
            w2[++w2_size] = c;
        if (w == 3)
            w3[++w3_size] = c;
    }
    sort(w1+1, w1+1 + w1_size, greater<int>());
    sort(w2+1, w2+1 + w2_size, greater<int>());
    sort(w3+1, w3+1 + w3_size, greater<int>());

    for (int i = 0; i <= m - 1; ++i) {
        if (dp[i].w1 < w1_size && dp[i].c + w1[dp[i].w1 + 1] > dp[i + 1].c)
            dp[i + 1] = {dp[i].c + w1[dp[i].w1 + 1], dp[i].w1 + 1, dp[i].w2};
        if (dp[i].w2 < w2_size && dp[i].c + w2[dp[i].w2 + 1] > dp[i + 2].c)
            dp[i + 2] = {dp[i].c + w2[dp[i].w2 + 1], dp[i].w1, dp[i].w2 + 1};
    }

    for (int i = 1; i <= w3_size; ++i)
        a[i] = a[i - 1] + w3[i];

    LL ans = 0;
    for (int i = 0; i <= m; ++i)
        ans = max(ans, dp[i].c + a[min(w3_size, (m-i) / 3)]);

    cout << ans << endl;

    return 0;
}

