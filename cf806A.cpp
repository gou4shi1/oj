/************************************************************************
* File Name : cf806A.cpp
* Purpose : math
* Creation Date : 2017年05月18日
* Last Modified : 2017年05月18日 星期四 23时51分19秒
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
    int T;
    cin >> T;
    while (T--) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if (p == 0)
            cout << (x ? -1 : 0) << endl;
        else if (p == q)
            cout << (x==y ? 0 : -1) << endl;
        else
            cout << (LL)q * max((x+p-1)/p, (y-x+q-p-1)/(q-p)) - y << endl;
    }

    return 0;
}

