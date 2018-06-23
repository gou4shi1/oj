/************************************************************************
* File Name : cf989A.cpp
* Purpose : water
* Creation Date : 2018年06月11日
* Last Modified : 2018年06月11日 星期一 21时45分47秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define lld I64d
#endif

// vector
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

#define mst(a,x) memset(a,x,sizeof(a))

bool f[233];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    string str;
    cin >> str;
    int len = str.length();
    if (len < 3) {
        puts("No");
        return 0;
    }
    for (int i = 0; i < len - 2; ++i) {
        f['A'] = f['B'] = f['C'] = false;
        f[str[i]] = f[str[i + 1]] = f[str[i + 2]] = true;
        if (f['A'] && f['B'] && f['C']) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");

    return 0;
}
