/************************************************************************
    > File Name:    UVa1368.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年03月12日 星期六 20时37分23秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000 + 10;
const int MAXM = 100;
const int nuc_ascii[] = {65,67,71,84};

char str[MAXN];
int nuc[MAXN][MAXM];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(nuc,0,sizeof(nuc));
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i != n; ++i)
        {
            scanf("%s",str);
            for (int j = 0; j !=m; ++j)
                ++nuc[j][str[j]];
        }
        int nuc_max,nuc_sum = 0;
        for (int i = 0; i !=m; ++i)
        {
            nuc_max = 0;
            for (int j = 0; j != 4; ++j)
            {
                nuc_sum += nuc[i][nuc_ascii[j]];
                if (nuc[i][nuc_ascii[j]] > nuc[i][nuc_ascii[nuc_max]])
                   nuc_max = j;
            }
           printf("%c",nuc_ascii[nuc_max]);
           nuc_sum -= nuc[i][nuc_ascii[nuc_max]];
        }
        printf("\n%d\n",nuc_sum);
    }
    return 0;
}
