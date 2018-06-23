/************************************************************************
    > File Name:    zoj3210.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月25日 星期六 20时47分54秒
************************************************************************/

#include <cstdio>

using namespace std;

const int MAXN = 1000;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        int a[MAXN],b[MAXN];
        scanf("%d",&n);
        for (int i = 0; i != n; ++i)
            scanf("%d",&a[i]);
        for (int i = 0; i != n; ++i)
            scanf("%d",&b[i]);
        bool stack(true),queue(true);
        for (int i = 0; i != n; ++i)
            if (a[i] != b[i])
                queue = false;
        for (int i = 0; i != n; ++i)
            if (a[i] != b[n-i-1])
                stack = false;
        if (queue && stack)
            puts("both");
        else if (queue)
            puts("queue");
        else if (stack)
            puts("stack");
        else 
            puts("neither");
    }
    return 0;
}
