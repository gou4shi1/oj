/************************************************************************
* File Name : cf977F.cpp
* Purpose : dp
* Creation Date : 2018年05月06日
* Last Modified : 2018年05月06日 星期日 23时07分48秒
* Created By : admin@goushi.me
************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
  
int a[N], ans[N], len;  
  
int main()  {  
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d",&n);  
    for(int i = 1; i <= n; ++i)  
        scanf("%d", &a[i]);  

    map<int, int> m;
    int ma = 0, mi = 0;
    for(int i = 1; i <= n; ++i){  
        if (m.count(a[i]) == 0) {
            m[a[i]] = 1;
        }
        if (m.count(a[i] - 1) != 0) {
            int t = m[a[i] - 1] + 1;
            if (t > m[a[i]]) {
                m[a[i]] = t;
            }
        }
        int t = m[a[i]];
        if (t > ma) {
            ma = t;
            mi = i;
        }
    }

    printf("%d\n", ma);
    ans[0] = mi;
    len = 1;
    int t = a[mi] - 1;
    --ma;
    for (int i = mi - 1; i >= 1; --i) {
        if (ma == 0)
            break;
        if (a[i] == t) {
            ans[len++] = i;
            --t;
            --ma;
        }
    }
    for (int i = len - 1; i >= 0; --i) {
        printf("%d ", ans[i]);
    }
    return 0;  
}
