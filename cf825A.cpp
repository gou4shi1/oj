/************************************************************************
* File Name : cf825A.cpp
* Purpose : water
* Creation Date : 2017年08月03日
* Last Modified : 2017年08月03日 星期四 23时29分05秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define LLD %I64d
#else
#define LLD %lld
#endif

// array
typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    cin >> n;
    string str;
    cin >> str;
    int len = str.length();
    int a = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == '1')
            ++a;
        else {
            cout << a;
            a = 0;
        }
    }
    cout << a << endl;

    return 0;
}

