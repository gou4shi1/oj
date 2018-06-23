/************************************************************************
* File Name : cf976B.cpp
* Purpose : water
* Creation Date : 2018年05月04日
* Last Modified : 2018年05月04日 星期五 14时03分49秒
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

    int n, m;
    LL k;
    scanf("%d%d%lld", &n, &m, &k);

    int r, c;
    if (k < n) {
        r = 1 + k;
        c = 1;
    } else {
        k -= n;
        r = n - (k / (m - 1));
        if ((k / (m - 1)) % 2) {
            c = m - (k % (m - 1));
        } else {
            c = 2 + (k % (m - 1));
        }
    }
    printf("%d %d\n", r, c);

    return 0;
}

