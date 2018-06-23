/************************************************************************
* File Name : cf853B.cpp
* Purpose : greedy
* Creation Date : 2017年09月14日
* Last Modified : 2017年09月17日 星期日 21时55分37秒
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

pair<int, pair<int, int>> to[MAXN], fr[MAXN];
int ts, fs;
FLAG flag;
ARRAY mct, mcf;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        int d, f, t, c;
        scanf("%d%d%d%d", &d, &f, &t, &c);
        if (t == 0)
            to[ts++] = mp(d, mp(f, c));
        else
            fr[fs++] = mp(d, mp(t, c));
    }
    
    sort(to, to+ts);
    sort(fr, fr+fs);

    memset(mct, 0x3f, sizeof(mct));
    int t = 0, ti = -1;
    while (t < n) {
        ++ti;
        if (ti >= ts) {
            puts("-1");
            return 0;
        }
        if (!flag[to[ti].se.fi]) {
            ++t;
            flag[to[ti].se.fi] = true;
        }
        mct[to[ti].se.fi] = min(mct[to[ti].se.fi], to[ti].se.se);   
    }

    LL tc = 0;
    for (int i = 1; i <= n; ++i)
        tc += mct[i];

    int fi = 0;
    while (fi < fs && fr[fi].fi <= to[ti].fi + k)
        fi++;
    if (fi >= fs) {
        puts("-1");
        return 0;
    }

    multiset<int> s[MAXN];
    memset(mcf, 0x3f, sizeof(mcf));
    for (int i = fi; i < fs; ++i) {
        mcf[fr[i].se.fi] = min(mcf[fr[i].se.fi], fr[i].se.se);
        s[fr[i].se.fi].insert(fr[i].se.se);
    }
    for (int i = 1; i <= n; ++i)
        if (s[i].empty()) {
            puts("-1");
            return 0;
        }

    for (int i = 1; i <= n; ++i)
        tc += mcf[i];

    LL ans = tc;
    while (++ti < ts) {
        if (to[ti].se.se < mct[to[ti].se.fi]) {
            tc -= mct[to[ti].se.fi] - to[ti].se.se;
            mct[to[ti].se.fi] = to[ti].se.se;
        }
        while (fi < fs && fr[fi].fi <= to[ti].fi + k) {
            s[fr[fi].se.fi].erase(fr[fi].se.se);
            if (s[fr[fi].se.fi].empty()) {
                printf(LLD "\n", ans);
                return 0;
            }
            int nm = *s[fr[fi].se.fi].begin();
            tc += nm - mcf[fr[fi].se.fi];
            mcf[fr[fi].se.fi] = nm;

            ++fi;
        }
        if (fi >= fs) {
            printf(LLD "\n", ans);
            return 0;
        }
        ans = min(ans, tc);
    }
    printf(LLD "\n", ans);

    return 0;
}

