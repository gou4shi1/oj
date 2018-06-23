/************************************************************************
    > File Name:    zoj1204.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月10日 星期五 21时56分34秒
************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXM = 50;

int a[MAXM];
bool used[MAXM];
int m;
bool found;

void solve(int sum,int begin,int n)
{
    if (n == 0)
    {
        int exist = -1;
        for (int i = begin; i < m && sum >= a[i]; ++i)
            if (sum == a[i])
            {
                exist = i;
                break;
            }
        if (exist != -1)
        {
            found = true;
            int i,j;
            for (i = 0; i < exist; ++i)
                if (used[i])
                {
                    printf("%d",a[i]);
                    break;
                }
            for (j = i + 1; j < exist; ++j)
                if (used[j])
                    printf("+%d",a[j]);
            printf("=%d\n",sum);
        }
        return;
    }
    for (int i = begin; i < m; ++i)
    {
        if (sum + a[i] > a[m - 1])
            return;
        used[i] = true;
        solve(sum + a[i],i + 1,n - 1);
        used[i] = false;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&m);
        for (int i = 0; i < m; ++i)
            scanf("%d",&a[i]);
        sort(a,a+m);
        found = false;
        memset(used,0,sizeof(used));
        for (int i = 2; i < m; ++i)
            solve(0,0,i);
        if (!found)
            printf("Can't find any equations.\n");
        printf("\n");
    }
    return 0;
}
