/************************************************************************
    > File Name:    UVa1225.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月08日 星期二 23时52分09秒
************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10000;

int a[MAXN][10];

int main()
{
    for (int i = 1; i <= MAXN; ++i)
    {
        int x = i;
        while(x > 0)
        {
            ++a[i][x % 10];
            x /= 10;
        }
        for (int j = 0; j <= 9; ++j)
            a[i][j] += a[i-1][j];
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i <= 8; ++i)
            printf("%d ",a[n][i]);
        printf("%d\n",a[n][9]);
    }
    return 0;
}
