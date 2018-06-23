/************************************************************************
* File Name : cf808C.cpp
* Purpose : greedy
* Creation Date : 2017年05月15日
* Last Modified : 2017年05月16日 星期二 00时50分14秒
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

struct Cup {
    int id, v, l;
}cup[MAXN];

bool operator < (const Cup &a, const Cup &b) {
    return a.v < b.v;
}

ARRAY ans;

int main() {
    //freopen("in", "r", stdin);
    int n, w;
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; ++i) {
        int vol;
        scanf("%d", &vol);
        cup[i] = {i, vol, 0};
    }

    sort(cup+1, cup+1 + n);

    for (int i = 1; i <= n; ++i) {
        cup[i].l = cup[i].v % 2 ? cup[i].v/2 + 1 : cup[i].v / 2;
        if (i > 1 && cup[i].v > cup[i-1].v && cup[i].l < cup[i-1].l)
            cup[i].l = cup[i-1].l;
        w -= cup[i].l;
        if (w < 0) {
            puts("-1");
            return 0;
        }
        ans[cup[i].id] = cup[i].l;
    }

    for (int i = n; i >= 1; --i) {
        if (!w)
            break;

        int a = min(w, cup[i].v-cup[i].l);
        w -= a;
        ans[cup[i].id] += a;
    }

    for(int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}

