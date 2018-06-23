/************************************************************************
* File Name : cf794C.cpp
* Purpose : water
* Creation Date : 2017年05月13日
* Last Modified : 2017年05月17日 星期三 01时07分51秒
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

const int MAXN = 300000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

char a[MAXN];

int main() {
    //freopen("in", "r", stdin);
    string s, t;
    cin >> s >> t;
    int n = s.length();
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    int sl = 0, sr = (n%2 ? n/2 + 1 : n/2) - 1;
    int tl = 0, tr = n/2 - 1;

    int al = 0, ar = n - 1;
    bool flag = 0;
    for (int i = 1;  i <= n; ++i) {
        if (i % 2) {
            if (tl <= tr && s[sl] >= t[tl])
                flag = true;

            if (flag)
                a[ar--] = s[sr--];
            else
                a[al++] = s[sl++];
        } else {
            if (sl <= sr && s[sl] >= t[tl])
                flag = true;

            if (flag)
                a[ar--] = t[tr--];
            else
                a[al++] = t[tl++];
        }
    }
    a[n] = '\0';
    printf("%s\n", a);

    return 0;
}

