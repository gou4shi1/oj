/************************************************************************
* File Name : cf965B.cpp
* Purpose : water
* Creation Date : 2018年04月26日
* Last Modified : 2018年04月27日 星期五 00时06分52秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const
const int N = 100 + 10;
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

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int n, k;
int a[N][N][5];
bool f[N][N];

int compute(int *a) {
    int ret = 0;
    for (int dir = 0; dir < 2; ++dir) {
        if (a[dir] + a[dir + 2] - 1 >= k) {
            ret += max(min(min(min(a[dir], a[dir + 2]), k), a[dir] + a[dir + 2] - k), 0);
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%*c", &n, &k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char ch;
            scanf("%c", &ch);
            if (ch == '.') {
                f[i][j] = true;
                for (int dir = 0; dir < 4; dir += 3) {
                    a[i][j][dir] = a[i + dr[dir]][j + dc[dir]][dir] + 1;
                }
            } else {
                for (int dir = 0; dir < 4; ++dir) 
                    a[i][j][dir] = 0;
            }
        }
        scanf("%*c");
    }

    for (int i = n; i > 0; --i)
        for (int j = n; j > 0; --j) {
            if (f[i][j]) {
                for (int dir = 1; dir < 3; ++dir) 
                    a[i][j][dir] = a[i + dr[dir]][j + dc[dir]][dir] + 1;
            }
        }

    int ans = 0, ii = 1, jj = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            //if (i == 13 && j == 8) {
            //    printf("# %d # %d %d %d %d\n", compute(a[i][j]), a[i][j][0], a[i][j][1], a[i][j][2], a[i][j][3]);
            //}
            if (compute(a[i][j]) > ans) {
                ans = compute(a[i][j]);
                ii = i;
                jj = j;
            }
        }

    printf("%d %d\n", ii, jj);

    return 0;
}

