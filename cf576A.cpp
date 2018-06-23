/************************************************************************
* File Name : cf576A.cpp
* Purpose : math
* Creation Date : 2017年05月20日
* Last Modified : 2017年05月20日 星期六 14时12分15秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

int prime[MAXN];
void getPrime() {
    for (int i = 2; i < MAXN; ++i) {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j]*i < MAXN; ++j) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int k;
ARRAY y;

int main() {
    //freopen("in", "r", stdin);
    int n;
    cin >> n;

    getPrime();

    for (int i = 1; i <= prime[0] && prime[i] <= n; ++i) {
        int t = prime[i];
        while (t <= n) {
            y[++k] = t;
            t *= prime[i];
        }
    }

    cout << k << endl;
    for (int i = 1; i <= k; ++i)
        cout << y[i] << ' ';
    cout << endl;

    return 0;
}

