/************************************************************************
    > File Name:    zoj2734.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月10日 星期五 23时15分47秒
************************************************************************/

#include <cstdio>


using namespace std;

const int MAXM = 20;

int val[MAXM],num[MAXM];
int m;

int solve(int begin,int goal)
{
    if (goal < 0)
        return 0;
    if (goal == 0)
        return 1;
    int ways(0);
    for (int i = begin; i != m; ++i)
        for (int j = 1; j <= num[i]; ++j)
        {
            if (goal - val[i]*j < 0)
                break;
            ways += solve(i + 1,goal - val[i]*j);
        }
    return ways;
}

int main()
{
    int n;
    while (scanf("%d",&n) == 1)
    {
        scanf("%d",&m);
        for (int i = 0; i != m; ++i)
            scanf("%d%d",&val[i],&num[i]);
        printf("%d\n\n",solve(0,n));
    }
    return 0;
}
