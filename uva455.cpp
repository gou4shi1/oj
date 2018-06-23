/************************************************************************
    > File Name:    UVa455.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月09日 星期三 12时55分48秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100; 

int main()
{
    int T;
    scanf("%d",&T);
    char str[MAXN];
    while (T--)
    {
        scanf("%s",str);
        int len = strlen(str);
        int k;
        for (k = 1; k <= len; ++k)
        {
           bool flag = true;
           for (int i = 0; i != len; ++i)
               if (str[i] != str[(i+k) % len])
               {
                   flag = false;
                   break;
               }
           if (flag)
               break;
        }
        printf("%d\n",k);
        if (T > 0)
            printf("\n");
    }
    return 0;
}
