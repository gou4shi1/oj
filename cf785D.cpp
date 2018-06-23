/************************************************************************
* File Name : cf785D.cpp
* Purpose : combination
* Creation Date : 2017年04月22日
* Last Modified : 2017年04月22日 星期六 22时56分10秒
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

const int MAXN = 200000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

LL pow_mod(LL a, LL n, LL mod) {
    LL ret = 1, temp = a % mod;
    while (n) {
        if (n & 1)
            ret = ret * temp % mod;
        temp = temp * temp % mod;
        n >>= 1;
    }
    return ret;
}

LL inv(LL a, LL mod) {
    return pow_mod(a, mod - 2, mod);
}

LL fac[MAXN], fac_inv[MAXN];

void init(int n) {
    fac[0] = 1;
    fac_inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        fac_inv[i] = inv(fac[i], MOD);
    }
    /*  get all combinations via pretreatment:
     *  
     *  C[0][0] = C[1][0] = C[1][1] = 1;
     *  for (int i = 2; i != MAXN; ++i) {
     *      C[i][0] = C[i][i] = 1;
     *      for (int j = 1; j < i; ++j)
     *          C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
     *  }
    */
}

LL C(int n, int m) {
    if (!m)
        return 1;
    return fac[n] * fac_inv[m] % MOD * fac_inv[n-m] % MOD;
}

ARRAY l, r;

int main() {
    //freopen("in", "r", stdin);
    
    string str;
    cin >> str;
    int len = str.length();
    init(len);
    for (int i = 1; i < len; ++i)
        l[i] = l[i-1] + (str[i-1] == '(' ? 1 : 0);
    for (int i = len - 2; i >= 0; --i)
        r[i] = r[i+1] + (str[i+1] == ')' ? 1 : 0);

    LL ans = 0;
    for (int i = 0; i < len; ++i)
        if (str[i] == '(' && r[i])
            ans = (ans + C(l[i] + r[i], r[i] - 1)) % MOD;
    cout << ans << endl;

    return 0;
}

