/************************************************************************
* File Name : cf789E.cpp
* Purpose : training
* Creation Date : 2017年04月01日
* Last Modified : 2017年04月02日 星期日 01时41分00秒
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

ARRAY a;
int a_size;
FLAG val, vis;

struct Node{
    int val, step;
    Node(int v, int s) : val(v), step(s) {}
};
queue<Node> q;

int main() {
    //freopen("in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
        int ai;
        scanf("%d", &ai);
        if (val[ai])
            continue;
        val[ai] = true;
        a[a_size++] = ai - n;
    }

    int ans(-1);
    bool flag(false);
    q.push(Node(0, 0));
    while (!q.empty()) {
        Node t = q.front();
        q.pop();

        if (flag && !t.val) {
            ans = t.step;
            break;
        }
        flag = true;

        for (int i = 0; i < a_size; ++i) {
            Node p = Node(t.val + a[i], t.step + 1);
            if (p.val > 2000 || p.val < 0 || vis[p.val])
                continue;
            vis[p.val] = true;
            q.push(p);
        }
    }
    printf("%d\n", ans);
    return 0;
}

