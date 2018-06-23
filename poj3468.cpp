/************************************************************************
    > File Name:    poj3468.cpp
    > Author:       gou4shi1
    > Mail:         gou4shi1@qq.com
    > Created Time: 2016年04月01日 星期五 14时40分39秒
************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const int MAXN = 100000 + 10;

int a[MAXN];

struct node
{
    int le,re;
    LL sum;
    int lazy;
    node *lc,*rc;
    node(int LE = 0,int RE = 0,LL SUM = 0,int LAZY = 0,node *LC = NULL,node *RC = NULL)
        : le(LE),re(RE),sum(SUM),lazy(LAZY),lc(LC),rc(RC) {}
};

void push_up(node *rt)
{
    rt->sum = rt->lc->sum + rt->rc->sum;
    return;
}

void push_down(node *rt)
{
    if (!rt->lazy)
        return;
    int len = rt->re - rt->le + 1;
    LL right_len =len >> 1;
    LL left_len =len - right_len;
    rt->lc->sum += rt->lazy * left_len;
    rt->rc->sum += rt->lazy * right_len;
    rt->lc->lazy += rt->lazy;
    rt->rc->lazy += rt->lazy;
    rt->lazy = 0;
}

void build(node *rt)
{
    if (rt->le == rt->re)
    {
        rt->sum = a[rt->le];
        return;
    }
    int mid = (rt->le + rt->re) >> 1;
    rt->lc = new node(rt->le,mid);
    rt->rc = new node(mid+1,rt->re);
    build(rt->lc);
    build(rt->rc);
    push_up(rt);
} 

LL query(node *rt,int left,int right)
{
    if (rt->le > right || rt->re < left)
        return 0;
    if (left <= rt->le && rt->re <= right)
        return rt->sum;
    push_down(rt);
    return query(rt->lc,left,right) + query(rt->rc,left,right); 
}

void update(node *rt,int left,int right,int c)
{
    if (left <= rt->le && rt->re <= right)
    {
        rt->sum += (LL)c * (rt->re - rt->le + 1);
        rt->lazy += c;
        return ;
    }
    push_down(rt);
    int mid = (rt->le + rt->re) >> 1;
    if (left <= mid)
        update(rt->lc,left,right,c);
    if (right > mid)
        update(rt->rc,left,right,c);
    push_up(rt);
}

int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    for (int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);
    node *root = new node(1,n);
    build(root);
    char str[5];
    int a,b,c;
    while (Q--)
    {
        scanf("%s",str);
        if (str[0] == 'Q')
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(root,a,b));
        }
        if (str[0] == 'C')
        {
            scanf("%d%d%d",&a,&b,&c);
            update(root,a,b,c);
        }
    }
    return 0;
}
