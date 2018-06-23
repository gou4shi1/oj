/************************************************************************
* File Name : cf962B.cpp
* Purpose : water 
* Creation Date : 2018年05月05日
* Last Modified : 2018年05月05日 星期六 10时36分12秒
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

int a[233];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d%d%d%*c", &n, &a[0], &a[1]);
    bool begin = true;
    int last = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        char ch;
        scanf("%c", &ch);
        if (ch == '*') {
            begin = true;
        } else {
            if (begin) {
                begin = false;
                if (a[0] < a[1])
                    swap(a[0], a[1]);
                if (a[0] > 0) {
                    ++ans;
                    --a[0];
                    last = 0;
                } else {
                    break;
                }
            } else {
                if (a[1 - last] > 0) {
                    ++ans;
                    --a[1 - last];
                    last = 1 - last;
                } else {
                    begin = true;
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}

