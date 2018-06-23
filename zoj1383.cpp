/************************************************************************
    > File Name:    zoj1383.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月26日 星期日 23时15分22秒
************************************************************************/

#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x;
        scanf("%d",&x);
        bool first(true);
        for (int i = 0; x > 0; ++i)
        {
            if (x&1)
            {
                if (!first)
                    printf(" ");
                printf("%d",i);
                first = false;
            }
            x >>= 1;
        }
        printf("\n");
    }
    return 0;
}
