/************************************************************************
* File Name : cf825D.cpp
* Purpose : greedy
* Creation Date : 2017年08月07日
* Last Modified : 2017年08月07日 星期一 16时13分32秒
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

ARRAY fs, ft;

bool isFull() {
    for (int i = 'a'; i <= 'z'; ++i)
        if (fs[i] < ft[i])
            return false;
    return true;
}
void subFull() {
    for (int i = 'a'; i <= 'z'; ++i)
        fs[i] -= ft[i];
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    string s, t;
    cin >> s >> t;

    int ls = s.length(); 
    for (int i = 0; i < ls; ++i)
        ++fs[s[i]];
    int lt = t.length();
    for (int i = 0; i < lt; ++i)
        ++ft[t[i]];
    while (isFull())
        subFull();
    for (int i = 0; i < ls; ++i)
        if (s[i] == '?') {
            s[i] = 'a';
            for (int j = 'a'; j <= 'z'; ++j)
                if (fs[j] < ft[j]) {
                    s[i] = j;
                    ++fs[j];
                    break;
                }
            while (isFull())
                subFull();
        }
    cout << s;

    return 0;
}

