/************************************************************************
* File Name : cf806C.cpp
* Purpose : binary-search
* Creation Date : 2017年05月20日
* Last Modified : 2017年05月21日 星期日 00时10分51秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY p, hp, extra, ended;

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    int mt = 0;
    for (int i = 1; i <= n; ++i) {
        LL a;
        scanf("%I64d", &a);
        LL hb = 1;
        int t = 0;
        while (a > hb) {
            hb *= 2;
            ++t;
        }
        mt = max(mt, t);
        if (a == hb)
            ++p[t];
        else
            ++hp[t - 1];
    }

    LL l = 1, h = p[0] + 1;
    while (l < h) {
        int m = (l + h) / 2;
        int cur = m;
        for (int i = 0; i <= mt; ++i) {
            extra[i] = p[i] - cur;
            if (p[i + 1] < cur) {
                ended[i] = cur - p[i + 1];
                cur = p[i + 1];
            } else
                ended[i] = 0;
        }

        int s = 0, flag = 0;
        for (int i = mt; i >= 0; --i) {
            s += ended[i];
            s -= hp[i];
            s -= extra[i];
            if (s < 0) {
                flag = true;
                break;
            }
        }

        if (flag)
            l = m + 1;
        else
            h = m;
    }
    if (l > p[0]) {
        puts("-1");
        return 0;
    }
    for (int i = l; i <= p[0]; ++i)
        printf("%d ", i);
    printf("\n");

    return 0;
}

