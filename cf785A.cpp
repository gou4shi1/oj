/************************************************************************
* File Name : cf785A.cpp
* Purpose : water
* Creation Date : 2017年04月22日
* Last Modified : 2017年04月22日 星期六 15时44分56秒
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

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

int main() {
    //freopen("in", "r", stdin);
    int n;
    cin >> n;
    ARRAY a;
    a['T'] = 4;
    a['C'] = 6;
    a['O'] = 8;
    a['D'] = 12;
    a['I'] = 20;
    int ans = 0;
    while (n--) {
        string str;
        cin >> str;
        ans += a[str[0]];
    }
    cout << ans << endl;
    return 0;
}

