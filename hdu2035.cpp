/************************************************************************
* File Name : hdu2035.cpp
* Purpose : quick-power-mod & quick-multipy-mod
* Creation Date : 2016年10月21日
* Last Modified : 2016年10月21日 星期五 23时23分42秒
* Created By : gou4shi1@qq.com
************************************************************************/
#include <cstdio>

using namespace std;

const int MOD = 1000;

typedef long long LL;

/**
 * @brief fast multipy with mod
 *
 * @param a
 * @param b
 * @param m
 *
 * @return a*b (mod m)
 */
LL mult_mod(LL a, LL b, LL m) {
    a %= m;
    b %= m;
    LL ret = 0, temp = a;
    //e.g. 3*5 = 3*(101) = 3*(100) + 3*(1)  (binary)
    while (b) {
        if (b & 1) {
            ret += temp;
            if  (ret > m)
                ret -= m; //minus is faster than mod
        }
        temp <<= 1;
        if (temp > m)
            temp -= m;
        b >>= 1;
    }
    return ret;
}

/**
 * @brief fast power with mod
 *
 * @param a
 * @param n
 * @param m
 *
 * @return a^n (mod m)
 */
LL pow_mod(LL a, LL n, LL m) {
    LL ret = 1, temp = a % m;
    //e.g. 3^5 = 3^(101) = 3^(100) * 3^(1)  (binary)
    while (n) {
        if (n & 1)
            ret = mult_mod(ret, temp, m);
        temp = mult_mod(temp, temp, m);
        n >>= 1;
    }
    return ret;
}

int main() {
    //freopen("in", "r", stdin);
    int a, b;
    while (~scanf("%d%d", &a, &b) && !(a==0 && b==0))
        printf("%lld\n", pow_mod(a, b, MOD));
    return 0;
}
