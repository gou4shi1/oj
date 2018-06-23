/************************************************************************
    > File Name:    zoj2615.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月26日 星期日 15时04分31秒
************************************************************************/

#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 20000005;
const int MAXM = 300005;

int son_num[MAXM],son_start[MAXM];
int in[MAXN],out[MAXN];
int n,clock;

void dfs(int root)
{
    in[root] = ++clock;
    if (root < n)
        for (int i = 0; i != son_num[root]; ++i)
            dfs(son_start[root] + i);
    out[root] = ++clock;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int kase = 1; kase <= T; ++kase)
    {
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        scanf("%d",&n);
        for (int i = 0; i != n; ++i)
            scanf("%d",&son_num[i]);
        son_start[0] = 1;
        for (int i = 1; i != n; ++i)
            son_start[i] = son_start[i-1] + son_num[i-1];
        clock = 0;
        dfs(0);
        printf("Case %d:\n",kase);
        int m,a,b;
        scanf("%d",&m);
        while (m--)
        {
            scanf("%d%d",&a,&b);
            puts(in[a]<in[b] && out[a]>out[b] ? "Yes" : "No");
        }
        if (kase != T)
            printf("\n");
    }
    return 0;
}
