#include <cstdio>
#include <cstring>
#include <algorithm>

#define lson rt << 1,l,m
#define rson rt << 1 | 1,m + 1,r
#define l_rt (rt << 1)
#define r_rt (rt << 1 | 1)

const int MAXN = 100000 + 10;
typedef int ARRAY1[MAXN];
typedef int ARRAY2[MAXN << 1];
typedef int ARRAY4[MAXN << 2];

ARRAY2 to,next;
ARRAY1 color,head,fa,depth,size,pos,segment,h_son,top;
ARRAY4 lc,rc,num,lazy;

int n,edge_size,pos_size;

void AddEdge(int u,int v)
{
    to[++edge_size] = v;
    next[edge_size] = head[u];
    head[u] = edge_size;
    return;
}

void LHC_DFS1(int u)
{
    size[u] = 1;
    for (int i = head[u]; i; i = next[i])
    {
        int v = to[i];
        if (v == fa[u])
            continue;
        fa[v] = u;
        depth[v] = depth[u] + 1;
        LHC_DFS1(v);
        size[u] += size[v];
        if (size[v] > size[h_son[u]])
            h_son[u] = v;
    }
    return;
}

void LHC_DFS2(int u,int u_top)
{
    pos[u] = ++pos_size;
    segment[pos[u]] = u;
    top[u] = u_top;
    if (!h_son[u])
        return;
    LHC_DFS2(h_son[u],u_top);
    for (int i = head[u]; i; i = next[i])
    {
        int v = to[i];
        if (v == fa[u] || v == h_son[u])
            continue;
        LHC_DFS2(v,v);
    }
    return;
}

void PushUp(int rt)
{
    num[rt] = num[l_rt] + num[r_rt];
    if (rc[l_rt] == lc[r_rt])
        --num[rt];
    lc[rt] = lc[l_rt];
    rc[rt] = rc[r_rt];
   return; 
}

void PushDown(int rt)
{
    if (lazy[rt] == -1)
        return;
    num[l_rt] = num[r_rt] = 1;
    lc[l_rt] = rc[l_rt] = lc[r_rt] = rc[r_rt] = lazy[rt];
    lazy[l_rt] = lazy[r_rt] = lazy[rt];
    lazy[rt] = -1;
}

void build(int rt,int l,int r)
{
    if (l == r)
    {
        lc[rt] = rc[rt] = color[segment[l]];
        num[rt] = 1;   
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
    return;
}

void update(int rt,int l,int r,int L,int R,int col)
{
    if (L <= l && r <= R)
    {
        lc[rt] = rc[rt] = lazy[rt] = col;
        num[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    PushDown(rt);
    if (L <= m)
        update(lson,L,R,col);
    if (R > m)
        update(rson,L,R,col);
    PushUp(rt);
    return;
}

int query_num(int rt,int l,int r,int L,int R)
{
    if (L <= l && r <= R)
        return num[rt];
    int sum(0);
    int m = (l + r) >> 1;
    PushDown(rt);
    if (L <= m)
        sum += query_num(lson,L,R);  
    if (R > m)
        sum += query_num(rson,L,R);
    if (L <= m && R > m && rc[l_rt] == lc[r_rt])
        --sum;
    PushUp(rt);
    return sum;
}

int query_color(int rt,int l,int r,int k)
{
    if (l == r)
        return lc[rt];
    int m = (l + r) >> 1;
    PushDown(rt);
    if (k <= m)
       return query_color(lson,k); 
    else
       return query_color(rson,k); 
    PushUp(rt);
}

void change(int a,int b,int c)
{
    while (top[a] != top[b])
    {
        if (depth[top[a]] < depth[top[b]])
            std::swap(a,b);
        update(1,1,n,pos[top[a]],pos[a],c);
        a = fa[top[a]]; 
    }
    if (depth[a] < depth[b])
        std::swap(a,b);
    update(1,1,n,pos[b],pos[a],c);
    return;
}

int ask(int a,int b)
{
    int a_col(-1),b_col(-1);
    int cnt(0);
    while (top[a] != top[b])
    {
        if (depth[top[a]] > depth[top[b]])
        {
            cnt += query_num(1,1,n,pos[top[a]],pos[a]);
            if (query_color(1,1,n,pos[a]) == a_col)
                --cnt;
            a_col = query_color(1,1,n,pos[top[a]]);
            a = fa[top[a]];
        }
        else
        {
            cnt += query_num(1,1,n,pos[top[b]],pos[b]);
            if (query_color(1,1,n,pos[b]) == b_col)
                --cnt;
            b_col = query_color(1,1,n,pos[top[b]]);
            b = fa[top[b]];
        }
    }
    if (depth[a] < depth[b])
        cnt += query_num(1,1,n,pos[a],pos[b]);
    else
        cnt += query_num(1,1,n,pos[b],pos[a]);
    if (query_color(1,1,n,pos[a]) == a_col)
        --cnt;
    if (query_color(1,1,n,pos[b]) == b_col)
        --cnt;
    return cnt;
}
        
int main()
{
    //freopen("in","r",stdin);
    int m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i)
        scanf("%d",&color[i]);
    int u,v;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d",&u,&v);
        AddEdge(u,v);
        AddEdge(v,u);
    }
    LHC_DFS1(1);
    LHC_DFS2(1,1);
    memset(lazy,-1,sizeof(lazy));
    build(1,1,n);
    char op[10];
    int a,b,c;
    while (m--)
    {
        scanf("%s",op);
        if (op[0] == 'C')
        {
            scanf("%d%d%d",&a,&b,&c);
            change(a,b,c);
        }
        if (op[0] == 'Q')
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",ask(a,b));
        }
    }
    return 0;
}
