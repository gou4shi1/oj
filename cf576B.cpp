/************************************************************************
* File Name : cf576B.cpp
* Purpose : constructive algorithms
* Creation Date : 2017年05月20日
* Last Modified : 2017年05月20日 星期六 16时51分43秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY p, c[2];
FLAG v;

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);

    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; ++i)
        if (i == p[i])
            c1 = i;
        else if (i == p[p[i]])
            c2 = i;

    if (c1) {
        puts("YES");
        for (int i = 1; i <= n; ++i)
            if (i != c1)
                printf("%d %d\n", c1, i);
    } else if (c2) {
        v[c2] = v[p[c2]] = true;
        for (int i = 1; i <= n; ++i) {
            if (v[i])
                continue;

            //printf("# %d\n", i);
            int cur = i, t = 0;
            while (!v[cur]) {
                //printf("# %d\n", t);
                c[t][++c[t][0]] = cur;
                v[cur] = true;
                cur = p[cur];
                t ^= 1;
            }
            if (t || cur != i) {
                puts("NO");
                return 0;
            }
        }

        puts("YES");
        printf("%d %d\n", c2, p[c2]);
        for (int i = 1; i <= c[0][0]; ++i)
            printf("%d %d\n", c2, c[0][i]);
        for (int i = 1; i <= c[1][0]; ++i)
            printf("%d %d\n", p[c2], c[1][i]);
    } else
        puts("NO");

    return 0;
}

