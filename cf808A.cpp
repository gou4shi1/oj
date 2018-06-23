/************************************************************************
* File Name : cf808A.cpp
* Purpose : water
* Creation Date : 2017年05月15日
* Last Modified : 2017年05月15日 星期一 23时34分38秒
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

int main() {
    //freopen("in", "r", stdin);
    int n;
    cin >> n;
    int l = n;
    int m = n / 10;
    int a = 1;
    while (m) {
        a *= 10;
        l = m;
        m /= 10;
    }
    if (n % a == 0)
        cout << a << endl;
    else
        cout << a - (n-l*a) << endl;
    return 0;
}

