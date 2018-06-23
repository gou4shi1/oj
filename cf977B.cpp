/************************************************************************
* File Name : cf977B.cpp
* Purpose : water
* Creation Date : 2018年05月06日
* Last Modified : 2018年05月06日 星期日 22时23分16秒
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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    cin >> n;
    string str;
    cin >> str;
    int len = str.length();
    map<string, int> s;
    for (int i = 0; i < len - 1; ++i) {
        if (s.count(str.substr(i, 2)) == 0)
            s[str.substr(i, 2)] = 1;
        else
            ++ s[str.substr(i, 2)];
    }
    int m = 0;
    string ans;
    for (auto x: s) {
        if (x.se > m) {
            m = x.se;
            ans = x.fi;
        }
    }
    cout << ans << endl;

    return 0;
}

