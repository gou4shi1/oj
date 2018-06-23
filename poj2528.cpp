/************************************************************************
* File Name : poj2528.cpp
* Purpose : segment tree
* Creation Date : 2017年09月25日
* Last Modified : 2017年09月25日 星期一 22时52分01秒
* Created By : admin@goushi.me
************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// const
const int MAXN = 1000000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000000 + 7;
const double EPS = 1E-8;

// long long
typedef long long LL;
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

// array
typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];

// pair
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

ARRAY lb, rb, num, cov, flag;
int ns, ans;

#define id(x) (lower_bound(num, num+ns, (x))-num)

#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

void pushDown(int rt) {
    if (cov[rt]) {
        cov[lr] = cov[rr] = cov[rt];
        cov[rt] = 0;
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        cov[rt] = c;
        return;
    }
    pushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, ls);
    if (m < R)
        update(L, R, c, rs);
}

void query(int l, int r, int rt) {
    if (cov[rt]) {
        if (!flag[cov[rt]]) {
            flag[cov[rt]] = true;
            ++ans;
        }
        return;
    }
    if (l == r)
        return;
    pushDown(rt);
    int m = (l + r) >> 1;
    query(ls);
    query(rs);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        memset(cov, 0, sizeof(cov));
        int n;
        scanf("%d", &n);
        ns = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &lb[i], &rb[i]);
            num[ns++] = lb[i];
            num[ns++] = rb[i];
        }

        sort(num, num+ns);
        ns = unique(num, num+ns) - num;
        for (int i = ns-1; i > 0; --i)
            if (num[i] > num[i-1] + 1)
                num[ns++] = num[i-1] + 1;
        sort(num, num+ns);

        for (int i = 1; i <= n; ++i)
            update(id(lb[i]), id(rb[i]), i, 0, ns-1, 1);
        ans = 0;
        memset(flag, 0, sizeof(flag));
        query(0, ns-1, 1);
        printf("%d\n", ans);
    }

    return 0;
}

