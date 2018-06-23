/************************************************************************
* File Name : hdu5925.cpp
* Purpose : training
* Creation Date : 2016年10月16日
* Last Modified : 2016年10月16日 星期日 18时08分56秒
* Created By : gou4shi1@qq.com
************************************************************************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 500;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

typedef int ARRAY[MAXN];
typedef long long LL;

struct BARRIER {
    int x, y;
} bar[MAXN];

struct HASH {
    LL v, n;
} ha_x[MAXN], ha_y[MAXN];
int ha_x_size, ha_y_size;
bool operator < (HASH l, HASH r) {
    return l.v < r.v;
}
bool operator == (HASH l, HASH r) {
    return l.v == r.v;
}

bool flag[MAXN][MAXN];
LL ans[MAXN * MAXN];
int ans_size;

LL dfs(int x, int y) {
    if (flag[x][y])
        return 0;

    flag[x][y] = true;
    LL ret = ha_x[x].n * ha_y[y].n;
    for (int i = 0; i != 4; ++i)
        ret += dfs(x + dx[i], y + dy[i]);
    return ret;
}

inline void init() {
    ha_x_size = ha_y_size = ans_size = 0;
    for (int i = 0; i != MAXN; ++i)
        for (int j = 0; j != MAXN; ++j)
            flag[i][j] = false;
}

int main() {
    //freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case #%d:\n", kase);

        init();

        int R, C;
        scanf("%d%d", &R, &C);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &bar[i].x, &bar[i].y);
            ha_x[++ha_x_size].v = bar[i].x;
            ha_x[ha_x_size].n = 1;
            ha_y[++ha_y_size].v = bar[i].y;
            ha_y[ha_y_size].n = 1;
        }

        sort(ha_x+1, ha_x+1 + n);
        ha_x[0].v = 0;
        ha_x[++ha_x_size].v = R + 1;
        for (int i = 1; i <= n+1; ++i)
            if (ha_x[i].v - ha_x[i-1].v > 1) {
                ha_x[++ha_x_size].v = ha_x[i].v - 1;
                ha_x[ha_x_size].n = ha_x[i].v - ha_x[i-1].v - 1;
            }
        sort(ha_x+1, ha_x+1 + ha_x_size);
        ha_x_size = unique(ha_x+1, ha_x+1 + ha_x_size) - (ha_x+1);

        sort(ha_y+1, ha_y+1 + n);
        ha_y[0].v = 0;
        ha_y[++ha_y_size].v = C + 1;
        for (int i = 1; i <= n+1; ++i)
            if (ha_y[i].v - ha_y[i-1].v > 1) {
                ha_y[++ha_y_size].v = ha_y[i].v - 1;
                ha_y[ha_y_size].n = ha_y[i].v - ha_y[i-1].v - 1;
            }
        sort(ha_y+1, ha_y+1 + ha_y_size);
        ha_y_size = unique(ha_y+1, ha_y+1 + ha_y_size) - (ha_y+1);

        for (int i = 0; i <= ha_x_size; ++i)
            for (int j = 0; j <= ha_y_size; ++j) {
                if (i == 0 || j == 0 || i == ha_x_size || j == ha_y_size)
                    flag[i][j] = true;
                else
                    for (int k = 1; k <= n; ++k)
                        if (ha_x[i].v == bar[k].x && ha_y[j].v == bar[k].y) {
                            flag[i][j] = true;
                            break;
                        }
            }

        for (int i = 1; i < ha_x_size; ++i)
            for (int j = 1; j < ha_y_size; ++j)
                if (!flag[i][j])
                    ans[++ans_size] = dfs(i, j);

        sort(ans+1, ans+1 + ans_size);
        printf("%d\n", ans_size);
        for (int i = 1; i < ans_size; ++i)
            printf("%lld ", ans[i]);
        printf("%lld\n", ans[ans_size]);
    }
    return 0;
}

