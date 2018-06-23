/************************************************************************
* File Name : cf989B.cpp
* Purpose : water
* Creation Date : 2018年06月11日
* Last Modified : 2018年06月12日 星期二 10时51分34秒
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

char str[N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, p;
    scanf("%d%d", &n, &p);
    scanf("%s", str);
    int len = strlen(str);

    bool ans = false;
    for (int i = 0; i + p - 1 < len; ++i) {
        if (ans || i + p >= len)
            break;
        if (str[i] == '.' && str[i + p] == '.') {
            str[i] = '0';
            str[i + p] = '1';
            ans = true;
        } else if (str[i] == '.' && str[i + p] != '.') {
            str[i] = '0' + (1 - (str[i + p] - '0'));
            ans = true;
        } else if (str[i] != '.' && str[i + p] == '.') {
            str[i + p] = '0' + (1 - (str[i] - '0'));
            ans = true;
        } else if (str[i] != str[i + p]) {
            ans = true;
        } else {
            ans = false;
        }
    }

    if (ans) {
        for (int i = 0; i < len; ++i)
            printf("%c", str[i] == '.' ? '1' : str[i]);
    } else {
        puts("No");
    }

    return 0;
}
