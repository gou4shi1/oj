/************************************************************************
    > File Name:    UVa202.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月12日 星期六 21时26分02秒
************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000000;

int exp[MAXN];
int cycle[MAXN];
int n;

int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b) == 2)
    {
        printf("%d/%d = %d.",a,b,a / b);
        a %= b;
        n = 0;
        int len = 0,start = 0;
        while (true)
        {
            a *= 10;
            cycle[n] = a;
            exp[n++] = a / b;
            a %= b;
            for (int i = 0; i != n - 1; ++i)
                if (cycle[i] == cycle[n-1])
                {
                    len = n - 1 - i;
                    start = i;
                    break;
                }
            if (len == 0)
                continue;
            for (int i = 0; i != start; ++i)
                printf("%d",exp[i]);    
            printf("(");
            if (start + len > 50)
            {
                for (int i = start; i != 50; ++i)
                    printf("%d",exp[i]);
                printf("...)\n");
                break;
            }
            for (int i = start; i != start + len; ++i)
                printf("%d",exp[i]);
            printf(")\n");
            break;
        }
        printf("   %d = number of digits in repeating cycle\n\n",len);
    }
    return 0;
}
