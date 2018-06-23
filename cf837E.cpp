/************************************************************************
* File Name : cf837E.cpp
* Purpose : number theory
* Creation Date : 2017年08月14日
* Last Modified : 2017年08月15日 星期二 01时11分20秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100000 + 10;
const int MAXP = 1000000;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

// array
typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

//Miller-Rabin Test

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

bool check(LL a, LL n, LL x, LL t) {
    LL ret = pow_mod(a, x, n);
    LL last = ret;
    for (int i = 1; i <= t; ++i) {
        ret = mult_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n-1)
            return true;
        last = ret;
    }
    return (ret != 1);
}

bool Miller_Rabin(LL n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (!(n & 1))
        return false;

    const static int S = 10;
    LL x = n - 1, t = 0;
    while (!(x & 1)) {
        x >>= 1;
        ++t;
    }

    for (int i = 0; i != S; ++i) {
        LL a = rand()%(n-1) + 1;
        if (check(a, n, x, t))
            return false;
    }
    return true;
}

//pollard-rho

LL gcd(LL a, LL b) {
    LL t;
    while (b) {
        t = a;
        a = b;
        b = t % b;
    }
    return a >= 0 ? a : -a;
}

LL pollard_rho(LL x, LL c) {
    LL i = 1, k = 2;
    LL x0 = rand()%(x-1) + 1;
    LL y = x0;

    while (true) {
        ++i;
        x0 = (mult_mod(x0, x0, x) + c) % x;
        LL d = gcd(y - x0, x);
        if (d != 1 && d != x)
            return d;
        if (y == x0)
            return x;
        if (i == k) {
            y = x0;
            k += k;
        }
    }
}

const int MAX_FACTOR_NUM = 100;
LL factor[MAX_FACTOR_NUM];
int factor_num;

void findFactor(LL n) {
    if (n == 1)
        return;
    if (Miller_Rabin(n)) {
        factor[factor_num++] = n;
        return;
    }

    const static int C = 107;
    int c = C;
    LL p = n;
    while (p >= n)
        p = pollard_rho(p, c--);
    findFactor(p);
    findFactor(n / p);
}

void factorDecomposition(LL n) {
    factor_num = 0;
    findFactor(n);
}

LL f(LL x, LL y) {
    LL ret = 0;

    while (y) {
        LL g = gcd(x, y);
        x /= g;
        y /= g;
        factorDecomposition(x);
        LL m = y;
        for (int i = 0; i < factor_num; ++i)
                m = min(m, y - (y/factor[i]*factor[i]));
        y -= m;
        ret += m;
    }

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    LL x, y;
    scanf(LLD LLD, &x, &y);

    printf(LLD, f(x, y));

    return 0;
}

