/************************************************************************
* File Name : cf894A.cpp
* Purpose : water
* Creation Date : 2017年11月19日
* Last Modified : 2017年11月19日 星期日 22时00分59秒
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

    char str[666];
    scanf("%s", str);
    int len = strlen(str);
    int c = 0, s = 0, ans = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == 'A')
            s += c;
        if (str[i] == 'Q') {
            ans += s;
            ++c;
        }
    }
    printf("%d\n", ans);

    return 0;
}

