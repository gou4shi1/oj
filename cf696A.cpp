/************************************************************************
* File Name : cf696A.cpp
* Purpose : heap
* Creation Date : 2017年04月22日
* Last Modified : 2017年04月22日 星期六 13时45分12秒
* Created By : admin@goushi.me
************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = 0x3f3f3f3f;

typedef int ARRAY[MAXN];
typedef bool FLAG[MAXN];
typedef long long LL;

struct Event{
    LL u, v, w;
}e[MAXN];
int e_size;

LL travel(LL u, LL v) {
    set<LL> s;
    while (u != v) {
        if (u < v)
            swap(u, v);
        s.insert(u);
        u /= 2;
    }

    LL fee = 0;
    for (int i = 1; i <= e_size; ++i) {
        LL u = e[i].u, v = e[i].v, w = e[i].w;
        while (u != v) {
            if (u < v)
                swap(u, v);
            if (s.count(u))
                fee += w;
            u /= 2;
        }
    }

    return fee;
}

int main() {
    //freopen("in", "r", stdin);
    int p;
    scanf("%d", &p);
    for (int i = 1; i <= p; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            ++e_size;
            scanf("%I64d%I64d%I64d", &e[e_size].u, &e[e_size].v, &e[e_size].w);
        } else if (t == 2) {
            LL u, v;
            scanf("%I64d%I64d", &u, &v);
            printf("%I64d\n", travel(u, v));
        }
    }
    return 0;
}

