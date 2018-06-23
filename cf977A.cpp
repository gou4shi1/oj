/************************************************************************
* File Name : cf977A.cpp
* Purpose : water  
* Creation Date : 2018年05月06日
* Last Modified : 2018年05月06日 星期日 22时07分47秒
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

    int n, k;
    cin >> n >> k;
    while (k--) {
        if (n % 10)
            --n;
        else
            n /= 10;
    }
    cout << n << endl;

    return 0;
}

