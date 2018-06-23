/************************************************************************
* File Name : cf766D.cpp
* Purpose : training
* Creation Date : 2017年03月26日
* Last Modified : 2017年03月26日 星期日 14时34分49秒
* Created By : gou4shi1@qq.com
************************************************************************/
#include <iostream>
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

const int MAXN = 100000 + 10;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

ARRAY fa, ha;

void init(int n) {
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}

int find(int u) {
    return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

bool unin(int u, int v) {
    int fau = find(u);
    int fav = find(v);

    if (fau == fav)
        return true;

    if (!ha[fau] && !ha[fav]) {
        fa[fau] = fav;
    } else if (!ha[fau]) {
        fa[fau] = fav;
    } else if (!ha[fav]) {
        fa[fav] = fau;
    } else {
        if (ha[fau] == fav)
            return false;
        fa[ha[fau]] = ha[fav];
        fa[fau] = fav;
    }
    return true;
}

bool hate(int u, int v) {
    int fau = find(u);
    int fav = find(v);

    if (fau == fav)
        return false;

    if (!ha[fau] && !ha[fav]) {
        ha[fau] = fav;
        ha[fav] = fau;
    } else if (!ha[fau]) {
        fa[fau] = ha[fav];
    } else if (!ha[fav]) {
        fa[fav] = ha[fau];
    } else {
        if (ha[fau] == fav)
            return true;
        if (!unin(fau, ha[fav]))
            return false;
        if (!unin(fav, ha[fau]))
            return false;
        fau = find(u);
        fav = find(v);
        ha[fau] = fav;
        ha[fav] = fau;
    }
    return true;
}

int query(int u, int v) {
    int fau = find(u);
    int fav = find(v);

    if (fau == fav)
        return 1;
    if (ha[fau] == fav)
        return 2;
    return 3;
}

int main() {
    //freopen("in", "r", stdin);
    int n, m, q;
    cin >> n >> m >> q;
    init(n);
    map<string, int> mp;
    string name;
    for (int i = 1; i <= n; ++i) {
        cin >> name;
        mp[name] = i;
    }
    int type;
    string name1, name2;
    for (int i = 1; i <= m; ++i) {
        cin >> type >> name1 >> name2;
        if (type == 1)
            puts(unin(mp[name1], mp[name2]) ? "YES" : "NO");
        else
            puts(hate(mp[name1], mp[name2]) ? "YES" : "NO");
    }
    for (int i = 1; i <= q; ++i) {
        cin >> name1 >> name2;
        cout << query(mp[name1], mp[name2]) << endl;
    }
    return 0;
}

