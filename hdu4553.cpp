/************************************************************************
* File Name : hdu4553.cpp
* Purpose : segment tree
* Creation Date : 2017年10月03日
* Last Modified : 2017年10月04日 星期三 17时28分07秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// const
const int MAXN = 200000 + 10;
const int INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
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

//segment tree
#define lr rt << 1
#define rr rt << 1 | 1
#define ls l, m, lr
#define rs m+1, r, rr

int memp[MAXN << 2], lemp[MAXN << 2], remp[MAXN << 2], memp2[MAXN << 2], lemp2[MAXN << 2], remp2[MAXN << 2];

void pushUp(int rt, int l) {
    lemp[rt] = lemp[lr];
    if (lemp[rt] == l-(l>>1))
        lemp[rt] += lemp[rr];
    remp[rt] = remp[rr];
    if (remp[rt] == (l>>1))
        remp[rt] += remp[lr];
    memp[rt] = max(memp[lr], memp[rr]);
    memp[rt] = max(memp[rt], remp[lr]+lemp[rr]);

    lemp2[rt] = lemp2[lr];
    if (lemp2[rt] == l-(l>>1))
        lemp2[rt] += lemp2[rr];
    remp2[rt] = remp2[rr];
    if (remp2[rt] == (l>>1))
        remp2[rt] += remp2[lr];
    memp2[rt] = max(memp2[lr], memp2[rr]);
    memp2[rt] = max(memp2[rt], remp2[lr]+lemp2[rr]);
}

/*
void pushDown(int rt, int l) {
    if (lazy[rt] == 1) {
        lazy[lr] = lazy[rr] = 1;
        memp[lr] = lemp[lr] = remp[lr] = 0;
        memp2[lr] = lemp2[lr] = remp2[lr] = l-(l>>1);
        memp[rr] = lemp[rr] = remp[rr] = 0;
        memp2[rr] = lemp2[rr] = remp2[rr] = (l>>1);
    } else if (lazy[rt] == 2) {
        lazy[lr] = lazy[rr] = 2;
        memp[lr] = lemp[lr] = remp[lr] = 0;
        memp2[lr] = lemp2[lr] = remp2[lr] = 0;
        memp[rr] = lemp[rr] = remp[rr] = 0;
        memp2[rr] = lemp2[rr] = remp2[rr] = 0;
    } else if (lazy[rt] == 3) {
        lazy[lr] = lazy[rr] = 3;
        memp[lr] = lemp[lr] = remp[lr] = l-(l>>1);
        memp2[lr] = lemp2[lr] = remp2[lr] = l-(l>>1);
        memp[rr] = lemp[rr] = remp[rr] = (l>>1);
        memp2[rr] = lemp2[rr] = remp2[rr] = (l>>1);
    }
    lazy[rt] = 0;
}
*/

void pushDown(int rt, int l) {
    if (memp[rt] == l) {
        memp[lr] = lemp[lr] = remp[lr] = l-(l>>1);
        memp[rr] = lemp[rr] = remp[rr] = (l>>1);
    } else if (memp[rt] == 0) {
        memp[lr] = lemp[lr] = remp[lr] = 0;
        memp[rr] = lemp[rr] = remp[rr] = 0;
    }

    if (memp2[rt] == l) {
        memp2[lr] = lemp2[lr] = remp2[lr] = l-(l>>1);
        memp2[rr] = lemp2[rr] = remp2[rr] = (l>>1);
    } else if (memp2[rt] == 0) {
        memp2[lr] = lemp2[lr] = remp2[lr] = 0;
        memp2[rr] = lemp2[rr] = remp2[rr] = 0;
    }
}

void build(int l, int r, int rt) {
    if (l == r) {
        memp[rt] = lemp[rt] = remp[rt] = 1;
        memp2[rt] = lemp2[rt] = remp2[rt] = 1;
        return ;
    }
    int m = (l + r) >> 1;
    build(ls);
    build(rs);
    pushUp(rt, r-l+1);
}

void update1(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        memp[rt] = lemp[rt] = remp[rt] = 0;
        //memp2[rt] = lemp2[rt] = remp2[rt] = r-l+1;
        return ;
    }
    int m = (l + r) >> 1;
    pushDown(rt, r-l+1);
    if (L <= m)
        update1(L, R, ls);
    if (m < R)
        update1(L, R, rs);
    pushUp(rt, r-l+1);
}

void update2(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        memp[rt] = lemp[rt] = remp[rt] = 0;
        memp2[rt] = lemp2[rt] = remp2[rt] = 0;
        return ;
    }
    int m = (l + r) >> 1;
    pushDown(rt, r-l+1);
    if (L <= m)
        update2(L, R, ls);
    if (m < R)
        update2(L, R, rs);
    pushUp(rt, r-l+1);
}

void update3(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        memp[rt] = lemp[rt] = remp[rt] = r-l+1;
        memp2[rt] = lemp2[rt] = remp2[rt] = r-l+1;
        return ;
    }
    int m = (l + r) >> 1;
    pushDown(rt, r-l+1);
    if (L <= m)
        update3(L, R, ls);
    if (m < R)
        update3(L, R, rs);
    pushUp(rt, r-l+1);
}

int query1(int t, int l, int r, int rt) {
    if (t > memp[rt])
        return -1;
    if (l == r)
        return l;
    int m = (l + r) >> 1;
    pushDown(rt, r-l+1);
    if (memp[lr] >= t)
        return query1(t, ls);
    if (remp[lr]+lemp[rr] >= t)
        return m - remp[lr] + 1;
    return query1(t, rs);
}

int query2(int t, int l, int r, int rt) {
    if (t > memp2[rt])
        return -1;
    if (l == r)
        return l;
    int m = (l + r) >> 1;
    pushDown(rt, r-l+1);
    if (memp2[lr] >= t)
        return query2(t, ls);
    if (remp2[lr]+lemp2[rr] >= t)
        return m - remp2[lr] + 1;
    return query2(t, rs);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int Case;
    scanf("%d", &Case);
    for (int Ci = 1; Ci <= Case; ++Ci) {
        printf("Case %d:\n", Ci);
        int T, n;
        scanf("%d%d", &T, &n);
        build(1, T, 1);
        while (n--) {
            char op[23];
            int t;
            scanf("%s%d", op, &t);
            if (op[0] == 'D') {
                int x = query1(t, 1, T, 1);
                if (x == -1)
                    puts("fly with yourself");
                else {
                    update1(x, x+t-1, 1, T, 1);
                    printf("%d,let's fly\n", x);
                }
            } else if (op[0] == 'N') {
                int x = query1(t, 1, T, 1);
                if(x == -1)
                    x = query2(t, 1, T, 1);
                if (x == -1)
                    puts("wait for me");
                else {
                    update2(x, x+t-1, 1, T, 1);
                    printf("%d,don't put my gezi\n", x);
                }
            } else if (op[0] == 'S') {
                int tt;
                scanf("%d", &tt);
                update3(t, tt, 1, T, 1);
                puts("I am the hope of chinese chengxuyuan!!");
            }
        }
    }
    return 0;
}

