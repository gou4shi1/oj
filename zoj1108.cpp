/************************************************************************
    > File Name:    zoj1108.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年06月26日 星期日 20时22分29秒
************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

struct data{
    int w,s,f,g,id;
}a[MAXN];

bool operator < (const data &a,const data &b)
{
    return a.w < b.w;
}

int n;

int main()
{
    while (scanf("%d%d",&a[n].w,&a[n].s) == 2)
    {
        a[n].id = n + 1;
        a[n].f = 0;
        a[n].g = -1;
        ++n;
    }
    sort(a,a+n);
    for (int i = 0; i != n; ++i)
    {
        a[i].f = 1;
        for (int j = i - 1; j >= 0; --j)
            if (a[j].w<a[i].w && a[j].s > a[i].s && a[j].f+1 > a[i].f)
            {
                a[i].f = a[j].f + 1;
                a[i].g = j;
            }
    }
    int max(0);
    for (int i = 0; i != n; ++i)
        if (a[i].f > a[max].f)
            max = i;
    printf("%d\n",a[max].f);
    int ans[MAXN];
    int k(max),m(0);
    while ((ans[m++] = a[k].id) && a[k].g != -1)
        k = a[k].g;
    for (int i = m - 1; i >= 0; --i)
        printf("%d\n",ans[i]);
    return 0;
}
