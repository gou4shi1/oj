/************************************************************************
    > File Name:    UVa10474.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月24日 星期四 22时26分41秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

int main()
{
    int n,q,x,a[MAXN],kase(0);
    while (scanf("%d%d",&n,&q) == 2 && n)
    {
        printf("CASE# %d:\n",++kase);
        for (int i = 0; i < n; ++i)
            scanf("%d",&a[i]);
        sort(a,a+n);
        while (q--)
        {
            scanf("%d",&x);
            int p = lower_bound(a,a+n,x) - a;
            if (a[p] == x)
                printf("%d found at %d\n",x,p+1);
            else
                printf("%d not found\n",x);
        }
    }
    return 0;
}
