/************************************************************************
* File Name : cf989C.cpp
* Purpose : graph construction
* Creation Date : 2018年06月11日
* Last Modified : 2018年06月11日 星期一 23时26分50秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 1000 + 10;
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

char g[N][N];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    --a;
    --b;
    int n = 38, m = 41;

    // B
    int r = 1, dr = 1, c0 = 1;
    for (int i = 0; b > 0 && i < 40; ++i, --b) {
        g[r][c0 + i] = 'B';
        r += dr;
        dr *= -1;
    }

    r = 4, dr = 1;
    for (int i = 0; b > 0 && i < 40; ++i, --b) {
        g[r][c0 + i] = 'B';
        r += dr;
        dr *= -1;
    }

    r = 7, dr = 1;
    for (int i = 0; b > 0 && i < 40; ++i, --b) {
        g[r][c0 + i] = 'B';
        r += dr;
        dr *= -1;
    }

    // C
    r = 10, dr = 1;
    for (int i = 0; c > 0 && i < 40; ++i, --c) {
        g[r][c0 + i] = 'C';
        r += dr;
        dr *= -1;
    }

    r = 13, dr = 1;
    for (int i = 0; c > 0 && i < 40; ++i, --c) {
        g[r][c0 + i] = 'C';
        r += dr;
        dr *= -1;
    }

    r = 16, dr = 1;
    for (int i = 0; c > 0 && i < 40; ++i, --c) {
        g[r][c0 + i] = 'C';
        r += dr;
        dr *= -1;
    }

    // D
    r = 19, dr = 1;
    for (int i = 0; d > 0 && i < 40; ++i, --d) {
        g[r][c0 + i] = 'D';
        r += dr;
        dr *= -1;
    }

    r = 22, dr = 1;
    for (int i = 0; d > 0 && i < 40; ++i, --d) {
        g[r][c0 + i] = 'D';
        r += dr;
        dr *= -1;
    }

    r = 25, dr = 1;
    for (int i = 0; d > 0 && i < 40; ++i, --d) {
        g[r][c0 + i] = 'D';
        r += dr;
        dr *= -1;
    }

    // A
    r = 29, dr = 1;
    for (int i = 0; a > 0 && i < 40; ++i, --a) {
        g[r][c0 + i] = 'A';
        r += dr;
        dr *= -1;
    }

    r = 32, dr = 1;
    for (int i = 0; a > 0 && i < 40; ++i, --a) {
        g[r][c0 + i] = 'A';
        r += dr;
        dr *= -1;
    }

    r = 35, dr = 1;
    for (int i = 0; a > 0 && i < 40; ++i, --a) {
        g[r][c0 + i] = 'A';
        r += dr;
        dr *= -1;
    }
    
    // A
    for (int i = 0; i < 28; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!g[i][j])
                g[i][j] = 'A';
        }
    }

    // B
    for (int i = 28; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!g[i][j])
                g[i][j] = 'B';
        }
    }

    // print
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%c", g[i][j]);
        }
        printf("\n");
    }

    return 0;
}
