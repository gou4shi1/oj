/************************************************************************
    > File Name:    UVa340.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月07日 星期一 17时48分36秒
************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;

int main()
{
    int n,a[MAXN],b[MAXN];
    int kase = 0;
    while (scanf("%d",&n) == 1 && n)
    {
        printf("Game %d:\n",++kase);
        for (int i = 0; i < n; ++i)
            scanf("%d",&a[i]);
        for (;;)
        {
            int A = 0,B = 0;
            for (int i = 0; i < n; ++i)
            {
                scanf("%d",&b[i]);
                if (a[i] == b[i])
                    ++A;
            }
            if (b[0] == 0)
                break;
            for (int d = 1; d <= 9; ++d)
            {
                int c1 = 0,c2 = 0;
                for (int i = 0; i < n; ++i)
                {
                    if (a[i] == d)
                        ++c1;
                    if (b[i] == d)
                        ++c2;
                }
                if (c1 < c2)
                    B += c1;
                else 
                    B += c2;
            }
            B -= A;
            printf("    (%d,%d)\n",A,B);
        }
    }
    return 0;
}
