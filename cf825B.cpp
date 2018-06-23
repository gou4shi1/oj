/************************************************************************
* File Name : cf825B.cpp
* Purpose : water
* Creation Date : 2017年08月04日
* Last Modified : 2017年08月05日 星期六 00时21分09秒
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
#define LLD %I64d
#else
#define LLD %lld
#endif

// array
typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

char m[666][666];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 666; ++i)
        for (int j = 0; j < 666; ++j)
            m[i][j] = 'O';

    for (int i = 0; i < 10; ++i)
        scanf("%s", m[i]);

    for (int j = 0; j < 10; ++j)
        for (int i = 0; i < 10; ++i)
            m[10 + j][i] = m[i][j];
    for (int ii = 0; ii < 10; ++ii) {
        int i = ii, j = 0, l = 0;
        while (i >= 0) {
            m[20 + ii][l++] = m[i][j];
            --i;
            ++j;
        }
    }
    for (int jj = 0; jj < 10; ++jj) {
        int i = 9, j = jj, l = 0;
        while (j < 10) {
            m[30 + jj][l++] = m[i][j];
            --i;
            ++j;
        }
    }
    for (int ii = 0; ii < 10; ++ii) {
        int i = ii, j = 0, l = 0;
        while (i < 10) {
            m[40 + ii][l++] = m[i][j];
            ++i;
            ++j;
        }
    }
    for (int jj = 0; jj < 10; ++jj) {
        int i = 0, j = jj, l = 0;
        while (j < 10) {
            m[50 + jj][l++] = m[i][j];
            ++i;
            ++j;
        }
    }


    int max_a = 0;

    for (int i = 0; i < 60; ++i) {
        int a0 = 0, a1 = 0;
        bool have_empty = false, inter_empty = false;
        for (int j = 0; j < 10; ++j) {
            if (m[i][j] == 'X') {
                if (!inter_empty)
                    ++a0;
                else
                    ++a1;
                if (have_empty && (a0 + a1) > max_a)
                    max_a = a0 + a1;
            }
            else if (m[i][j] == 'O') {
                a0 = 0;
                a1 = 0;
                have_empty = false;
                inter_empty = false;
            } else {
                have_empty = true;
                if (inter_empty) {
                    a0 = a1;
                    a1 = 0;
                } else {
                    if (a0 > 0)
                        inter_empty = true;
                    if (have_empty && (a0 + a1) > max_a)
                        max_a = a0 + a1;
                }
            }
            //if (a >= 4)
                //printf("%d %d\n", i, j);
        }
    }
    
    puts((max_a >= 4) ? "YES" : "NO");

    return 0;
}

