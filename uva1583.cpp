/************************************************************************
    > File Name:    UVa1583.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月07日 星期一 19时29分25秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100000 + 5;

int ans[MAXN];

int main()
{
    int T,n;
    memset(ans,0,sizeof(ans));
    for (int m = 1; m < MAXN; ++m)
    {
        int x = m,y = m;
        while (x > 0)
        {
            y += x % 10;
            x /=10;
        }
        if (ans[y] == 0)
            ans[y] = m;
    }
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
