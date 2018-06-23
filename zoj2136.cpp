/************************************************************************
    > File Name:    zoj2136.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月26日 星期日 21时14分20秒
************************************************************************/

#include <cstdio>

using namespace std;

const int MAXN = 1005;

int a[MAXN],f[MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i != n; ++i)
            scanf("%d",&a[i]);
        for (int i = 0; i != n; ++i)
        {
            f[i] = 1;
            for (int j = i - 1; j >= 0; --j)
                if (a[j] < a[i] && f[j]+1 > f[i])
                    f[i] = f[j] + 1;
        }
        int max(0);
        for (int i = 0; i != n; ++i)
            if (f[i] > max)
                max = f[i];
        printf("%d\n",max);
        if (!T)
            printf("\n");
    }
    return 0;
}
