/************************************************************************
* File Name : cf808D.cpp
* Purpose : water
* Creation Date : 2017年05月16日
* Last Modified : 2017年05月16日 星期二 01时23分36秒
* Created By : admin@goushi.me
************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <set>
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

ARRAY a;
LL b[MAXN], c[MAXN];

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum % 2) {
        puts("NO");
        return 0;
    }

    LL half = sum / 2;

    b[1] = 0;
    for (int i = 2; i <= n; ++i)
        b[i] = b[i - 1] + a[i - 1];

    set<LL> s;
    for (int i = n; i >= 1; --i) {
        s.insert(a[i]);
        if (b[i] < half && s.count(half-b[i])) {
            puts("YES");
            return 0;
        }
    }

    c[n] = 0;
    for (int i = n - 1; i >= 1; --i)
        c[i] = c[i + 1] + a[i + 1];

    s.clear();
    for (int i = 1; i <= n; ++i) {
        s.insert(a[i]);
        if (c[i] < half && s.count(half-c[i])) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");
    return 0;
}

