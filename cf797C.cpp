/************************************************************************
* File Name : cf797C.cpp
* Purpose : training
* Creation Date : 2017年04月15日
* Last Modified : 2017年04月16日 星期日 00时27分48秒
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

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

int alpha[233];
char getMinAlpha() {
    for (char i = 'a'; i <= 'z'; ++i)
        if (alpha[i])
            return i;
    return 0;
}

int main() {
    //freopen("in", "r", stdin);
    string str;
    cin >> str;
    int len = str.length();
    for (int i = 0; i < len; ++i)
        ++alpha[str[i]];

    stack<char> s;
    int i = 0;
    while (i < len) {
        if (!s.empty() && s.top() <= getMinAlpha()) {
            cout << s.top();
            s.pop();
        } else if (str[i] != getMinAlpha()) {
            s.push(str[i]);
            --alpha[str[i++]];
        } else {
            cout << str[i];
            --alpha[str[i++]];
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}

