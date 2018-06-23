/************************************************************************
    > File Name:    poj2104.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年04月29日 星期五 18时18分55秒
************************************************************************/

#include <cstdio>
#include <algorithm>

const int MAXN = 100000 + 10;

int tree[20][MAXN],toleft[20][MAXN],sorted[MAXN];

void build(int l,int r,int dep)
{
    if (l == r)
        return;
    int m = (l + r) >> 1;
    int same = m - l + 1;
    for (int i = l; i <= r; ++i)
        if (tree[dep][i] < sorted[m])
            --same;
    int lpos = l;
    int rpos = m + 1;
    for (int i = l; i <= r; ++i)
    {
        if (i == l)
            toleft[dep][i] = 0;
        else
            toleft[dep][i] = toleft[dep][i - 1];
        if (tree[dep][i] < sorted[m])
        {
            tree[dep + 1][lpos++] = tree[dep][i];
            ++toleft[dep][i];
        }
        else if (tree[dep][i] == sorted[m] && same)
        {
            tree[dep + 1][lpos++] = tree[dep][i];
            ++toleft[dep][i];
            --same;
        }
        else
            tree[dep + 1][rpos++] = tree[dep][i];
    }
    build(l,m,dep + 1);
    build(m + 1,r,dep + 1);
}

int query(int L,int R,int dep,int l,int r,int k)
{
    if (l == r)
        return tree[dep][l];
    int m = (L + R) >> 1,cnt,nl,nr;
    if (l == L)
        cnt = toleft[dep][r];
    else
        cnt = toleft[dep][r] - toleft[dep][l - 1];
    if (cnt >= k)
    {
        if (l == L)
            nl = l;
        else
            nl = L + toleft[dep][l - 1];
        nr = nl + cnt - 1;
        return query(L,m,dep + 1,nl,nr,k);
    }
    nr = r + toleft[dep][R] - toleft[dep][r];
    nl = nr - (r - l + 1 - cnt) + 1;
    return query(m + 1,R,dep + 1,nl,nr,k - cnt);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d",&tree[0][i]);
        sorted[i] = tree[0][i];
    }
    std::sort(sorted+1,sorted+1+n);
    build(1,n,0);
    int a,b,c;
    while (m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",query(1,n,0,a,b,c));
    }
    return 0;
}
