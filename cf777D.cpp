/************************************************************************
* File Name : cf777D.cpp
* Purpose : greedy
* Creation Date : 2017年04月05日
* Last Modified : 2017年04月06日 星期四 01时00分24秒
* Created By : gou4shi1@qq.com
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

const int MAXN = 500000 + 10;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

string a[MAXN];

int main() {
    //freopen("in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = n - 1; i >= 1; --i) {
        int len = min(a[i].length(), a[i + 1].length());
        int j;
        for (j = 0; j <= len; ++j)
            if (a[i][j] != a[i + 1][j])
                break;
        if (a[i][j] < a[i + 1][j])
            continue;
        if (a[i][j] > a[i + 1][j] || a[i].length() > a[i + 1].length())
            a[i] = a[i].substr(0, j);
    }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << endl;
    return 0;
}

