/************************************************************************
    > File Name:    UVa540.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月27日 星期日 16时37分28秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXT = 1000 + 10;
const int MAXN = 1000000 + 10;

int team[MAXN];

int main()
{
    int t,kase(0);
    while (scanf("%d",&t) == 1 && t)
    {
        printf("Scenario #%d\n",++kase);
        for (int i = 0; i != t; ++i)
        {
            int n,x;
            scanf("%d",&n);
            while (n--)
            {
                scanf("%d",&x);
                team[x] = i;
            }
        }
        queue<int> q,q2[MAXT];
        for (;;)
        {
            int x;
            char cmd[10];
            scanf("%s",cmd);
            if (cmd[0] == 'S')
                break;
            else if (cmd[0] == 'D')
            {
                int t = q.front();
                printf("%d\n",q2[t].front());
                q2[t].pop();
                if (q2[t].empty())
                    q.pop();
            }
            else if (cmd[0] == 'E')
            {
                scanf("%d",&x);
                int t = team[x];
                if (q2[t].empty())
                    q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}
